#ifndef person_hpp
#define person_hpp

#include <string>
#include "./resource.hpp"

class Person
{
private:
  std::string firstname;
  std::string lastname;
  int arbitraryNumber;
  Resource *pResource;

public:
  Person(std::string first, std::string last, int arbitraryNumber);
  Person();
  ~Person();
  Person(Person const &p); // Copy constructor
  Person &operator=(const Person &p); // Copy assignment
  std::string getName() const;
  int getNumber() const { return arbitraryNumber; }
  void setNumber(int number) { arbitraryNumber = number; }
  void setFirstName(std::string first) { firstname = first; }
  void addResource();
};

#endif
