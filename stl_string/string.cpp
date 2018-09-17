#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>

#define ASSERT assert

using std::cout;
using std::string;

auto trim(string const &s) -> string
{
    auto front = std::find_if_not(begin(s), end(s), isspace);
    // Here we use reverse iterators, so `back` is a reverse iterator pointing to
    // the *last* whitespace character.
    auto back = std::find_if_not(std::rbegin(s), std::rend(s), isspace);
    // Turn `back` into a regular iterator.
    return string{front, back.base()};
}

int main()
{
    auto s = string{};

    s = std::basic_string<char>{};

    // basic string of wide characters
    auto ws = std::wstring{};

    ws = std::basic_string<wchar_t>{};

    static_assert(sizeof(string::value_type) == 1, "1 byte");
    static_assert(sizeof(std::wstring::value_type) == 4, "2 bytes");

    s = string{"cluck"};

    cout << s << "\n";

    s.clear();
    ASSERT(s.empty());
    cout << s << "\n";

    // Grab a substring of a string
    s = string{"That hen clucked!"};
    s = string(s, 5, 3);

    ASSERT(s == "hen");
    cout << "string(s, 5, 3): " << s << "\n";

    // iterate through string
    for (auto c : s)
    {
        cout << c << " ";
    }
    cout << "\n";

    auto hen = string{"Matilda"};
    auto pasture = string{"Tomatoes"};
    auto id = hen + "@" + pasture;

    cout << "id: " << id << "\n";

    auto pos = id.find('@');
    cout << "Position of '@' - pos: " << pos << "\n";

    // Grab a substring with `substr`
    auto domain = id.substr(pos);
    ASSERT(domain == "@Tomatoes");
    cout << "id.subs(pos): " << domain << "\n";

    auto trimmed = trim(" \t Matilda the hen \r\n ");
    ASSERT(trimmed == "Matilda the hen");
    cout << "trimmed: '" << trimmed << "'\n";
}