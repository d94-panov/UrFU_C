#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <cmath>
#define N 5
using namespace std;

// Переберем все элементы матрицы и найдем наименьший из них.
// Функция принимает матрицу в качестве параметра и возвращает соответствующее минимальное значение.
float findMin(float m[][N])
{
  float minVal = m[0][0];
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (m[i][j] < minVal)
      {
        minVal = m[i][j];
      }
    }
  }
  return minVal;
}

// Переберем все элементы матрицы и найдем наибольший из них.
// Функция принимает матрицу в качестве параметра и возвращает соответствующее максимальное значение.
float findMax(float m[][N])
{
  float maxVal = m[0][0];
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (m[i][j] > maxVal)
      {
        maxVal = m[i][j];
      }
    }
  }
  return maxVal;
}

// Функция ищет наименьшее значение в нижнетреугольной части матрицы.
// Функция перебирает только элементы в нижнетреугольной части матрицы, где индекс строки больше или равен индексу столбца.
float findMinLowerTriangle(float m[][N])
{
  float minVal = m[1][0];
  for (int i = 1; i < N; i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (m[i][j] < minVal)
      {
        minVal = m[i][j];
      }
    }
  }
  return minVal;
}

// Функция ищет наибольшее значение в нижнетреугольной части матрицы
// Функция перебирает только элементы в нижнетреугольной части матрицы, где индекс строки больше или равен индексу столбца.
float findMaxLowerTriangle(float m[][N])
{
  float maxVal = m[1][0];
  for (int i = 1; i < N; i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (m[i][j] > maxVal)
      {
        maxVal = m[i][j];
      }
    }
  }
  return maxVal;
}

// Минимальное значение в верхнетреугольной части матрицы
float findMinUpperTriangle(float m[][N])
{
  float minVal = m[0][1];
  for (int i = 0; i < N; i++)
  {
    for (int j = i + 1; j < N; j++)
    {
      if (m[i][j] < minVal)
      {
        minVal = m[i][j];
      }
    }
  }
  return minVal;
}

// Максимальное значение в верхнетреугольной части матрицы
float findMaxUpperTriangle(float m[][N])
{
  float maxVal = m[0][1];
  for (int i = 0; i < N; i++)
  {
    for (int j = i + 1; j < N; j++)
    {
      if (m[i][j] > maxVal)
      {
        maxVal = m[i][j];
      }
    }
  }
  return maxVal;
}

// Функция для вычисления минимального значения главной диагонали матрицы
float findMinPrimaryDiagonal(float m[][N])
{
  float min_val = m[0][0];
  for (int i = 1; i < N; i++)
  {
    if (m[i][i] < min_val)
    {
      min_val = m[i][i];
    }
  }
  return min_val;
}

// Функция для вычисления максимального значения главной диагонали матрицы
float findMaxPrimaryDiagonal(float m[][N])
{
  float max_val = m[0][0];
  for (int i = 1; i < N; i++)
  {
    if (m[i][i] > max_val)
    {
      max_val = m[i][i];
    }
  }
  return max_val;
}

// Функция для вычисления минимального значения второстепенной диагонали матрицы
float findMinSecondaryDiagonal(float m[][N])
{
  float min_val = m[0][N - 1];
  for (int i = 1; i < N; i++)
  {
    if (m[i][N - 1 - i] < min_val)
    {
      min_val = m[i][N - 1 - i];
    }
  }
  return min_val;
}

// Функция для вычисления максимального значения второстепенной диагонали матрицы
float findMaxSecondaryDiagonal(float m[][N])
{
  float max_val = m[0][N - 1];
  for (int i = 1; i < N; i++)
  {
    if (m[i][N - 1 - i] > max_val)
    {
      max_val = m[i][N - 1 - i];
    }
  }
  return max_val;
}

// Функция для вычисления среднего арифметического значения элементов матрицы
float findAverageValue(float m[][N])
{
  float sum = 0;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      sum += m[i][j];
    }
  }
  return sum / (N * N);
}

// Функция для вычисления среднего арифметического значения элементов нижнетреугольной части матрицы
float findLowerTriangleAverageValue(float m[][N])
{
  float sum = 0;
  int count = 0;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      sum += m[i][j];
      count++;
    } // Для вычисления элементов нижнетреугольной части матрицы реализуем двойной цикл с условием j<=i,
      // чтобы перебрать только те элементы, которые находятся ниже главной диагонали.
  }
  return sum / count;
}

