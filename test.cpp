#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

std::string disemvowel(std::string const &str)
{
    string disemvoweled = str;
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    vector<char>::iterator itr;
    int i = 0;

    while (i != disemvoweled.end() - disemvoweled.begin())
    {
        itr = find(vowels.begin(), vowels.end(), disemvoweled[i]);
        if (itr != vowels.end())
        {
            disemvoweled.erase(i, 1);
            continue;
        }
        ++i;
    }

    return disemvoweled;
}

int main()
{
    string message = "This website is for losers LOL!";
    string edited_message = disemvowel(message);

    cout << edited_message << "\n";

    return 0;
}