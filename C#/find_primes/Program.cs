using System;
using System.Collections.Generic;
using System.Diagnostics;

public class Program
{
    public static bool IsPrime(int num)
    {
        if (num <= 1) return false;
        for (int i = 2; i * i <= num; ++i)
        {
            if (num % i == 0) return false;
        }
        return true;
    }

    public static int FindPrimes(int start, int end)
    {
        int count = 0;
        for (int num = start; num <= end; ++num)
        {
            if (IsPrime(num))
            {
                count++;
            }
        }
        return count;
    }

    public static void Main()
    {
        int start = 0;
        int end = 10000000;

        // Find primes and measure execution time
        Stopwatch stopwatch = new Stopwatch();
        stopwatch.Start();
        int primes_count = FindPrimes(start, end);
        stopwatch.Stop();

        double executionTime = stopwatch.Elapsed.TotalSeconds;
        Console.WriteLine("Execution time: " + executionTime + " seconds");
        Console.WriteLine("Total prime numbers found: " + primes_count);
    }
}
