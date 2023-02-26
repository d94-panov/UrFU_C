#include <iostream>
#include <fstream>
#include <string>
#include <vector> // шаблон для реализации динамического массива
#include <algorithm>
#include <ctime>
using namespace std;

// 1. Преобразуем символы в числа
// 2. Перемешаем символы перестановкой

// Функция преобразования символа в число
int char_to_int(char c) {
    return static_cast<int>(c);
}

// Функция преобразования числа в символ
char int_to_char(int i) {
    return static_cast<char>(i);
}

// Функция генерации псевдослучайной последовательности
vector<int> generate_permutation(int n) {
    vector<int> permutation(n);

    // Заполнение значениями от 0 до n-1
    for (int i = 0; i < n; ++i) {
        permutation[i] = i;
    }

    // Перемешивание элементов с помощью алгоритма Фишера-Йетса:
    // - алгоритм начинает работу с последнего элемента и перемещается к первому
    // - выбирается случайный элемент и перемещается на позицию
    // - продолжать, пока все элементы не будут перемещены
    srand(time(nullptr)); // Инициализация генератора случайных чисел
    for (int i = n - 1; i >= 1; --i) {
        int j = rand() % (i + 1);
        swap(permutation[i], permutation[j]);
    }

    return permutation;
}

// Функция шифрования
void encrypt(ifstream& input, ofstream& output, const string& key) {
    int key_length = key.length();
    int key_index = 0;
    char c;

    while (input.get(c)) {
        // Преобразование символа в число
        int x = char_to_int(c);
        // XOR-шифрование с ключом
        x = x ^ char_to_int(key[key_index]); // операцией исключающего ИЛИ преобразуем каждый символ в битовую последовательность
        // Перемешивание битов числа
        vector<int> permutation = generate_permutation(8);
        int y = 0;
        for (int i = 0; i < 8; ++i) {
            y |= ((x >> permutation[i]) & 1) << i;
        }

        output.put(int_to_char(y));
        // Обновление индекса ключа
        key_index = (key_index + 1) % key_length;
    }

}

// Функция дешифрования
void decrypt(ifstream& input, ofstream& output, const string& key) {
    int key_length = key.length();
    int key_index = 0;
    char c;

    while (input.get(c)) {
        // Преобразование символа в число
        int x = char_to_int(c);
        // Перемешивание битов числа
        vector<int> permutation = generate_permutation(8);
        int y = 0;
        for (int i = 0; i < 8; ++i) {
            y |= ((x >> i) & 1) << permutation[i];
        }
        // XOR-дешифрование с ключом
        y = y ^ char_to_int(key[key_index]);
        // Преобразование числа в символ
        output.put(int_to_char(y));
        // Обновление индекса ключа
        key_index = (key_index + 1) % key_length;
    }

}

int main() {
// Открытие входного файла для чтения
    ifstream input_file("input.txt");
    if (!input_file) {
        std::cerr << "Error opening input file\n";
        return 1;
    }

    // Открытие выходного файла для записи
    ofstream output_file("output.txt");
    if (!output_file) {
        std::cerr << "Error opening output file\n";
        return 1;
    }

// Чтение ключа из консоли
    string key;
    cout << "Enter encryption key: ";
    cin >> key;

// Шифрование входного файла
    encrypt(input_file, output_file, key);

// Закрытие файлов
    input_file.close();
    output_file.close();

// Открытие зашифрованного файла для чтения
    ifstream encrypted_file("output.txt");
    if (!encrypted_file) {
        cerr << "Error opening encrypted file\n";
        return 1;
    }

// Открытие дешифрованного файла для записи
    ofstream decrypted_file("decrypted.txt");
    if (!decrypted_file) {
        cerr << "Error opening decrypted file\n";
        return 1;
    }

// Дешифрование зашифрованного файла
    decrypt(encrypted_file, decrypted_file, key);

// Закрытие файлов
    encrypted_file.close();
    decrypted_file.close();

    cout << "Done!\n";

    return 0;
}
