#include <iostream>
#include <cmath>

int result[100];
int resultIndex = 0;

bool isPrime(int n) {
    if (n <= 1) return false;      
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    int limit = static_cast<int>(std::sqrt(n));
    for (int i = 3; i <= limit; i += 2) { // check only odd divisors
        if (n % i == 0) return false;
    }
    return true;
}

void addFactor(int factor)
{
    result[resultIndex] = factor;
    resultIndex++;
    result[resultIndex] = 0; //zero-terminate the array
}

int getNextPrime(int start)
{
    for (int i = start + 1;  ; ++i)
    {
        if (isPrime(i))
        {
            return i;
        }
    }
}

int* getFators(int n)
{
    int nextPrime = 0;

    while (n > 1)
    {
        nextPrime = getNextPrime(nextPrime);
        while (n % nextPrime == 0) {
            addFactor(nextPrime);
            n = n / nextPrime;
        }
    }
    return result;
}

int main()
{
    int n = 0;
    std::cout << "Enter a number: ";
    std::cin >> n;

    int* factors = getFactors(n);

    if (nullptr == factors)
    {
        std::cerr << "Error computing factors!" << std::endl;
        return 1; // on error we never return 0
    }

    std::cout << "Factors of " << n << " are: " << std::endl;

    for (int i = 0; factors[i] != 0; ++i)
    {
        std::cout << factors[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

// illegal instruction - cpu n chi haskanum
// segmentation fault - 