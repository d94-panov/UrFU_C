// На основании приведенной программы для двусвязного списка
// написать аналогичную по выполняемым действиям программу для односвязного списка.

#include <iostream>
using namespace std;

struct Node
{
    int d;
    Node *next; // оставляем указатель только на следующий узел
};

Node *first(int d);
void add(Node **pend, int d);
Node *find(Node * const pbeg, int i);
int remove(Node **pbeg, Node **pend, int key);
Node *insert(Node* const pbeg, Node **pend, int key, int d);

int main() {
    // Формирование первого элемента списка
    Node *pbeg = first(1);
    // Список заканчивается, едва начавшись
    Node *pend = pbeg;
    // Добавление в конец списка четырех элементов 2,3,4,5
    for (int i = 2; i < 6; i++) add(&pend, i);
    // Вставка элемента 200 после элемента 2
    insert(pbeg, &pend, 2, 200);
    // Удаление элемента 5
    if (!remove(&pbeg, &pend, 5)) cout << "not found";
    Node *pv = pbeg;
    while (pv) // вывод списка на экран
    {
        cout << pv->d << ' ';
        pv = pv->next;
    }
    return 0;
}

// Формирование первого элемента
Node * first(int d)
{
    Node *pv = new Node;
    pv->d = d;
    pv->next = 0;
    return pv;
}

// Добавление в конец списка
void add(Node **pend, int d) // убрали указатель на предыдущий узел
{
    Node *pv = new Node;
    pv->d = d;
    pv->next = 0;
    (*pend)->next = pv;
    *pend = pv;
}

// Поиск элемента по ключу
Node * find(Node * const pbeg, int d)
{
    Node *pv = pbeg;
    while (pv)
    {
        if(pv->d == d) break;
        pv = pv->next;
    }
    return pv;
}

// Удаление элемента
int remove(Node **pbeg, Node **pend, int key)
{
    Node *pkey = find(*pbeg, key);
    if (pkey) //1
    {
        if (pkey == *pbeg) //2
        {
            *pbeg = (*pbeg)->next;
        }
        else
        if (pkey == *pend) // 3
        {
            Node *pv = *pbeg;
            while (pv->next != *pend) pv = pv->next;
            *pend = pv;
            pv->next = 0;
        }
        else // 4
        {
            Node *pv = *pbeg;
            while (pv->next != pkey) pv = pv->next;
            pv->next = pkey->next;
        }
        delete pkey;
        return 1; // 5
    }
    return 0; // 6
}

// Вставка элемента
Node* insert(Node* const pbeg, Node **pend, int key, int d)
{
    Node *pkey = find(pbeg, key);
    if(pkey)
    {
        Node *pv = new Node;
        pv->d = d;
        // 1 - установление связи нового узла с последующим:
        pv->next = pkey->next;
        // 2 - установление связи нового узла с предыдущим:
        pkey->next = pv;
        // Обновление указателя на конец списка, если узел вставляется в конец:
        if(pkey == *pend)
            *pend = pv;
        return pv;
    }
    return 0;
}
