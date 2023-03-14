// Написать программу которая сортирует одномерный массив
// методом "быстрой сортировки"
// Схему алгоритма можно описать таким образом:
// - выбрать опорный элемент в массиве;
// - разделить массив на 2 части следующим образом:
// все элементы из левой части, которые больше или равны опорному, перемещаем в правую,
// все элементы из правой, которые меньше или равны опорному перемещаем в левую часть;
// - в левой части массива останутся элементы, которые меньше или равны центральному, в правой — больше либо равны;
// - рекурсивно повторяем действие для левой и правой части массива.
#include <iostream>
using namespace std;

int main()
{
  int arr[] = {3, 6, 7, 5, 8, 9, 1};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Source array: \n";
  printArray(arr, n);

  fastSort(arr, 0, n - 1);

  cout << "Sorted array: \n";
  printArray(arr, n);

  return 0;
}

// функция быстрой сортировки
void fastSort(int arr[], int low, int high)
{
  if (low < high)
  {
    // получаем индекс опорного элемента после разделения массива
    int pi = separation(arr, low, high);

    // сортируем элементы рекурсивно перед опорным и после него
    fastSort(arr, low, pi - 1);
    fastSort(arr, pi + 1, high);
  }
}

// функция вывода массива на экран
void printArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

// функция разделения массива на две части
int separation(int arr[], int low, int high)
{
  int pivot = arr[high];
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++)
  {
    // если текущий элемент меньше или равен опорному
    if (arr[j] <= pivot)
    {
      i++; // увеличиваем индекс меньшего элемента
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

// функиция обмена элементов массива
void swap(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}