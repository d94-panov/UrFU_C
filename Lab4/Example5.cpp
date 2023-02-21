// Организацивать массив строк. Применить функции, написанные в предыдущей программе к строкам, составляющим этот массив. 

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

int main() {
    // создаем массив strs из трех указателей на символы
    const int n = 3;
    char* strs[n];

    for (int i = 0; i < n; i++) {
        strs[i] = (char*) calloc(100, sizeof(char)); // выделяем память с помощью функции calloc()
    }

    strcpy(strs[0], "Hello"); // функция strcpy() для копирования текта в каждую строку
    strcpy(strs[1], "world");
    strcpy(strs[2], "!");

    for (int i = 0; i < n; i++) { // вывод в консоль 
        cout << strs[i] << " ";
    }

    for (int i = 0; i < n; i++) {
        free(strs[i]); // освобождаем память, выделенную для каждой строки функцией free()
    }

    return 0;
}
