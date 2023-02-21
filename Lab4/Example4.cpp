// Изменить программу так, чтобы вместо malloc() использовалась функция calloc().

#include <iostream>
#include <cstdlib> // добавили файл <cstdlib> для объявления функции calloc()
using namespace std;

int main() {
    char* str1;
    char* str2;
    str1 = (char*) calloc(100, sizeof(char)); // malloc() заменили на calloc(). Передаем кол-во и размер элементов
    str2 = (char*) calloc(100, sizeof(char));

    free(str1);
    free(str2);
    return 0;
}
