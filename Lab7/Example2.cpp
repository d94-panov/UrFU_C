#include <iostream>
using namespace std;
class X
{
protected:
    int i;
public:
    void seti(int c) { i = c; }
    virtual void print() { cout << endl << "class X : " << i; }
};
class Y : public X // наследование
{
public:
    void print() { cout << endl << "class Y : " << i; } // переопределение базовой функции
};
int main()
{
    X x;
    X *px = &x;  // Указатель на базовый класс
    Y y;
    x.seti(10);
    y.seti(15);
    px->print();  // класс X: 10
    px = &y;
    px->print();  // класс Y: 15
    cin.get();
    return 0;
}
