#include "./person.hpp"
#include "./tweeter.hpp"
#include <iostream>

using std::cout;
using std::endl;

#include <memory>
using std::make_shared;
using std::shared_ptr;

int Dummy(Person p) { return p.getNumber(); }
int DummyCRef(Person const &p) { return p.getNumber(); }

int main()
{
    std::ios::sync_with_stdio(false);

    Person Damian("Damian", "Rivas", 456);
    Person &rDamian = Damian;
    Person *pDamian = &Damian;

    Tweeter DamianRivas("Damian", "Rivas", 567, "@dapperdamian");
    Person *pDamianRivas = &DamianRivas;
    Person &rpDamianRivas = DamianRivas;
    Tweeter &rtDamianRivas = DamianRivas;

    cout << rDamian.getName() << "\n";
    cout << pDamian->getName() << "\n";
    cout << DamianRivas.getName() << "\n";
    cout << rpDamianRivas.getName() << "\n"; // Will only print the twitter handle if getName is marked as virtual
    cout << rtDamianRivas.getName() << "\n";
    cout << pDamianRivas->getName() << "\n"; // Will only print the twitter handle if getName is marked as virtual

    // Person *Someone = new Tweeter("Someone", "Else", 567, "@someone");
    // cout << Someone->getName() << "\n";
    // delete Someone;

    shared_ptr<Person> spDamian = make_shared<Tweeter>("Third", "Name", 678, "@handle");
    cout << spDamian->getName() << "\n";

    // DamianRivas = Damian;

    Damian = DamianRivas;
    cout << Damian.getName() << "\n";

    int x;
    cout << Dummy(Damian) << "\n";
    cout << Dummy(DamianRivas) << "\n"; // What happens here? :) (slicing)
    // What if Dummy takes a Person by const reference?

    cout << DummyCRef(DamianRivas) << "\n";

    return 0;
}
