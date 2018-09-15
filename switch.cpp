#include <iostream>

using std::cout;
using std::endl;

int main()
{
    enum class Status
    {
        ok,
        warning,
        error
    };

    switch (Status res = Status::ok; res = Status::error)
    {
    case Status::ok:
        cout << "Status is ok" << endl;
        break;
    case Status::warning:
        cout << "Warning!" << endl;
        break;
    case Status::error:
        cout << "ERROR!" << endl;
        break;
    default:
        cout << "No response" << endl;
    }

    // `res` is unusable here because we used a `switch` initialization statement
    // so `res` exists only in the scope of the switch statement.
    // if (res == Status::ok)
    // {
    //     cout << "Everything is okay" << endl;
    // }

    return 0;
}
