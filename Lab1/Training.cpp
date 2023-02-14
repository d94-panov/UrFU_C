#include <iostream>
using namespace std;

int main()
{
    double y = 10.5;
    double *ptr = &y;

    cout << "Value of y: " << y << endl;
    cout << "Address of y: " << &y << endl;
    cout << "Value of ptr: " << ptr << endl;
    cout << "Value pointed by ptr: " << *ptr << endl;

    *ptr = 20.5;
    cout << "Value of y after modification: " << y << endl;

    return 0;
}
