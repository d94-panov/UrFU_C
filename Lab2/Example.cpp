#include <iostream>
#include <iomanip>
#include <conio.h>
#define N 5
void main()
{
  float m[N][N];
  int i, j;
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
      m[i][j] = rand() / 10.;
  for (i = 0; i < N; i++)
  {
    for (j = -; j < N; j++)
      count << setw(8) << setprecision(5) << m[i][j];
    count << endl;
    getch();
  }
}