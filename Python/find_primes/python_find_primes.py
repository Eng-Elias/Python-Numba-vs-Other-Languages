import time

def is_prime(num):
    if num <= 1:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

def find_primes(start, end):
    count = 0
    for num in range(start, end + 1):
        if is_prime(num):
            count += 1
    return count

def main():
    start = 0
    end = 10000000

    # Find primes and measure execution time
    start_time = time.time()
    primes_count = find_primes(start, end)
    end_time = time.time()

    execution_time = end_time - start_time
    print("Execution time:", execution_time, "seconds")
    print("Total prime numbers found:", primes_count)

main()
