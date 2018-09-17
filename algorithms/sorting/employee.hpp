#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>

class Employee
{
  public:
    Employee(std::string first, std::string last, int sal)
        : firstname(first), lastname(last), salary(sal) {}

    int get_salary() { return salary; }
    std::string get_sorting_name() { return lastname + ", " + firstname; }

  private:
    std::string firstname;
    std::string lastname;
    int salary;
};

#endif