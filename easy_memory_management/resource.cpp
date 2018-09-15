#include "./resource.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

Resource::Resource(string n) : name(n)
{
    cout << "constructing " << name << "\n";
}

Resource::~Resource(void)
{
    cout << "destructing " << name << "\n";
}
