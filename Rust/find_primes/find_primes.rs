use std::time::Instant;

fn is_prime(num: i32) -> bool {
    if num <= 1 {
        return false;
    }
    for i in 2..=((num as f64).sqrt() as i32) {
        if num % i == 0 {
            return false;
        }
    }
    true
}

fn find_primes(start: i32, end: i32) -> i32 {
    let mut count = 0;
    for num in start..=end {
        if is_prime(num) {
            count += 1;
        }
    }
    count
}

fn main() {
    let start = 0;
    let end = 10000000;

    // Find primes and measure execution time
    let start_time = Instant::now();
    let primes_count = find_primes(start, end);
    let end_time = Instant::now();

    let execution_time = end_time.duration_since(start_time).as_secs_f64();
    println!("Execution time: {} seconds", execution_time);
    println!("Total prime numbers found: {}", primes_count);
}
