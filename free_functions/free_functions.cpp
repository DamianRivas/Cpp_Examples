#include <iostream>
using std::cin;
using std::cout;

#include "utility.hpp"

int main()
{
    std::ios::sync_with_stdio(false);
    int x;
    cout << "Enter a number:\n";

    cin >> x;

    if (isPrime(x))
        cout << x << " is prime\n";
    else
        cout << x << " is not prime\n";

    if (is2MorePrime(x))
        cout << x << " + 2 is prime\n";
    else
        cout << x << " + 2 is not prime\n";

    return 0;
}
