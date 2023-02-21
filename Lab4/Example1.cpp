// Написать программу, которая использует функции: 
// strlen() - определение длины строки
// strcat() - конкатенация строк
// strcpy() - копирование строк
// strcmp() - сравнение строк
// Для работы с этими функциями подключить файл string.h

#include <iostream>
#include <string.h>

int main()
{
    // Создадим три массива символов
    char str1[20] = "Hello";
    char str2[20] = "World";
    char str3[20];
    int len;

    // Использование strlen()
    len = strlen(str1);
    std::cout << "Длина строки '" << str1 << "' равна " << len << std::endl;

    // Использование strcat()
    strcat(str1, str2);
    std::cout << "Строка после объединения: " << str1 << std::endl;

    // Использование strcpy()
    strcpy(str3, str1);
    std::cout << "Копия строки: " << str3 << std::endl;

    // Использование strcmp()
    if (strcmp(str1, str3) == 0)
        std::cout << "Строки равны" << std::endl;
    else
        std::cout << "Строки не равны" << std::endl;

    return 0;
}
