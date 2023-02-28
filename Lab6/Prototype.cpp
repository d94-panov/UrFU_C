#include <iostream>
#include <cstring>
using namespace std;

class Stroka {
    char str[80];
public:
    Stroka(char *);
    Stroka() {}
    Stroka(const Stroka &);
    Stroka &operator=(const Stroka &);
    Stroka &operator+(const Stroka &);
    int operator==(const Stroka&);
    int dlina();
    void vvod();
    void vyvod();
};

Stroka::Stroka(char *string)
{
    strcpy(str,string);
}
Stroka::Stroka(const Stroka& s) {
    strcpy(str, s.str);
}
Stroka& Stroka::operator=(const Stroka& s)
{
    strcpy(str, s.str);
    return *this;
}
Stroka& Stroka::operator+(const Stroka& s)
{
    strcpy(str, s.str);
    return  * this;
}
int Stroka::operator==(const Stroka& s)
{
    if ((strcmp(str, s.str))==0)
        return 1;
    else
        return 0;
}
int Stroka::dlina()
{
    return  strlen(str);
}
void Stroka::vvod()
{
    cin >> str;
}
void Stroka::vyvod()
{
    cout << str;
}
int main(void)
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
}
