#ifndef tweeter_hpp
#define tweeter_hpp
#include "person.hpp"
#include <string>

class Tweeter : public Person
{
private:
  std::string twitterHandle;

public:
  Tweeter(std::string first,
          std::string last,
          int arbitrary,
          std::string handle);
  ~Tweeter();
  std::string getName() const;
  int getNumber() const { return 0; }
};

#endif
