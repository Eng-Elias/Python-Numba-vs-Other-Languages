function isPrime(num) {
  if (num <= 1) return false;
  for (let i = 2; i * i <= num; ++i) {
    if (num % i === 0) return false;
  }
  return true;
}

function findPrimes(start, end) {
  let count = 0;
  for (let num = start; num <= end; ++num) {
    if (isPrime(num)) {
      count++;
    }
  }
  return count;
}

function main() {
  const start = 0;
  const end = 10000000;

  // Find primes and measure execution time
  const startTime = new Date();
  const primes_count = findPrimes(start, end);
  const endTime = new Date();

  const executionTime = (endTime - startTime) / 1000;
  console.log("Execution time:", executionTime, "seconds");
  console.log("Total prime numbers found:", primes_count);
}

main();
