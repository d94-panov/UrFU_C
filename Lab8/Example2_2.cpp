#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char name[12];
    fstream fin; // Неоткрытый объект-поток
    cout << "Enter file name: ";
    cin>>name;
    // Открыли входной потом
    fin.open(name, ios::in);
    if (fin) // Проверяем состояние потока
    {
        cout << "File open" << name << endl;
        fin.close(); // Закрываем файл
    }
    else
    {
        cout << "Input file not open" << name << endl;
    }
    return 0;
}