// Функция для вычисления среднего арифметического значения элементов верхнетреугольной части матрицы
float findUpperTriangleAverageValue(float m[][N])
{
  float sum = 0;
  int count = 0;
  for (int i = 0; i < N; i++)
  {
    for (int j = i; j < N; j++)
    {
      sum += m[i][j];
      count++;
    }
  }
  return sum / count;
}

// Функция для вычисления суммы элементов строки матрицы
float findRowSumValue(float m[][N], int row)
{
  float sum = 0;
  for (int j = 0; j < N; j++)
  {
    sum += m[row][j];
  }
  return sum;
}

// Функция для вычисления суммы элементов столбца матрицы
float findColumnSumValue(float m[][N], int col)
{
  float sum = 0;
  for (int i = 0; i < N; i++)
  {
    sum += m[i][col];
  }
  return sum;
}

// Функция для вычисления минимального значения в строке матрицы
float findRowMinValue(float m[][N], int row)
{
  float min_val = m[row][0];
  for (int j = 1; j < N; j++)
  {
    if (m[row][j] < min_val)
    {
      min_val = m[row][j];
    }
  }
  return min_val;
}

// Функция для вычисления максимального значения в строке матрицы
float findRowMaxValue(float m[][N], int row)
{
  float max_val = m[row][0];
  for (int j = 1; j < N; j++)
  {
    if (m[row][j] > max_val)
    {
      max_val = m[row][j];
    }
  }
  return max_val;
}

// Функция для вычисления минимального значения в столбце матрицы
float findColumnMinValue(float m[][N], int col)
{
  float min_val = m[0][col];
  for (int i = 1; i < N; i++)
  {
    if (m[i][col] < min_val)
    {
      min_val = m[i][col];
    }
  }
  return min_val;
}

// Функция для вычисления максимального значения в столбце матрицы
float findColumnMaxValue(float m[][N], int col)
{
  float max_val = m[0][col];
  for (int i = 1; i < N; i++)
  {
    if (m[i][col] > max_val)
    {
      max_val = m[i][col];
    }
  }
  return max_val;
}

// Функция для вычисления среднего арифметического значения в строке матрицы
float findRowAvgValue(float m[][N], int row)
{
  float sum = 0;
  for (int j = 0; j < N; j++)
  {
    sum += m[row][j];
  }
  return sum / N;
}

// Функция для вычисления среднего арифметического значения в столбце матрицы
float findColumnAvgValue(float m[][N], int col)
{
  float sum = 0;
  for (int i = 0; i < N; i++)
  {
    sum += m[i][col];
  }
  return sum / N;
}

// Функция для вычисления суммы элементов нижнетреугольной части матрицы.
// Cуммирование всех элементов, которые находятся ниже главной диагонали.
float findSumLowerTriangleValue(float m[N][N])
{
  float sum = 0.0;
  for (int i = 1; i < N; i++)
  {
    for (int j = 0; j < i; j++)
    {
      sum += m[i][j];
    }
  } // используем два вложенных цикла, чтобы пройти по всем элементам нижнетреугольной и верхнетреугольной частей матрицы
  // начинаем суммирование со второго элемента в каждой строке и до последнего элемента в каждом столбце, чтобы исключить главную диагональ
  return sum;
}

// Функция для вычисления суммы элементов верхнетреугольной части матрицы.
// Суммирование всех элементов, которые находятся выше главной диагонали
float findSumUpperTriangleValue(float m[N][N])
{
  float sum = 0.0;
  for (int i = 0; i < N - 1; i++)
  {
    for (int j = i + 1; j < N; j++)
    {
      sum += m[i][j];
    }
  }
  return sum;
}

// Функция для вычисления элемента, наиболее близкого по значению к среднему арифметическому.
// Функция вычисляет разность между элементом и средним арифметическим значением averageValue.
// Затем она сравнивает это значение с наименьшей известной разностью minDifference и,
// если текущий элемент ближе, обновляет ближайший элемент closestValue и минимальную разность minDifference.
// В конце функция возвращает ближайший элемент closestValue.
float findClosestValue(float m[][N], float averageValue)
{
  float closestValue = m[0][0];
  float minDifference = abs(closestValue - averageValue);

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      float difference = abs(m[i][j] - averageValue);
      if (difference < minDifference)
      {
        closestValue = m[i][j];
        minDifference = difference;
      }
    }
  }

  return closestValue;
}

