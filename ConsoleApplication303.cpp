#include <iostream>
#include <windows.h>
#include <vector>
#include "LinkedList.h"
#include "Timer.h"
//#define DEBUG
using std::cin;
using std::cout;
using std::endl;
using std::vector;

const int N = 10000;
int M;
int current;

void fArray() { 
    Timer t;
    int end = N - 1;
    int S = 0;
    int* round = new int[N];
    for (int i = 0; i < N; i++) {
        round[i] = i + 1;
#ifdef DEBUG
        cout << round[i] << ' ';
#endif
    }
#ifdef DEBUG
    cout << endl;
#endif
    while (end > 0) {
        S =  (S+ M - 1)%(end+1);
#ifdef DEBUG
        cout << "������� ��� ������� " << round[S] << " ����� �� �����\n";
#endif
        if (S == end) {
            S = 0;
        }
        else
            for (int i = S; i < end; i++) {
                std::swap(round[i], round[i + 1]);
            }
        end--;
#ifdef DEBUG
        for (int i = 0; i <= end; i++) {
            cout << round[i] << ' ';
        }
        cout << endl;
        Sleep(10);
#endif
    }
    current = round[0];
    delete[]round;
    cout << "fArray - ";
}

void fLinkedList() {
    Timer t;
    LinkedList list;
    for (int i = 1; i <= N; i++) {
        list.push_back(i);
#ifdef DEBUG
        cout << i << ' ';
#endif
    }
#ifdef DEBUG
    cout << endl;
#endif
    Node* S = list.head;
    while (list.size()>1) {
        for (int i = 0; i < M - 2; i++) {
            S = list.next(S);
        }
#ifdef DEBUG
        cout << "������� ��� ������� " << list.next(S)->data << " ����� �� �����\n";
#endif
        Node* del = list.next(S);
        if (del == list.head) {
            list.pop_front();
            S = list.head;
        }
        else if (del == list.tail) {
            list.pop_back();
            S = list.head;
        }
        else {
            S->next = list.next(list.next(S));
            delete del;
            S = list.next(S);
            list.length--;
        }
#ifdef DEBUG
        list.print();
        Sleep(10);
#endif
    }
    current = list.head->data;
    cout << "fLinkedList - ";
}

void fSTL() {
    Timer t;
    vector<int> round(N);
    for (int i = 0; i < N; ++i) {
        round[i] = i + 1; // ��������� � 1 �� N
#ifdef DEBUG
        cout << round[i] << ' ';
#endif
    }
#ifdef DEBUG
    cout << endl << ' ';
#endif
    int S = 0; // �������� � ������� �������� (������ 0)
    while (round.size() > 1) {
        S = (S+M - 1) % round.size(); // ��������� ������ ����������
#ifdef DEBUG
        cout << "������� ��� ������� " << round[S] << " ����� �� �����\n";
#endif
        round.erase(round.begin() + S); // ������� ��������
#ifdef DEBUG
        for (const auto& men : round) {
            cout << men << ' ';
        }
        cout << endl;
#endif
    }
    current = round[0];
    cout << "fSTL - ";
}


int main()
{
    setlocale(LC_ALL, "RUS");
    cout << "����� �������: " << N << endl;
    char choose;
    do {
    cout << "����������\na) ����� ����������� ��������, ���� �������� M � ��, ��� ���� ��������� � ������� ��������;\n";
    cout << "b) ����� ��������, � �������� ��������� ����, ���� �������� M � ����� ����������� �������� L.\n";
    cin >> choose;
    } while (choose != 'a' && choose != 'b');
    cout << "������� M: ";
    cin >> M;
    
    cout << "��������� ����� �� " << M << " ��������" << endl;
    fArray();
#ifdef DEBUG
    cout << "----------------------------------------------------------\n";
#endif
    fLinkedList();
#ifdef DEBUG
    cout << "----------------------------------------------------------\n";
#endif
    fSTL();
#ifdef DEBUG
    cout << "----------------------------------------------------------\n";
#endif
    switch (choose) {
    case 'a':
        cout << "����� ����������� ��������: " << current << endl;
        break;
    case 'b':
    {
        cout << "������� ����� ����������� ��������: ";
        int L;
        cin >> L;
        cout << "����� ��������, � �������� ��������� ����: " <<((L>= current)? L - current + 1: N-(current -L)+1) << endl;
    }
        break;
    }
}