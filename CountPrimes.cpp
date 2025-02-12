#include <iostream>
#include <vector>
#include <cmath>

int countPrimes(int n)
{
    if (n <= 1) return 0;
    std::vector<bool> isPrime(n, true);
    isPrime[0] = isPrime[1] = false;
    int primes{n - 2};
    for (int i = 2; i < ceil(sqrt(n)); ++i)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j < n; j += i)
            {
                primes -= isPrime[j];
                isPrime[j] = false;
            }
        }
    }
    return primes;
}

int main()
{
    std::cout << "Should be 4: " << countPrimes(10) << std::endl;
    std::cout << "Should be 0: " << countPrimes(0) << std::endl;
    std::cout << "Should be 0: " << countPrimes(1) << std::endl;
    std::cout << "Should be 5: " << countPrimes(13) << std::endl;
}