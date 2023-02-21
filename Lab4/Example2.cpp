// Написать варианты функций:
// - определения длины строк тремя способами;
// - копирование строк;
// - сравнение строк;
// - конкатенация строк.

#include <iostream>
using namespace std;

// функция определения длины строки способом 1
int dlina1(char* str) { // функция принимает указатель на строку
    int count = 0;
    while (*str != '\0') { // считаем колво символов, пока не дойдем до нулевого 
        count++;
        str++;
    }
    return count;
}

// функция определения длины строки способом 2
// используем указатель, чтобы перемещаться по строке до ее конца
int dlina2(char* str) {
    char* temp = str;
    while (*temp != '\0') {
        temp++;
    }
    return (temp - str); // разница между указателем на конец и указателем на начало строки = длина строки
}

// функция определения длины строки способом 3
int dlina3(char* str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) { // перебираем все символы в строке, пока не встретим нулевой символ 
        count++;
    }
    return count;
}

// функция копирования строки
void kopir(char* str1, char* str2) {
    while (*str1 != '\0') { // в цикле копируем каждый символ из 1 строки во 2, пока не дойдем до нулевого символа, затем добавляем нулевой символ в конец второй строки
        *str2 = *str1;
        str1++;
        str2++;
    }
    *str2 = '\0';
}

// функция сравнения строк
void sravn(char* str1, char* str2) {
    while (*str1 == *str2) {
        if (*str1 == '\0') {
            cout << "Строки равны" << endl;
            return;
        }
        str1++;
        str2++;
    }
    cout << "Строки не равны" << endl;
}

// функция конкатенации строк
// сравниваем символы в двух строках, пока не встретим отличающиеся, либо нулевой символ
void konkat(char* str1, char* str2) {
    while (*str1 != '\0') {
        str1++;
    }
    while (*str2 != '\0') {
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';
}

int main() {
    char str1[] = "qwerty", str2[] = "1234567890";

    // использование функций длины строки
    cout << "длина str1=" << dlina1(str1) << ", str2=";
    cout << dlina1(str2) << endl;
    cout << "длина str1=" << dlina2(str1) << ", str2=";
    cout << dlina2(str2) << endl;
    cout << "длина str1=" << dlina3(str1) << ", str2=";
    cout << dlina3(str2) << endl;

    // вызов kopir(char*, char*);
    kopir(str1, str2);
    cout << "результат копирования: str1=" << str1;
    cout << ", str2=" << str2 << endl;

    // вызов sravn(char*, char*);
    cout<< "результат сравнения: str1="<< str1;
    cout<<", str2="<<str2<< endl;
    sravn(str1, str2);

    // вызов konkat(char*, char*);
    konkat(str1, str2);
    cout << "результат сцепления: str1=" << str1;
    cout << ", str2=" << str2 << endl;

    return 0;
}
