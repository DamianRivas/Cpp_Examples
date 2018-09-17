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

    //// Stable Sort ////
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

    ////////////////// is_sorted ///////////////////

    auto sorted = is_sorted(begin(v2), end(v2)); // According to operator<
    cout << "Is v2 sorted? " << (sorted ? "yes" : "no") << "\n";
    sorted = is_sorted(begin(v2), end(v2), [](int e1, int e2) { return abs(e1) > abs(e2); });
    cout << "Is v2 sorted now? " << (sorted ? "yes" : "no") << "\n";

    //////////// Max/Min and Binary Search //////////////

    int high = *(max_element(begin(v), end(v)));
    int low = *(min_element(begin(v), end(v)));
    cout << "Max: " << high << "\nMin: " << low << "\n";

    sort(begin(v2), end(v2));
    low = *(begin(v2));
    high = *(--end(v2));
    cout << "After sorting...\n";
    cout << "Max: " << high << "\nMin: " << low << "\n";

    int positive = *upper_bound(begin(v2), end(v2), 0); // Binary search
    cout << "First positive: " << positive << "\n";

    //// Randomization ////

    random_device randomdevice;
    mt19937 generator(randomdevice());

    shuffle(begin(v2), end(v2), generator);
    cout << "After shuffling: [ ";
    for (auto i : v2)
    {
        cout << i << " ";
    }
    cout << " ]\n\n";

    //// Partial Sorting ////

    // First and last arguments are where the elements you plan to sort will be
    // drawn from
    // Middle parameter indicates where the non-sorted sequence begins
    partial_sort(begin(v2), find(begin(v2), end(v2), 4), end(v2));
    cout << "Partially sorted until the first occurence of `4`...\n[ ";
    for (auto i : v2)
    {
        cout << i << " ";
    }
    cout << " ]\n";

    int breakpoint = *is_sorted_until(begin(v2), end(v2));
    cout << "Now the array is in order until: " << breakpoint << "\n";

    // Now lets copy the first three elements of v, in sorted order, to v3
    vector<int> v3(3);
    partial_sort_copy(begin(v), end(v), begin(v3), end(v3));
    cout << "The first three sorted elements of v: [ ";
    for (auto i : v3)
    {
        cout << i << " ";
    }
    cout << " ]\n\n";

    //// Nth Element ////
    v2 = {1, 5, 4, 2, 9, 7, 3, 8, 2};
    int i = *(begin(v2) + 4);
    cout << "Collection Before: [ ";
    for (auto i : v2)
    {
        cout << i << " ";
    }
    cout << " ]\n";
    cout << "Middle element: " << i << "\n";
    // All items after the middle are greater than, items before the middle are
    // less than:
    nth_element(begin(v2), begin(v2) + 4, end(v2));
    cout << "Collection After: [ ";
    for (auto i : v2)
    {
        cout << i << " ";
    }
    cout << " ]\n";
    i = *(begin(v2) + 4);
    cout << "Middle element: " << i << "\n";
}