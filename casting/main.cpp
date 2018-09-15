#include "./person.hpp"
#include "./tweeter.hpp"
#include <iostream>
using std::cin;
using std::cout;
#include "./resource.hpp"

int main()
{
    std::ios::sync_with_stdio(false);

    Tweeter t("Damian", "Rivas", 123, "@dapperdam");
    Person *p = &t;
    // Tweeter *pt = (Tweeter *)p; // C-style cast. Don't do this. Might shoot yourself in the foot.
    Tweeter *pt = static_cast<Tweeter *>(p);
    cout << pt->getName() << "\n";

    // Static casts are safer. Unlike C-style casts, they spot potential errors at compile time and then won't build.
    // int i = 3;
    // Tweeter *pi = static_cast<Tweeter *>(i);

    Resource r("local");
    Tweeter *pt2;
    cout << "Use Resource or Tweeter?\n";
    std::string answer;
    cin >> answer;
    if (answer == "r")
    {
        // pt2 = dynamic_cast<Tweeter *>(&r);
    }
    else
    {
        pt2 = dynamic_cast<Tweeter *>(p);
    }

    if (pt2)
    {
        cout << pt2->getName() << "\n";
    }
    else
    {
        cout << "pointer can't be cast to tweeter\n";
    }

    return 0;
}
