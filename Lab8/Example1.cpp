// Для класса Stroka, написанного на лабораторной работе 6, предусмотреть возможность ввода - вывода его объектов при помощи операций
// помещения и извлечения (аналогично тому, как это делается для объектов стандартных типов данных).

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
    friend ostream& operator<<(ostream& os, const Stroka& s); // Дружественная функция вывода
    friend istream& operator>>(istream& is, Stroka& s); // Дружественная функция ввода
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
    strcat(str, s.str);
    return * this;
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
    return strlen(str);
}
void Stroka::vvod()
{
    cin >> str;
}
void Stroka::vyvod()
{
    cout << str;
}

// Операция извлечения
ostream& operator<<(ostream& os, const Stroka& s)
{
    os << s.str;
    return os;
}

// Операция помещения
istream& operator>>(istream& is, Stroka& s)
{
    is >> s.str;
    return is;
}

int main(void)
{
    Stroka s1("qwert"), s3, s4(s1), s5;
    cin >> s3; // операция помещения
    s3="asdfg";
    cout << s3 << endl; // операция извлечения
    s5=s1+s3+s4;
    cout<<"dlina s5 = "<<s5.dlina() << endl;
    cout << s5 << endl;
    if (s1==s5)
        cout << "stroki s1 and s5 ravni" << endl;
    else
    if (s1==s4)
        cout << "stroki s1 and s4 ravni" << endl;
    return 0;
}
