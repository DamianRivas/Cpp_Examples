#include <iostream>
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
    X *pX = new X{};
    pX->sayHi();

    delete pX; // without this line, there will be a memory leak
    pX = nullptr;

    return 0;
}
