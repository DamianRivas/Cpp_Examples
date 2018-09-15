#include "person.hpp"
#include <iostream>

using std::cout;
using std::string;

Person::Person(string first, string last, int arbitrary)
    : firstname(first), lastname(last), arbitraryNumber(arbitrary), pResource(nullptr)
{
}

Person::Person() : arbitraryNumber(0)
{
}

Person::~Person()
{
    delete pResource;
}

string Person::getName() const
{
    return firstname + " " + lastname;
}

void Person::addResource()
{
    pResource = new Resource("Resource for " + getName());
}

Person::Person(Person const &p)
{
    pResource = new Resource(p.pResource->getName());
}

Person &Person::operator=(const Person &p)
{
    delete pResource;
    pResource = new Resource(p.pResource->getName());
    return *this;
}
