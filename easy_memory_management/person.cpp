#include "person.hpp"
#include <iostream>

using std::cout;
using std::string;

Person::Person(string first, string last, int arbitrary)
    : firstname(first), lastname(last), arbitraryNumber(arbitrary)
{
}

string Person::getName() const
{
    return firstname + " " + lastname;
}

void Person::addResource()
{
    pResource.reset();
    pResource = std::make_shared<Resource>("Resource for " + getName());
}
