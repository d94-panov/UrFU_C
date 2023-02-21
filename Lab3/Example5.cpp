// Отсортировать массив по убыванию на интервале индексов от N1 до N2.

#include <iostream>
using namespace std;

void selectionSort(int arr[], int n, bool reverse = false) { // reverse 
    for (int i = 0; i < n - 1; i++) {
        int extIndex = i;
        for (int j = i + 1; j < n; j++) {
            if ((reverse && arr[j] > arr[extIndex]) || (!reverse && arr[j] < arr[extIndex])) {
                extIndex = j;
            }
        }
        int temp = arr[extIndex];
        arr[extIndex] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    const int SIZE = 10;
    int arr[SIZE] = { 5, 8, 1, 3, 6, 9, 2, 7, 4, 0 };
    int n1 = 0;
    int n2 = 5;

    // Сортировка только на интервале от n1 до n2
    for (int i = n1; i <= n2; i++) {
        int extIndex = i;
        for (int j = i + 1; j <= n2; j++) {
            if (arr[j] > arr[extIndex]) {
                extIndex = j;
            }
        }
        int temp = arr[extIndex];
        arr[extIndex] = arr[i];
        arr[i] = temp;
    }

    // Вывод массива
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
