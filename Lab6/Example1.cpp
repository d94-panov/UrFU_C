// Описать класс для работы со строкой, как со стандартным типом данных.
// В разделе описания элементов-данных класс должен иметь переменную для хранения символов строки.
// В разделе описания элементов-функций необходимо предусмотреть:
// - конструкторы в нескольких вариантах;
// - деструкторы, если необходимо;
// - перегруженные операции для выполнения присваивания (=), сцепления (+), сравнения (==);
// - методы для определения длины строки;
// - методы ввода и вывода строки.

#include <iostream>
#include <cstring>
using namespace std;

class Stroka {
    char str[80]; // символьный массив для хранения строки
public:
    Stroka(char *); // Конструктор с одним параметром
    Stroka() {} // Конструктор по умолчанию
    Stroka(const Stroka &); // Конструктор копирования
    Stroka &operator=(const Stroka &); // Перегрузка оператора присваивания
    Stroka &operator+(const Stroka &); // Перегрузка оператора сложения строк
    int operator==(const Stroka&); // Перегрузка оператора сравнения строк
    int dlina(); // Функция для определения длины строки
    void vvod(); // Функция для ввода строки с клавиатуры
    void vyvod(); // Функция для вывода строки на экран
};

Stroka::Stroka(char *string)
{
    strcpy(str,string); // Копируем переданную строку
}
Stroka::Stroka(const Stroka& s) {
    strcpy(str, s.str); // Копируем символьный массив
}
Stroka& Stroka::operator=(const Stroka& s)
{
    strcpy(str, s.str);
    return *this; // Возвращаем ссылку на текущий объект
}
Stroka& Stroka::operator+(const Stroka& s)
{
    strcpy(str, s.str);
    return  * this;
}
int Stroka::operator==(const Stroka& s)
{
    if ((strcmp(str, s.str))==0) // Сравниваем символьные массивы
        return 1;
    else
        return 0;
}
int Stroka::dlina()
{
    return  strlen(str); // функция strlen для определения длины строки
}
void Stroka::vvod() // ввод строки с клавиатуры
{
    cin >> str; // // Считывание строки с клавиатуры функцией cin
}
void Stroka::vyvod() // вывода строки на экран
{
    cout << str;
}
int main(void)
{
    Stroka s1("qwert"), s3, s4(s1), s5; // конструкторы в нескольких вариантах
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
