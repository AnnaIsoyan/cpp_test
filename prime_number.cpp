#include <iostream>
#include <cmath>

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

int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    if (isPrime(num)) {
        std::cout << num << " is a prime number.\n";
    } else {
        std::cout << num << " is not a prime number.\n";
    }

    return 0;
}
