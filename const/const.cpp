#include <iostream>
#include "./person.hpp"

using std::cout;

int DoubleIt(int const &num)
{
    return num * 2;
}

int main()
{
    std::ios::sync_with_stdio(false);

    int i = 3;

    int const ci = 3;
    i = 4;
    // ci = 4;

    int &ri = i;
    ri = 5;

    int const &cri = i;
    // cri = 6;

    // int &ncri = ci;

    int j = 10;
    int DoubleJ = DoubleIt(j);
    int DoubleTen = DoubleIt(10);

    Person Damian("Damian", "Rivas", 234);
    Damian.setNumber(235);
    Person const cDamian = Damian;
    // cDamian.setNumber(890);
    int DamianNumber = cDamian.getNumber();

    int *pI = &i;
    // int *pII = &pI;
    // pI = &Damian;

    int const *pcI = pI; // pointer to a const
    // *pcI = 4;
    pcI = &j;
    j = *pcI;

    int *const cpI = pI;
    *cpI = 4;
    // cpI = &j;

    int const *const crazy = pI; // const pointer to a const value
    // *crazy = 4;
    // crazy = &j;
    j = *crazy;

    return 0;
}
