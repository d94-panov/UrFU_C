#include <iostream>
#include "Example2.h"
#include "Example2.cpp"

using namespace std;

int main()
{
    Stroka s1("qwert"), s3, s4(s1), s5;
    s3.vvod();
    s3="asdfg";
    s3.vyvod();
    s5=s1+s3+s4;
    cout<<"dlina s5 = "<<s5.dlina();
    s5.vyvod();
    if (s1==s5)
        cout << "stroki s1 and s5 ravni";
    else
        if (s1==s4)
        cout << "stroki s1 and s4 ravni";

    return 0;
}
