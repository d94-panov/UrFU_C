#include <iostream>
using namespace std;
int main(void)
{
    int a=2, b=5;
    void obmen1(int, int);
    void obmen2(int*, int*);
    void obmen3(int&, int&);
    cout << "до обмена: a= "<< a <<" b="<<b<< endl;
    //вызов obmen1(int, int);
    obmen1(a, b);
    cout << "после обмена 1: a="<< a <<" b="<<b<< endl;
    //вызов obmen2(int*, int*);
    obmen2(&a, &b);
    cout << "после обмена 2: a="<< a <<" b="<<b<< endl;
    //вызов obmen3(int&, int&);
    obmen3(a, b);
    cout <<"после обмена 3: a="<< a <<" b="<<b<< endl;
}

void obmen1 (int x, int y)
{
    int z;
    z = x;
    x = y;
    y = z;
}

void obmen2 (int *x, int *y)
{
    int z;
    z = *x;
    *x = *y;
    *y = z;
}

void obmen3 (int &x, int &y)
{
    int z;
    z = x;
    x = y;
    y = z;
}
