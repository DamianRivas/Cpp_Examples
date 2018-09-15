#include <iostream>
#include <string>
#include <type_traits>

using namespace std;

template <typename T>
auto length(T const &value)
{
    // if (is_integral<T>::value) // THIS WON'T COMPILE
    if constexpr (is_integral<T>::value) // This compiles because it's evaluated at compile-time so the compiler will ignore the else statement
    {
        // The length of an integer number is the number itself
        return value;
    }
    else
    {
        return value.length();
    }
}

int main()
{
    int n{64};
    string s{"Connie"};

    cout << " n = " << n << "; length(n) = " << length(n) << '\n';
    cout << " s = " << s << "; length(s) = " << length(s) << '\n';
}
