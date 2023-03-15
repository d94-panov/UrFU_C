#include <cstring>

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
