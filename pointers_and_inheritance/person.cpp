#include "person.hpp"
#include <iostream>

using std::cout;
using std::string;

Person::Person(string first, string last, int arbitrary)
    : firstname(first), lastname(last), arbitraryNumber(arbitrary)
{
}

Person::~Person()
{
}

string Person::getName() const
{
    return firstname + " " + lastname;
}
