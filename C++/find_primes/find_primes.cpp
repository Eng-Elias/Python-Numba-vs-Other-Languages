#include <iostream>
#include <vector>
#include <ctime>

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

int find_primes(int start, int end)
{
    int count = 0;
    for (int num = start; num <= end; ++num)
    {
        if (is_prime(num))
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int start = 0;
    int end = 10000000;
    std::vector<int> primes;

    // Find primes and measure execution time
    clock_t start_time = clock();
    int primes_count = find_primes(start, end);
    clock_t end_time = clock();

    double execution_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
    std::cout << "Execution time: " << execution_time << " seconds" << std::endl;
    std::cout << "Total prime numbers found: " << primes.size() << std::endl;

    return 0;
}
