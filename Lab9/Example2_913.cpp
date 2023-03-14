#include <iostream>
#include <string>
#include <cstring>
using namespace std;

template <class T>
T getmax(T t1, T t2) // Возвращает больший из двух параметров
{
    return t1 > t2?t1:t2;
}
char getmax(const char* s1, const char* s2) {
    return strcmp (s1, s2) >0? *s1: *s2;
}
template <class T>
T getmax(T t[], size_t size)
{
    T retval = t[0];
    int i;
    for(i = 0; i < size; i++)
        if(t[i] > retval) retval = t[i];
    return retval;
}

int main()
{
    int i1 = 3, i2 = 5;
    const char *s1 = "stroka1";
    const char *s2 = "stroka2";
    cout << "max int = " << getmax(i1, i2) << endl;
    cout << "max str = " << getmax(s1, s2) << endl;
}
