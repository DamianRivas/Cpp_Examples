#include <iostream>
#include <string>
#include "./person.hpp"
#include "./accum.hpp"

using std::cout;
using std::endl;
using std::string;

int main()
{
    std::ios::sync_with_stdio(false);

    Accum<int> integers(0);
    integers += 3;
    integers += 7;
    cout << integers.getTotal() << "\n";

    // It's not necessary to include the type (<string>)
    Accum<string> strings("");
    strings += "hello";
    strings += " world";
    cout << strings.getTotal() << "\n";

    // Templates give helpful error messages nowadays
    // Uncomment the following and check out the error message:
    // integers += "testing";

    // Person start("", "", 0);
    Accum<Person> people(0);
    Person p1("Damian", "Rivas", 123);
    Person p2("Someone", "Else", 456);
    people += p1;
    people += p2;
    cout << people.getTotal() << "\n";

    return 0;
}