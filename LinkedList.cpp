#include "LinkedList.h"

Node* LinkedList:: next(const Node* node) const {
    if (node->next == nullptr) {
        return head;
    }
    return node->next;
}

void LinkedList::push_front(int value){
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = tail = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
    length++;
}

void LinkedList::push_back(int value) {
    Node* newNode = new Node(value);
    if (tail == nullptr) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
    length++;
}

void LinkedList::pop_front() {
    if (head == nullptr) return;

    Node* temp = head;
    head = head->next;
    delete temp;
    length--;

    if (head == nullptr) {
        tail = nullptr;
    }
}

void LinkedList::pop_back() {
    if (tail == nullptr) return;

    if (head == tail) {
        delete head;
        head = tail = nullptr;
        length = 0;
        return;
    }

    Node* current = head;
    while (current->next != tail) {
        current = current->next;
    }

    delete tail;
    tail = current;
    tail->next = nullptr;
    length--;
}

void LinkedList::insert(int index, int value) {
    if (index < 0 || index > length) {
        cout << "Ошибка: неверный индекс\n";
        return;
    }

    if (index == 0) {
        push_front(value);
    }
    else if (index == length) {
        push_back(value);
    }
    else {
        Node* newNode = new Node(value);
        Node* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        length++;
    }
}

void LinkedList::remove(int index) {
    if (index < 0 || index >= length) {
        cout << "Ошибка: неверный индекс\n";
        return;
    }

    if (index == 0) {
        pop_front();
    }
    else if (index == length - 1) {
        pop_back();
    }
    else {
        Node* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        length--;
    }
}

int LinkedList::get(int index) {
    if (index < 0 || index >= length) {
        cout << "Ошибка: неверный индекс\n";
        return -1; // В реальном коде лучше бросать исключение
    }

    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

void LinkedList::clear() {
    while (head != nullptr) {
        pop_front();
    }
}

void LinkedList::print() {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}






