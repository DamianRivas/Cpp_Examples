#include <iostream>
#include <memory> // For std::unique_ptr and std::make_unique
using namespace std;

class X
{
  public:
    X()
    {
        cout << " X constructor \n";
    }

    ~X()
    {
        cout << " X destructor \n";
    }

    void sayHi()
    {
        cout << " X says hi! :) \n";
    }

  private:
    int m1{};
    double m2{3.14};
};

int main()
{
    auto pX = make_unique<X>();
    pX->sayHi();
}
