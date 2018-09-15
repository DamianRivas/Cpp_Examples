#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    map<string, string> spanishDictionary{
        {"casa", "home"},
        {"gato", "cat"},
        {"mesa", "table"}};

    auto [pos, success] = spanishDictionary.insert({"silla", "chair"});
    if (success)
    {
        cout << " Insertion OK.\n\n";
    }

    for (const auto &[spanish, english] : spanishDictionary)
    {
        cout << ' ' << spanish << ": " << english << '\n';
    }
}