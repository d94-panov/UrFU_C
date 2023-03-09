// Написать программу, использующую методы, изменяющие состояние потоков.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream input_file("input.txt");
    ofstream output_file("output.txt");

    if (!input_file.is_open()) {
        cerr << "Could not open input file" << endl;
        return 1;
    }

    if (!output_file.is_open()) {
        cerr << "Could not open output file" << endl;
        return 1;
    }

    string line;
    // Читаем каждую строку из входного файла
    while (getline(input_file, line)) {
        string reversed_line;
        // Создаем новую строку, которая является зеркальным отображением исходной строки
        for (auto it = line.rbegin(); it != line.rend(); ++it) {
            reversed_line += *it;
        }
        // Записываем зеркальную строку в выходной файл
        output_file << reversed_line << endl;
    }

    input_file.close();
    output_file.close();

    return 0;
}
