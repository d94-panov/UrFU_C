#include <iostream>
#include <cstring>
using namespace std;

template <class T>
class Tstack
{
protected:
    int numItem;
    T *item;
public:
    Tstack(size_t size = 10)
    {
        numItem = 0;
        item = new T[size];
    }
    ~Tstack()
    {
        delete[] item;
    }
    void push(T t);
    T pop();
    bool isEmpty() { return numItem == 0; } // проверяем пуст ли стек
};

template <class T>
void Tstack <T>::push(T t)
{
    item[numItem++] = t;
}

template <class T>
T Tstack <T>::pop()
{
    return item[--numItem];
}

// Сортировка вагонов поезда
template <class T>
void sortTrain(T *train, size_t size)
{
    Tstack<T> sorted(size); // создание стека sorted (отсортированный)
    Tstack<T> temp(size); // создание стека temp (временный)

    for (size_t i = 0; i < size; i++) { // проход по всем элементам массива вагонов
        if (train[i] == "locomotive") { // если локомотив, то добавляем в стек sorted
            sorted.push(train[i]);
        } else { // иначе добавляем в нужную позицию стека sorted
            bool inserted = false; // флаг, указывающий на то, был ли вставлен текущий вагон в стек sorted
            while (!sorted.isEmpty()) { // продолжаем, пока стек sorted не пустой
                T top = sorted.pop(); // извлекаем верхний элемент стека
                if (top == "locomotive" || top >= train[i]) {
                    temp.push(top);
                } else {
                    sorted.push(top);
                    sorted.push(train[i]);
                    inserted = true; // помечаем, что вставка произошла
                    break;
                }
            }
            // Если не удалось найти место, куда можно вставить текущий вагон, то добавить его в конец отсортированного поезда
            if (!inserted) {
                sorted.push(train[i]);
            }
            // Перекидываем элементы из временного стека в отсортированный поезд
            while (!temp.isEmpty()) {
                sorted.push(temp.pop());
            }
        }
    }

    cout << "Sorted train: ";
    while (!sorted.isEmpty()) {
        cout << sorted.pop() << " ";
    }
    cout << endl;
}

int main()
{
    const int size = 8; // инициализация массива вагонов
    string train[size] = {"carriage2", "carriage1", "carriage7", "carriage3", "carriage5", "carriage4", "locomotive", "carriage6"};

    sortTrain(train, size);

    return 0;
}
