#include <regex>
#include <cassert>
#include <iostream>

#define ASSERT assert

using namespace std;

int main()
{
    auto s = string{"Call 877-808-2321 to reach Amelia the hen!"};
    auto r = regex{R"((\d{3})-(\d{3})-(\d{4}))"};

    auto m = smatch{};
    // The above initialization for m is a shorter version of this:
    // m = match_results<string::const_iterator>{};

    ASSERT(m.empty());
    // regex_search returns true if a match is found, false otherwise.
    // results are insreted into `m`
    ASSERT(regex_search(s, m, r));
    ASSERT(!m.empty());

    // Results of regex_search:
    // The first element in the sequence is the overall match.
    // Subsequent elements identify submatches.
    // Each submatch is a pair of iterators defining the range of characters
    // for each match.
    for (auto &sub : m)
    {
        auto str = sub.str();
        cout << "result: " << str << "\n";
    }

    auto output = m.format(R"($`<a href="link...">$1 $2 $3</a>$')");

    cout << "output: " << output << "\n";
}