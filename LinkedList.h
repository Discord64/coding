#pragma once
#include <iostream>
using std::cout;
using std::endl;
// Узел списка
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
// Класс связного списка
class LinkedList {
friend void fLinkedList();
private:
    Node* head;
    Node* tail;
    int length;
    Node* next(const Node* node) const;
public:
    // Конструктор
    LinkedList() : head(nullptr), tail(nullptr), length(0) {}
    // Деструктор
    ~LinkedList() {
        clear();
    }
    // Добавление в начало
    void push_front(int value);
    // Добавление в конец
    void push_back(int value);
    // Удаление из начала
    void pop_front();
    // Удаление из конца
    void pop_back();
    // Вставка по индексу
    void insert(int index, int value);
    // Удаление по индексу
    void remove(int index);
    // Получение элемента по индексу
    int get(int index);
    // Очистка списка
    void clear();
    // Получение размера списка
    int size() {
        return length;
    }
    // Проверка на пустоту
    bool empty() {
        return length == 0;
    }
    // Вывод списка
    void print();
};