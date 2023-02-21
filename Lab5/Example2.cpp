// Дополнить программу предыдущего пункта функцией подсчета "пустых" и "непустых" символов в текстовом файле.
// Под "пустыми" символами понимаются символы, не отображающиеся на экране:
// управляющие символы, пробел, звуковой сигнал и т.д.

#include <stdio.h>

int main()
{
    char ch, name[50];
    FILE *in;
    int empty_count = 0, non_empty_count = 0; // переменные для подсчета пустых и непустых символов

    printf("Enter filename to view: ");
    scanf("%s", name);

    if((in=fopen(name, "r"))==NULL)
        printf("File %s is not open", name);
    else
        while((ch=getc(in))!=EOF)
        {
            // проверяем пустой символ или нет
            if(ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r' || ch == '\f' || ch == '\v') // символы пробела, табуляции, переноса строки и тд
                empty_count++; // увеличиваем счетчик, если символ пустой
            else
                non_empty_count++; // увеличиваем счетчик, если символ непустой
            putchar(ch);
        }

    printf("\nNumber of empty characters: %d\n", empty_count);
    printf("Number of nonblank characters: %d\n", non_empty_count);

    return 0;
}
