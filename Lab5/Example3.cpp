#include <stdio.h>
#include <string.h>

void searchInFile(char *fileName, char *searchString, char *resultFileName);

int main()
{
    char fileName[50], searchString[50], resultFileName[50];

    printf("Enter filename to view: ");
    scanf("%s", fileName);

    printf("Enter a search string: ");
    scanf("%s", searchString);

    printf("Enter a file name to write the results: ");
    scanf("%s", resultFileName);

    searchInFile(fileName, searchString, resultFileName);

    return 0;
}

void searchInFile(char *fileName, char *searchString, char *resultFileName) // Функция searchInFile открывает файлы для чтения и записи результатов
{
    char ch, line[100];
    int lineNumber = 1, found = 0;

    FILE *in, *out;

    if((in=fopen(fileName, "r"))==NULL) {
        printf("File %s is not open\n", fileName);
        return;
    }

    if((out=fopen(resultFileName, "w"))==NULL) {
        printf("File %s is not open\n", resultFileName);
        return;
    }

    while(fgets(line, 100, in) != NULL) { // проходимся по всем строкам файла
        if(strstr(line, searchString) != NULL) { // ищем заданную подстроку
            fprintf(out, "Found in string %d: %s", lineNumber, line); // записываем результаты
            found = 1;
        }
        lineNumber++;
    }

    if(!found) {
        fprintf(out, "Not found\n");
    }

    fclose(in);
    fclose(out);

    printf("Search results saved in a file %s\n", resultFileName);
}
