#include <iostream>

using std::cin;
using std::cout;

int Fibonacci(int n)
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
    cout << "Index? ";
    int i{};
    cin >> i;

    cout << " F_" << i << " = " << Fibonacci(i) << "\n";
    return 0;
}