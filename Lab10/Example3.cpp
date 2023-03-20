// Составить программу, которая содержит динамическую информацию о наличии автобусов в автобусном парке.
// Сведения о каждом автобусе содержат:
// - номер автобуса;
// - фамилию и инициалы водителя;
// - номер маршрута.
// Программа должна обеспечивать:
// - начальное формирование данных обо всех автобусах в парке в виде списка;
// - при выезде каждого автобуса из парка вводится номер автобуса, и программа удаляет данные об этом автобусе из списка автобусов, находящихся в парке,
// и записывает эти данные в список автобусов, находящихся на маршруте;
// - при въезде каждого автобуса в парк вводится номер автобуса, и программа удаляет данные об этом автобусе из списка автобусов, находящихся на маршруте,
// и записывает эти данные в список автобусов, находящихся в парке;
// - по запросу выдаются сведения об автобусах, находящихся в парке, или об автобусах, находящихся на маршруте.

#include <iostream>
#include <string>

using namespace std;

template <typename T>
class ListNode {
public:
    T data; // Данные элемента списка
    ListNode* next; // Указатель на следующий элемент списка

    ListNode(T value) { // Конструктор класса
        data = value;
        next = nullptr;
    }
};

template <typename T>
class LinkedList {
public:
    ListNode<T>* head; // Указатель на голову списка

    LinkedList() { // Конструктор класса
        head = nullptr;
    }

    void insert(T value) { // Метод вставки элемента в начало списка
        ListNode<T>* newNode = new ListNode<T>(value); // Создание нового элемента списка
        newNode->next = head; // Установка указателя на следующий элемент
        head = newNode; // Обновление указателя на голову списка
    }

    void remove(T value) { // Метод удаления элемента из списка
        ListNode<T>* prev = nullptr; // Указатель на предыдущий элемент
        ListNode<T>* curr = head; // Указатель на текущий элемент
        while (curr != nullptr) {
            if (curr->data == value) {
                if (prev != nullptr) { // Если найден элемент, то обновляем указатели
                    prev->next = curr->next;
                }
                else {
                    head = curr->next;
                }
                delete curr; // Освобождаем память, занятую удаляемым элементом
                break;
            }
            prev = curr; // Обновление указателя на предыдущий элемент
            curr = curr->next; // Обновление указателя на текущий элемент
        }
    }

    void printList() { // Метод вывода списка на экран
        ListNode<T>* curr = head;
        while (curr != nullptr) {
            cout << *curr->data << endl; // Выводим данные текущего элемента
            curr = curr->next; // Обновляем указатель на текущий элемент
        }
    }
};

class Bus {
public:
    int number;
    string driver;
    int route;

    Bus(int n, string d, int r) { // Конструктор класса
        number = n;
        driver = d;
        route = r;
    }

    friend ostream& operator<<(ostream& os, const Bus& bus) {
        os << "Number: " << bus.number << ", Driver: " << bus.driver << ", Route: " << bus.route;
        return os;
    }
};

int main() {
    LinkedList<Bus *> parkList;
    LinkedList<Bus *> routeList;

    // формирование данных обо всех автобусах в парке в виде списка
    parkList.insert(new Bus(1, "Ivanov", 101));
    parkList.insert(new Bus(2, "Petrov", 102));
    parkList.insert(new Bus(3, "Sidorov", 103));

    cout << "All buses: " << endl;
    parkList.printList();

    // выезд автобуса из парка
    int busNumber;
    cout << "Enter the number of the bus that is leaving the park: ";
    cin >> busNumber;

    // Ищем автобус с заданным номером в parkList
    ListNode<Bus *> *curr = parkList.head;
    while (curr != nullptr) {
        // Если автобус найден, сохраняем указатель на него и переносим его в routeList
        if (curr->data->number == busNumber) {
            Bus *bus = curr->data;
            routeList.insert(bus);
            parkList.remove(bus);
            break;
        }
        curr = curr->next;
    }

    // въезд автобуса в парк
    cout << "Enter the number of the bus that is entering the park: ";
    cin >> busNumber;

    curr = routeList.head;
    while (curr != nullptr) {
        // Если автобус найден, сохраняем указатель на него и переносим его в parkList
        if (curr->data->number == busNumber) {
            Bus *bus = curr->data;
            parkList.insert(bus);
            routeList.remove(bus);
            break;
        }
        curr = curr->next;
    }

    // вывод списка автобусов в парке
    cout << "Buses in the park: " << endl;
    parkList.printList();

    // вывод списка автобусов на маршруте
    cout << "Buses on the route: " << endl;
    routeList.printList();

    return 0;
}
