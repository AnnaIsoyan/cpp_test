#include <iostream>
#include "factors.h" 

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

// run - clang++ main.cpp factors.cpp  -o main -lgtest -lgtest_main