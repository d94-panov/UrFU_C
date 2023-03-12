#include <iostream>
#include <algorithm> // для функции sort()
using namespace std;

class Money
{
    long dollars;
    int cents;
public:
    Money(){ }
    Money(long d, int c)
    {
        dollars = d;
        cents = c;
    }
    int operator>(const Money&) const;
    friend ostream& operator << (ostream&, Money&); // const?
};

int Money::operator>(const Money& amt) const
{
    return (dollars>amt.dollars) || ((dollars==amt.dollars)&&(cents>amt.cents));
}

ostream& operator<<(ostream& os, Money &amt)
{
    os << "$" << amt.dollars << '.' << amt.cents;
    return os;
}

bool CompareMoney(const Money& a, const Money& b) // функция сравнения
{
    return a > b;
}

int main()
{
    Money mas[] = {Money(19,10),
                   Money(99,99),
                   Money(99,95),
                   Money(19,95)};
    sort(mas, mas + sizeof(mas)/sizeof(mas[0]), CompareMoney); // добавили CompareMoney
    for(int i=0; i<sizeof(mas)/sizeof(mas[0]); i++) // добавили int
        cout << "mas[" << i << "j = " << mas[i] << endl;
}
