// Создать шаблон класса "односвязный линейный список".

#include <iostream>

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d) : data(d), next(nullptr) {}
    };
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    // Добавление элемента в начало списка
    void push_front(const T& data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // Удаление первого элемента списка
    void pop_front() {
        if (head == nullptr) {
            return;
        }
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }

    // Удаление элемента из списка по значению
    void remove(const T& data) {
        if (head == nullptr) {
            return;
        }
        if (head->data == data) {
            pop_front();
            return;
        }
        Node* current = head;
        while (current->next != nullptr && current->next->data != data) {
            current = current->next;
        }
        if (current->next != nullptr) {
            Node* tmp = current->next;
            current->next = current->next->next;
            delete tmp;
        }
    }

    // Получение размера списка
    int size() const {
        int size = 0;
        Node* current = head;
        while (current != nullptr) {
            size++;
            current = current->next;
        }
        return size;
    }

    // Проверка, пустой ли список
    bool empty() const {
        return head == nullptr;
    }

    // Получение первого элемента списка
    T& front() const {
        return head->data;
    }

    // Получение элемента списка по индексу
    T& operator[](int index) const {
        Node* current = head;
        int i = 0;
        while (current != nullptr && i < index) {
            current = current->next;
            i++;
        }
        if (current == nullptr) {
            throw std::out_of_range("Index out of range");
        }
        return current->data;
    }

    // Переопределение оператора вывода для удобного вывода списка
    friend std::ostream& operator<<(std::ostream& os, const LinkedList& list) {
        Node* current = list.head;
        while (current != nullptr) {
            os << current->data << " ";
            current = current->next;
        }
        return os;
    }
};
