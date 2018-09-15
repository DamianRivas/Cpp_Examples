#include <iostream>
#include "./person.hpp"

using std::cout;

int main()
{
    std::ios::sync_with_stdio(false);

    // REFERENCES

    int a = 3;
    cout << "a is " << a << "\n";
    int &rA = a;
    rA = 5;
    cout << "a is " << a << "\n";

    Person Damian("Damian", "Rivas", 234);
    Person &rDamian = Damian;
    rDamian.setNumber(345);
    cout << "rDamian: " << rDamian.getName() << " " << rDamian.getNumber() << "\n";

    // POINTERS

    int *pA = &a;
    *pA = 4;
    cout << "a is " << a << "\n";

    int b = 100;
    pA = &b; // pA now points to the address of b
    ++(*pA); // SO when we increment the contents of pA we increment b
    cout << "a " << a << ", *pA " << *pA << "\n";

    Person *pDamian = &Damian;
    (*pDamian).setNumber(235); // No one does this
    cout << "*pDamian num: " << (*pDamian).getNumber() << "\n";
    pDamian->setNumber(236); // do this!!!
    cout << "pDamian num: " << pDamian->getNumber() << "\n";

    // int *aPointer; // DONT DO THIS. Assign it to nullptr instead!
    int *aPointer = nullptr;
    if (aPointer != nullptr)
    {
        *aPointer = 3;
        cout << "*aPointer: " << *aPointer << "\n";
    }

    return 0;
}