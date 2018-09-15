#include <iostream>

using std::cin;
using std::cout;

// This function runs at compile time thanks to the constexpr keyword
constexpr int Fibonacci(int n)
{
    switch (n)
    {
    case 0:
        return 0;
    case 1:
        return 1;
    default:
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
}

int main()
{
    // static_assert is executed at compile time.
    static_assert(Fibonacci(10) == 55, "Unexpected Fibonacci number.");
    return 0;
}