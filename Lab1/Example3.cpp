#include <iostream>
using namespace std;



int main(void)
{
  int a = 2, b = 5;
  void obmen1(int, int);
  void obmen2(int *, int *);
  void obmen3(int &, int &);
  cout << "до обмена: a= " << a << "b=" << endl;
  // вызов obmen1(int, int);
  cout << "после обмена 1: a= " << a << "b=" << b << endl;
  // вызов obmen2(int*, int*);
  cout << "после обмена 2: a= " << a << "b=" << b << endl;
  obmen3(a, b);
  // вызов obmen3(int&, int&);
  cout << "после обмена 3:  a=" << a << "b=" << b << endl;
}
void obmen1(int x, int y)
{
  int tmp;
  tmp = x;
  x = y;
  y = tmp;
}

void obmen2(int *x, int *y)
{
  int tmp;
  tmp = *x;
  *x = *y;
  *y = tmp;
}

void obmen3(int &x, int &y)
{
  int tmp;
  tmp = x;
  x = y;
  y = tmp;
}
