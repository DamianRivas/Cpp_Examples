#include <iostream>
#include <string>

using std::cout;
using std::string;

template <class T>
T max(T const &t1, T const &t2)
{
    return t1 < t2 ? t2 : t1;
}

int main()
{
    auto x = 5;

    cout << "Max of 5 and 0 is: " << max(x, 0) << "\n";

    string hello = "hello";
    string world = "world";

    // cout << "Max of \"hello\" and \"world\" is: " << max(hello, world) << "\n";

    cout << hello += " everyone" << "\n";

    return 0;
}