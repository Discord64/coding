#pragma once
#include <iostream>
using std::cout;
using std::endl;
// ���� ������
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
// ����� �������� ������
class LinkedList {
friend void fLinkedList();
private:
    Node* head;
    Node* tail;
    int length;
    Node* next(const Node* node) const;
public:
    // �����������
    LinkedList() : head(nullptr), tail(nullptr), length(0) {}
    // ����������
    ~LinkedList() {
        clear();
    }
    // ���������� � ������
    void push_front(int value);
    // ���������� � �����
    void push_back(int value);
    // �������� �� ������
    void pop_front();
    // �������� �� �����
    void pop_back();
    // ������� �� �������
    void insert(int index, int value);
    // �������� �� �������
    void remove(int index);
    // ��������� �������� �� �������
    int get(int index);
    // ������� ������
    void clear();
    // ��������� ������� ������
    int size() {
        return length;
    }
    // �������� �� �������
    bool empty() {
        return length == 0;
    }
    // ����� ������
    void print();
};