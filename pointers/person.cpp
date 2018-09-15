#include "person.hpp"
#include <iostream>

using std::cout;
using std::string;

Person::Person(string first, string last, int arbitrary)
    : firstname(first), lastname(last), arbitraryNumber(arbitrary)
{
}

Person::Person() : arbitraryNumber(0)
{
}

Person::~Person()
{
}

string Person::getName() const
{
    return firstname + " " + lastname;
}

bool Person::operator<(Person const &p) const
{
    return arbitraryNumber < p.arbitraryNumber;
}

bool Person::operator<(int i) const
{
    return arbitraryNumber < i;
}

bool operator<(int i, Person const &p)
{
    return i < p.arbitraryNumber;
}
