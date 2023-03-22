// Отсортировать массив по убыванию на интервале индексов от N1 до N2

#include <iostream>
using namespace std;

void selectSort(int arr[], int a, bool reverse = false)
{
  for (int x = 0; x < a - 1; x++)
  {
    int extIndex = x;
    for (int y = x + 1; y < a; y++)
    {
      if ((reverse && arr[y] > arr[extIndex]) || (!reverse && arr[y] < arr[extIndex]))
      {
        extIndex = y;
      }
    }
    int temp = arr[extIndex];
    arr[x] = temp;
  }
}

int main()
{
  int size = 10;
  int arr[size] = {1, 0, 4, 6, 7, 9, 8, 3, 2};
  int n1 = 0;
  int n2 = 5;

  // Сортировка на интервале от n1 до n2
  for (int x = n1; x <= n2; x++)
  {
    int extIndex = x;
    for (int y = x + 1; y <= n2; y++)
    {
      if (arr[y] > arr[extIndex])
      {
        extIndex = y;
      }
    }
    int temp = arr[extIndex];
    arr[extIndex] = arr[x];
    arr[x];
  }

  // вывод массива
  for (int x = 0; x < size; x++)
  {
    cout << arr[x] << " ";
  }
  return 0;
}