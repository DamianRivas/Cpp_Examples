#include "./person.hpp"
#include <string>

using std::string;

int main()
{
    {
        Person Damian("Damian", "Rivas", 345);
        Damian.addResource();
        string s1 = Damian.getResourceName();
        Damian.addResource();
    }

    return 0;
}
