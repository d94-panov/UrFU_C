#define PR(x) printf("x=%u, *x=%d, &x=%u\n",x, *x, &x) // директива, определяем идентификатор и символы, которыми будет замещаться идентификатор
#include <stdio.h> // директива для ввода/вывода

#include <iostream> // тоже библиотека для ввода/вывода, с ней больше нравится 
using namespace std; // сообщаем компилятору ожидать данные от std, чтобы каждый раз не объявлять

int main() // основной метод main
{
    int mas[] = {100, 200, 300}; // объявляем целочисленный массив
    int *ptr1, *ptr2; // объявляем указатель
    ptr1 = mas; // ссылаемся на первый символ массива
    ptr2 = &mas[2]; // указатель получает адрес переменной 
    PR(ptr1); // вывод в консоль
    ptr1++; // вычисление ptr1, затем инкремент
    PR(ptr1); // вывод в консоль
    PR(ptr2); // вывод в консоль
    ++ptr2; // инкремент, затем вычисление ptr2
    printf("ptr2-ptr1=%u\n\n", ptr2 - ptr1); // вывод в консоль

    // Выполнить программу, иллюстрирующую разные операции с указателями.
    // Повторить эксперемент для разных типов данных.

    // double
    double y = 10.5;
    double *ptrdouble = &y;

    cout << "Value of y: " << y << endl;
    cout << "Address of y: " << &y << endl;
    cout << "Value of ptr: " << ptrdouble << endl;
    cout << "Value pointed by ptr: " << *ptrdouble << endl;

    *ptrdouble = 20.5;
    cout << "Value of y after modification: " << y << endl;

    printf("\n");

    // char
    char z = 'A';
    char *ptrchar = &z;

    cout << "Value of z: " << z << endl;
    cout << "Address of z: " << (void*)&z << endl;
    cout << "Value of ptr: " << (void*)ptrchar << endl;
    cout << "Value pointed by ptr: " << *ptrchar << endl;

    *ptrchar = 'B';
    cout << "Value of z after modification: " << z << endl;

    printf("\n");

    // bool
    bool w = true;
    bool *ptrbool = &w;

    cout << "Value of w: " << w << endl;
    cout << "Address of w: " << &w << endl;
    cout << "Value of ptr: " << ptrbool << endl;
    cout << "Value pointed by ptr: " << *ptrbool << endl;

    *ptrbool = false;
    cout << "Value of w after modification: " << w << endl;

    return 0;
}
