#include <algorithm>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int main()
{
    vector<int> nums{2, 7, 1, 6, 2, -2, 4, 0};
    int const target = 2;
    int twos{}, odds{};

    twos = count(nums.begin(), nums.end(), target); //=> 2
    // or... (safer choice)
    twos = count(begin(nums), end(nums), target); //=> 2

    odds = count_if(begin(nums), end(nums),
                    [](auto el) { return el % 2 != 0; }); //=> 2

    map<int, int> month_lengths{{1, 31}, {2, 28}, {3, 31}, {4, 30}, {5, 31}, {6, 30}, {7, 31}, {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31}};
    int long_months = count_if(begin(month_lengths), end(month_lengths), [](auto el) { return el.second == 31; }); //=> 7

    cout << "There are " << long_months << " long months in a year\n";

    // Are all, any, or none of the values odd? Use the STL algorithms!
    bool allof{}, anyof{}, noneof{};

    allof = all_of(begin(nums), end(nums), [](auto el) { return el % 2 != 0; });
    noneof = none_of(begin(nums), end(nums), [](auto el) { return el % 2 != 0; });
    anyof = any_of(begin(nums), end(nums), [](auto el) { return el % 2 != 0; });
}