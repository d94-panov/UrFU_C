// Описание класса выделить в заголовочный файл,
// определение его методов - в файл с расширением .cpp,
// текст главной функции написать в отдельном файле.

#include <iostream>
#include <cstring>
#include "Example2.h"

using namespace std;

Stroka::Stroka(const char *string)
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
