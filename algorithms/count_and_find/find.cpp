#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<int> v{2, 4, 6, 6, 1, 3, -2, 0, 11, 2, 3, 2, 4, 4, 2, 4};
    string s{"Hello I am a sentence"};

    // Find the first 0 in the collection
    auto result = find(begin(v), end(v), 0);
    int weLookedFor = *result;

    cout << "We found the `0`, here it is: " << weLookedFor << "\n";

    // Fine the first 2 after that zero
    result = find(result, end(v), 2);
    if (result != end(v))
    {
        weLookedFor = *result;
    }

    cout << "We should have found the 2 before the end, here it is: " << weLookedFor << "\n";

    // Fine the first letter a
    auto letter = find(begin(s), end(s), 'a');
    char a = *letter;

    cout << "We should have found the letter `a`, here it is: " << a << "\n";

    // Find first odd value
    result = find_if(begin(v), end(v), [](auto el) { return el % 2 != 0; });
    weLookedFor = *result;
    cout << "The first odd value is: " << weLookedFor << "\n";

    // Find the first even value (find_if_not)
    result = find_if_not(begin(v), end(v), [](auto el) { return el % 2 != 0; });
    weLookedFor = *result;
    cout << "The first even value is: " << weLookedFor << "\n";

    // The the first prime number
    vector<int> primes{1, 2, 3, 5, 7, 11, 13};
    result = find_first_of(begin(v), end(v), begin(primes), end(primes));
    weLookedFor = *result;
    cout << "The first prime is: " << weLookedFor << "\n";

    // Find the first subsequence of {2, 4}
    vector<int> subsequence{2, 4};
    result = search(begin(v), end(v), begin(subsequence), end(subsequence));
    weLookedFor = *result;
    cout << "Did we find it: " << weLookedFor << "\n";
    ++result;
    ++result;
    int six = *result;
    cout << "2 after result should be 6: " << six << "\n";

    string am = "am";
    letter = search(begin(s), end(s), begin(am), end(am));
    a = *letter;

    result = find_end(begin(v), end(v), begin(subsequence), end(subsequence));
    ++result;
    ++result;
    if (result != end(v))
    {
        weLookedFor = *result;
        cout << "2 after find_end({2, 4}): " << weLookedFor << "\n";
    }

    // Find the number of consecutive matches
    // Returns an iterator (pointer) to the first element in the result
    result = search_n(begin(v), end(v), 2, 4);

    // Search the entire collection for any adjacent pairs
    result = adjacent_find(begin(v), end(v));
    six = *result;
    cout << "First pair: " << six << "\n";
    ++result;
    six = *result;
    cout << "Second pair: " << six << "\n";
}