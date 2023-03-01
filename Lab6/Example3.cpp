// Изменить программу так, чтобы вместо библиотечных функций, выполняющих действия со строкой,
// использовались аналогичные функции, напианные при выполнении заданий лабораторной работы 4.

#include <iostream>
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

Stroka::Stroka(char *string) // копирование строки
{
    int i = 0;
    while (string[i] != '\0' && i < 80) {
        str[i] = string[i];
        i++;
    }
    str[i] = '\0';
}

Stroka::Stroka(const Stroka& s) // копирование строки
{
    int i = 0;
    while (s.str[i] != '\0' && i < 80) {
        str[i] = s.str[i];
        i++;
    }
    str[i] = '\0';
}

Stroka& Stroka::operator=(const Stroka& s)
{
    int i = 0;
    while (s.str[i] != '\0' && i < 80) {
        str[i] = s.str[i];
        i++;
    }
    str[i] = '\0';
    return *this;
}

Stroka& Stroka::operator+(const Stroka& s)
{
    int i = 0;
    while (str[i] != '\0' && i < 80) {
        i++;
    }
    int j = 0;
    while (s.str[j] != '\0' && i + j < 80) {
        str[i+j] = s.str[j];
        j++;
    }
    str[i+j] = '\0';
    return *this;
}

int Stroka::operator==(const Stroka& s)
{
    int i = 0;
    while (str[i] != '\0' && s.str[i] != '\0') {
        if (str[i] != s.str[i]) {
            return 0;
        }
        i++;
    }
    return str[i] == s.str[i];
}

int Stroka::dlina()
{
    int i = 0;
    while (str[i] != '\0' && i < 80) {
        i++;
    }
    return i;
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
    s3 = Stroka("asdfg");
    s3.vyvod();
    s5 = s1 + s3 + s4;
    cout << "dlina s5 = " << s5.dlina();
    s5.vyvod();
    if (s1 == s5)
        cout << "stroki s1 and s5 ravni";
    else
    if (s1 == s4)
        cout << "stroki s1 and s4 ravni";
}
