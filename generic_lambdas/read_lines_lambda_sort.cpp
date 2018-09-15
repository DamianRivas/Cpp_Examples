#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream file{"data.txt"};

    vector<string> lines{};
    string line{};
    while (getline(file, line))
    {
        lines.push_back(line);
    }

    sort(begin(lines), end(lines),
         [](auto const &a, auto const &b) {
             return a.length() < b.length();
         });

    for (auto const &s : lines)
    {
        cout << s << "\n";
    }
}