int main()
{
  float m[N][N];
  int i, j;
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
      m[i][j] = rand() / 10.;
  for (i = 0; i < N; i++)
  {
    for (j = 0; j < N; j++)
      cout << setw(8) << setprecision(5) << m[i][j];
    cout << endl;
  }

  float minVal = findMin(m); // вызываем функцию findMin
  float maxVal = findMax(m); // вызываем функцию findMax
  float lowerMinVal = findMinLowerTriangle(m);
  float lowerMaxVal = findMaxLowerTriangle(m);
  float upperMinVal = findMinUpperTriangle(m);
  float upperMaxVal = findMaxUpperTriangle(m);
  float minPrimaryDiagonalVal = findMinPrimaryDiagonal(m);
  float maxPrimaryDiagonalVal = findMaxPrimaryDiagonal(m);
  float minSecondaryDiagonalVal = findMinSecondaryDiagonal(m);
  float maxSecondaryDiagonalVal = findMaxSecondaryDiagonal(m);
  float averageValue = findAverageValue(m);
  float lowerTriangleAverageValue = findLowerTriangleAverageValue(m);
  float upperTriangleAverageValue = findUpperTriangleAverageValue(m);

  cout << "Min value: " << minVal << endl;
  cout << "Max value: " << maxVal << endl;
  cout << "Min value of lower triangle: " << lowerMinVal << endl;
  cout << "Max value of lower triangle: " << lowerMaxVal << endl;
  cout << "Min value of upper triangle: " << upperMinVal << endl;
  cout << "Max value of upper triangle: " << upperMaxVal << endl;
  cout << "Min primary diagonal value: " << minPrimaryDiagonalVal << endl;
  cout << "Max primary diagonal value: " << maxPrimaryDiagonalVal << endl;
  cout << "Min secondary diagonal value: " << minSecondaryDiagonalVal << endl;
  cout << "Max secondary diagonal value: " << maxSecondaryDiagonalVal << endl;
  cout << "Average value: " << averageValue << endl;
  cout << "Average value of lower triangle: " << lowerTriangleAverageValue << endl;
  cout << "Average value of upper triangle: " << upperTriangleAverageValue << endl;

  // Вычисление суммы элементов строк матрицы.
  // Сделаем перебор всех строк матрицы, и для каждой из них вызовем соответствующие функции для вычисления суммы элементов
  for (int i = 0; i < N; i++)
  {
    float rowSumValue = findRowSumValue(m, i);
    cout << "Sum of elements in row " << i << ": " << rowSumValue << endl;
  }

  // Вычисление суммы элементов столбцов матрицы
  // Сделаем перебор всех столбцов матрицы, и для каждого из них вызовем соответствующие функции для вычисления суммы элементов
  for (int j = 0; j < N; j++)
  {
    float columnSumValue = findColumnSumValue(m, j);
    cout << "Sum of elements in column " << j << ": " << columnSumValue << endl;
  }

  // Вычисление минимального и максимального значений в строках матрицы
  for (int i = 0; i < N; i++)
  {
    float rowMinValue = findRowMinValue(m, i);
    float rowMaxValue = findRowMaxValue(m, i);
    cout << "Row " << i << ": min = " << rowMinValue << ", max = " << rowMaxValue << endl;
  }

  // Вычисление минимального и максимального значений в столбцах матрицы
  for (int j = 0; j < N; j++)
  {
    float columnMinValue = findColumnMinValue(m, j);
    float columnMaxValue = findColumnMaxValue(m, j);
    cout << "Column " << j << ": min = " << columnMinValue << ", max = " << columnMaxValue << endl;
  }

  // Вычисление среднего арифметического значения в строках матрицы
  for (int i = 0; i < N; i++)
  {
    float rowAvgValue = findRowAvgValue(m, i);
    cout << "Row " << i << ": avg = " << rowAvgValue << endl;
  }

  // Вычисление среднего арифметического значения в столбцах матрицы
  for (int j = 0; j < N; j++)
  {
    float columnAvgValue = findColumnAvgValue(m, j);
    cout << "Column " << j << ": avg = " << columnAvgValue << endl;
  }

  float sumLowerTriangleValue = findSumLowerTriangleValue(m);
  float sumUpperTriangleValue = findSumUpperTriangleValue(m);
  float closestValue = findClosestValue(m, averageValue);

  cout << "Sum of lower triangle: " << sumLowerTriangleValue << endl;
  cout << "Sum of upper triangle: " << sumUpperTriangleValue << endl;
  cout << "Closest value to average: " << closestValue << endl;
}