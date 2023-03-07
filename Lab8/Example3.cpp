// Переписать программу-шифратор из ЛР 5 с использованием классов потоков.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string key;
    string input_filename;
    string output_filename;

    cout << "Enter encryption key: ";
    cin >> key;

    cout << "Enter input filename: ";
    cin >> input_filename;

    cout << "Enter output filename: ";
    cin >> output_filename;

    ifstream input(input_filename); // файловый поток ввода
    ofstream output(output_filename); // файловый поток вывода

    if (!input.is_open()) {
        std::cerr << "Failed to open input file" << std::endl; // ошибка если не удалось открыть входной файл
        return 1;
    }

    if (!output.is_open()) {
        std::cerr << "Failed to open output file" << std::endl; // // ошибка если не удалось открыть выходной файл
        return 1;
    }

    int key_length = key.length(); // вычисление длины ключа шифрования
    int key_index = 0; // начальное значение индекса ключа
    char c; // переменная для хранения символов из файла

    while (input.get(c)) { // пока есть символы во входном файле
        c = c ^ key[key_index]; // применяем ключ
        output.put(c); // запись зашифрованного символа в выходной файл
        key_index = (key_index + 1) % key_length; // переход к следующему символу ключа
    }

    input.close();
    output.close();
    return 0;
}
