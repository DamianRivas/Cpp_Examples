#include "./precompiled.hpp"
#include <cassert>
#include <iostream>

#define ASSERT assert

// Can place static_assert outside of a function
static_assert(sizeof(float) == 4, "we don't float that way!");

auto main() -> int
{
    // assert(4 == 5);

    // Run-time
    ASSERT(4 == 5);

    // Compile-time
    static_assert(sizeof(double) == 4, "Problem with sizeof(double)!");

    std::cout << "success!\n";
}
