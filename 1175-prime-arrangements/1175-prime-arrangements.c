#include <stdbool.h>

int numPrimeArrangements(int n) {
    const long long MOD = 1000000007;
    
    bool isPrime[101];

    // Assume all numbers are prime initially
    for (int i = 0; i <= n; i++) {
        isPrime[i] = true;
    }

    isPrime[0] = false;
    isPrime[1] = false;

    // Sieve of Eratosthenes
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // Count prime numbers
    int primeCount = 0;

    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primeCount++;
        }
    }

    // Calculate primeCount!
    long long primeFactorial = 1;

    for (int i = 2; i <= primeCount; i++) {
        primeFactorial = (primeFactorial * i) % MOD;
    }

    // Calculate (n - primeCount)!
    long long nonPrimeFactorial = 1;

    for (int i = 2; i <= n - primeCount; i++) {
        nonPrimeFactorial = (nonPrimeFactorial * i) % MOD;
    }

    // Final answer
    return (primeFactorial * nonPrimeFactorial) % MOD;
}