#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Enter two words separated by a space: " << endl;
    string word1, word2;
    cin >> word1 >> word2;

    int word1Length = word1.length();
    int word2Length = word2.length();

    cout << endl
         << word1 << " has a length of " << word1Length << endl;
    cout << word2 << " has a length of " << word2Length << endl;

    if (word1Length > word2Length)
    {
        cout << word1 << " is larger than " << word2 << endl;
    }
    else if (word1Length < word2Length)
    {
        cout << word2 << " is larger than " << word1 << endl;
    }
    else
    {
        cout << "They are both the same length" << endl;
    }

    return 0;
}
