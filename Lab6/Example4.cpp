// Дополнить описание класса конструктором, который создает экземпляр класса, используя заданный размер динамической памяти.

#include <iostream>
#include <cstring>
using namespace std;

class Stroka {
    char *str;
public:
    Stroka(char *);
    Stroka() {}
    Stroka(const Stroka &);
    Stroka(int); // конструктор, который создает экземпляр класса, используя заданный размер динамической памяти
    ~Stroka(); // деструктор для избежания утечки памяти
    Stroka &operator=(const Stroka &);
    Stroka operator+(const Stroka &);
    int operator==(const Stroka&);
    int dlina();
    void vvod();
    void vyvod();
};

Stroka::Stroka(char *string)
{
    str = new char[strlen(string)+1]; // выделение памяти для строки
    strcpy(str, string);
}

Stroka::Stroka(const Stroka& s)
{
    str = new char[strlen(s.str)+1]; // выделение памяти для строки
    strcpy(str, s.str);
}

Stroka::Stroka(int size)
{
    str = new char[size]; // выделение памяти для строки заданного размера
}

Stroka::~Stroka()
{
    delete[] str; // освобождение памяти
}

Stroka& Stroka::operator=(const Stroka& s)
{
    if (this != &s) { // проверка на самоприсваивание
        delete[] str; // освобождение текущей памяти
        str = new char[strlen(s.str)+1]; // выделение памяти для новой строки
        strcpy(str, s.str);
    }
    return *this;
}

Stroka Stroka::operator+(const Stroka& s)
{
    int new_size = strlen(str) + strlen(s.str) + 1; // выделение памяти для временной строки
    Stroka result(new_size);
    strcpy(result.str, str);
    strcat(result.str, s.str); // конкатенация строк
    return result;
}

int Stroka::operator==(const Stroka& s)
{
    return strcmp(str, s.str) == 0;
}

int Stroka::dlina()
{
    return strlen(str);
}

void Stroka::vvod()
{
    char buffer[80];
    cin.getline(buffer, 80);
    str = new char[strlen(buffer)+1];
    strcpy(str, buffer);
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
    return 0;
}
