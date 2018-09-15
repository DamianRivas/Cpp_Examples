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
  virtual ~Person();
  virtual std::string getName() const;
  virtual int getNumber() const { return arbitraryNumber; }
  void setNumber(int number) { arbitraryNumber = number; }
  void setFirstName(std::string first) { firstname = first; }
};

#endif
