#include <iostream>
#include <fstream>

const char fname[] = "NewFile";

using namespace std;

int main()
{
    // Создаем новый файл, если только он уже не существует
    ofstream ofs(fname, ios::out);
    if (!ofs) // Проверка состояния потока
    {
        cout << "Wrong situation! File " << fname << " already exists." << endl;
        return 0;
    }
    else
    {
        ofs << "This line is written to a new file";
        ofs.close(); // Закрываем файл
        fstream fs; // Определяем новый объект
        // Открываем файл и устанавливаем на EOF
        fs.open(fname, ios::out | ios::ate);
        fs << "Now it has been added";
        fs.close(); // Закрываем файл
        // Открываем файл как входной
        fstream ifs(fname);
        if (ifs)
        {
            cout << "The old file contains" << "..." << endl;
            char Line[80];
            ifs.getline(Line,sizeof(Line));
            cout << Line;
        }
        else
        {
            cout << "Error when reopening " << fname << endl;
        }
    }
    return 0;
}
