#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print(const string &message, const vector<string> &v)
{
    cout << ' ' << message << ": ";
    for (auto const &s : v)
    {
        cout << s << ' ';
    }
    cout << '\n';
}

int main()
{
    vector<string> names{"C64", "Damian", "Rivas", "Waldo", "Deckard"};
    print("Before", names);

    // it is scoped inside the if statement
    if (const auto it = find(begin(names), end(names), "Waldo");
        it != end(names))
    {
        *it = "***";
    }

    if (const auto it = find(begin(names), end(names), "C64");
        it != end(names))
    {
        *it = "**";
    }

    print("After", names);
}
