#include <iostream>
#include <vector>
#include <ctime>
#include <thread> // Include the thread header
#include <mutex>  // Include the mutex header

bool is_prime(int num)
{
    if (num <= 1)
        return false;
    for (int i = 2; i * i <= num; ++i)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

void find_primes(int start, int end, int &count, std::mutex &mtx)
{
    int local_count = 0;
    for (int num = start; num <= end; ++num)
    {
        if (is_prime(num))
        {
            local_count++;
        }
    }
    std::lock_guard<std::mutex> lock(mtx);
    count += local_count;
}

int main()
{
    int start = 0;
    int end = 10000000;
    int total_primes = 0;
    std::mutex mtx; // Declare the mutex

    // Determine the number of threads
    unsigned int num_threads = std::thread::hardware_concurrency();
    std::vector<std::thread> threads;
    int range_per_thread = (end - start + 1) / num_threads;

    // Measure execution time
    clock_t start_time = clock();

    for (unsigned int i = 0; i < num_threads; ++i)
    {
        int thread_start = start + i * range_per_thread;
        int thread_end = (i == num_threads - 1) ? end : (thread_start + range_per_thread - 1);
        threads.emplace_back(find_primes, thread_start, thread_end, std::ref(total_primes), std::ref(mtx));
    }

    for (auto &th : threads)
    {
        th.join();
    }

    clock_t end_time = clock();

    double execution_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
    std::cout << "Execution time: " << execution_time << " seconds" << std::endl;
    std::cout << "Total prime numbers found: " << total_primes << std::endl;
    getchar();

    return 0;
}
