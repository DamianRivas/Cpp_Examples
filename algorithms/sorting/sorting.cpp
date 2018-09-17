#include <vector>
#include <algorithm>
#include <cmath>
#include <random>
#include <iostream>

using namespace std;

int main()
{
    vector<int> v{4, 1, 0, 1, -2, 3, 7, -6, 2, 0, 0, -9, 9};
    auto v2 = v;

    sort(begin(v2), end(v2));
    cout << "Normally sorted: [";
    for (auto i : v2)
    {
        cout << i << " ";
    }
    cout << "]\n";

    sort(begin(v2), end(v2), [](int el1, int el2) { return el1 > el2; });
    cout << "Sorted by el1 > el2: [";
    for (auto i : v2)
    {
        cout << i << " ";
    }
    cout << "]\n";

    sort(begin(v2), end(v2), [](int el1, int el2) { return abs(el1) > abs(el2); });
    cout << "Sorted by abs(el1) > abs(el2): [";
    for (auto i : v2)
    {
        cout << i << " ";
    }
    cout << "]\n";
}