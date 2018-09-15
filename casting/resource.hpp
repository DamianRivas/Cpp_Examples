#ifndef resource_hpp
#define resource_hpp

#include <string>

class Resource
{
  private:
    std::string name;

  public:
    Resource(std::string n);
    ~Resource(void);
    std::string getName() const { return name; }
};

#endif
