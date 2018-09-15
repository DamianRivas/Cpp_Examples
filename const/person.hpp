#ifndef person_hpp
#define person_hpp

#include <string>
class Person
{
private:
  std::string firstname;
  std::string lastname;
  int arbitraryNumber;

public:
  Person(std::string first, std::string last, int arbitraryNumber);
  Person();
  ~Person();
  std::string getName() const;
  int getNumber() const { return arbitraryNumber; }
  void setNumber(int number) { arbitraryNumber = number; }
  bool operator<(Person const &p) const;
  bool operator<(int i) const;
  friend bool operator<(int i, Person const &p);
};
bool operator<(int i, Person &p);
#endif
