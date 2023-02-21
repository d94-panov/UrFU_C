// Переписать функции так, чтобы они использовали динамическую память при задании строк.

#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    char* str1;
    char* str2;
    str1 = (char*)malloc(100 * sizeof(char)); // функция malloc() для выделения памяти для каждой строки
    str2 = (char*)malloc(100 * sizeof(char)); // sizeof(char) для указания размера элемента

    free(str1); // функция free() освобождает память
    free(str2);
    return 0;
}
