// Написать программу, которая обрабатывает текстовый файл.
// В исходном тексте номера страниц проставлены в первой строке страницы.
// Требуется перенести эти номера в последнюю строку страницы и убрать знаки переноса. Например, номер страницы - 34 -, надо получить 34.
// Признаком перехода на следующую страницу является управляющий символ '\f'.

#include <fstream>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
    string inputFileName = "input.txt";
    string outputFileName = "output.txt";

    // Открываем исходный файл
    ifstream inputFile(inputFileName);

    // Открываем выходной файл
    ofstream outputFile(outputFileName);

    // Проверяем, что файлы были успешно открыты
    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "cannot open files" << endl;
        return 1;
    }

    // Читаем файл построчно
    string line;
    int pageIndex = 1;
    int lineIndex = 0;
    bool isFPreviousChar = false;
    while (getline(inputFile, line)) {
        if (lineIndex == 0) {
            lineIndex++;
        } else {
            if (isFPreviousChar) {
                isFPreviousChar = false;
            } else {
                if (strcmp(line.c_str(), "\\f") == 0) {
                    outputFile << pageIndex << endl;
                    outputFile << "\\f" << endl;
                    isFPreviousChar = true;
                    pageIndex++;
                } else {
                    outputFile << line << endl;
                }
            }
        }
    }

    // Закрываем файлы
    inputFile.close();
    outputFile.close();

    return 0;
}
