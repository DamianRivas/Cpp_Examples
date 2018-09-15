#include <iostream>
#include "utility.hpp"
using std::cout;

bool isPrime(int x)
{
    bool prime = true;

    for (int i = 2; i <= x / i; i++)
    {
        int factor = x / i;
        if (factor * i == x)
        {
            cout << "factor found: " << factor << "\n";
            prime = false;
            break;
        }
    }
    return prime;
}

bool is2MorePrime(int x)
{
    x += 2;
    return isPrime(x);
}
