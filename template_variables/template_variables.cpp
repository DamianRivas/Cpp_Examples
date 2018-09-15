#include <iostream>

using std::cout;

template <typename T>
constexpr T maxValue = T(1000);

template <>
constexpr double maxValue<double> = 2000;

template <>
constexpr char maxValue<char> = 'Z';

int main()
{
    cout << " maxValue<int>    : " << maxValue<int> << "\n";
    cout << " maxValue<double> : " << maxValue<double> << "\n";
    cout << " maxValue<char>   : " << maxValue<char> << "\n";
    return 0;
}