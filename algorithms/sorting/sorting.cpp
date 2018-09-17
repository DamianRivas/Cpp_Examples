#include <vector>
#include <algorithm>
#include <cmath>
#include <random>
#include <iostream>
#include "./employee.hpp"

using namespace std;

int main()
{
    vector<int> v{4, 1, 0, 1, -2, 3, 7, -6, 2, 0, 0, -9, 9};
    auto v2 = v;

    sort(begin(v2), end(v2));
    cout << "Normally sorted: [ ";
    for (auto i : v2)
    {
        cout << i << " ";
    }
    cout << "]\n";

    sort(begin(v2), end(v2), [](int el1, int el2) { return el1 > el2; });
    cout << "Sorted by el1 > el2: [ ";
    for (auto i : v2)
    {
        cout << i << " ";
    }
    cout << "]\n";

    sort(begin(v2), end(v2), [](int el1, int el2) { return abs(el1) > abs(el2); });
    cout << "Sorted by abs(el1) > abs(el2): [ ";
    for (auto i : v2)
    {
        cout << i << " ";
    }
    cout << "]\n";

    vector<Employee> staff{
        {"Damian", "Rivas", 1000},
        {"Obvious", "Artificial", 2000},
        {"Fake", "Name", 1000},
        {"Alan", "Turing", 2000},
        {"Bjarne", "Stroustrup", 5000},
        {"Linus", "Torvalds", 5000},
        {"Leon", "Gray", 10000}};

    // sort(begin(staff), end(staff)); // only works if operator< defined for Employee

    sort(begin(staff), end(staff), [](Employee e1, Employee e2) { return e1.get_salary() < e2.get_salary(); });
    cout << "Staff is now sorted by salaries: [ ";
    for (auto s : staff)
    {
        cout << s.get_salary() << " ";
    }
    cout << "]\n";

    sort(begin(staff), end(staff), [](Employee e1, Employee e2) { return e1.get_sorting_name() < e2.get_sorting_name(); });
    cout << "Staff is now sorted by name: [ | ";
    for (auto s : staff)
    {
        cout << s.get_sorting_name() << " | ";
    }
    cout << "]\n";

    // stable_sort keeps the original sorted order (by name) of employees with the same salary.
    stable_sort(begin(staff), end(staff), [](Employee e1, Employee e2) { return e1.get_salary() < e2.get_salary(); });
    cout << "Stable sorting by salary after normal sorting by name: [\n  ";
    for (auto e : staff)
    {
        cout << e.get_sorting_name() << " | " << e.get_salary();
        if ((--end(staff))->get_sorting_name() != e.get_sorting_name())
        {
            cout << ",\n  ";
        }
    }
    cout << "\n]\n\n";
}