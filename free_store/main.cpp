#include "./resource.hpp"
#include <string>

using std::string;

int main()
{
    { // Create a new local scope
        Resource localResource("local");
        string localString = localResource.getName();
    } // End of local scope, destructors run for localString and localResource

    Resource *pResource = new Resource("Created with new");
    string newString = pResource->getName();
    int j = 3;
    Resource *p2 = pResource; // This only makes a copy of the pointer, not the resource it points to. Now we have two pointers pointing to the same block of memory.
    string string2 = p2->getName();

    delete pResource;
    // pResource = nullptr;
    // Bad things happen here because `delete` deletes the pointer AND it frees up the memory that it was pointing to. But assigning pResource to nullptr elimniates that risk.
    string2 = p2->getName();
    delete p2;
    // string string3 = pResource->getName();

    return 0;
}
