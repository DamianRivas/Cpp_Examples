#include "tweeter.hpp"
#include <iostream>

Tweeter::Tweeter(
    std::string first,
    std::string last,
    int arbitrary,
    std::string handle)
    : Person(first, last, arbitrary), twitterHandle(handle)
{
}

Tweeter::~Tweeter()
{
}

std::string Tweeter::getName() const
{
    return Person::getName() + " " + twitterHandle;
}
