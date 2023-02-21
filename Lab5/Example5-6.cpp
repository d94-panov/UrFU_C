// Написать программу-шифратор файлов. Она читает из файла и пишет в другой файл закодированные символы.
// Схема шифровки: c=c^key[i], где c - символ, считанный из файла;
// key - ключ шифрования, строка, которая передается как параметр командной строки.
// Программа использует символы из key циклически, пока не будет считан весь код.
// Для проверки правильности программы зашифровать зашифрованный файл еще раз с тем же ключом.
// Должен получиться файл - точная копия исходного файла.
// Дополнить программу возмодностью вводить имя файла и ключ из командной строки.

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

    ifstream input(input_filename); // чтение из входного файла
    ofstream output(output_filename); // запись в выходной файл

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
