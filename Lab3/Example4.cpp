// Отсортировать массив по возрастанию на интервале индексов от N1 до N2.

// Алгоритм сортировки выбором:
// - проходим по всему массиву, начиная с первого элемента;
// - находим минимальный элемент в оставшейся части массива;
// - обмениваем текущий элемент с минимальным элементом;
// - повторяем шаги 2 и 3 для всех элементов, начиная со второго.

#include <iostream>
using namespace std;

// Функция selectionSort реализует алгоритм сортировки выбором.
// Принимает массив arr и его размер n в качестве параметров и сортирует массив по возрастанию.
void selectionSort(int arr[], int n) { 
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    const int SIZE = 10;
    int arr[SIZE] = { 5, 8, 1, 3, 6, 9, 2, 7, 4, 0 };
    // Переменные n1 и n2 задают интервал индексов, на котором нужно выполнить сортировку.
    int n1 = 2;
    int n2 = 7;

    // Сортировка только на интервале от n1 до n2, для этого два вложенных цикла
    for (int i = n1; i <= n2; i++) { // также сортировка выбором
        int minIndex = i;
        for (int j = i + 1; j <= n2; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }

    // Сортировка всего массива
    //selectionSort(arr, SIZE);

    // Вывод массива
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
