#include "LinkedList.h"

LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

void LinkedList::insertFirst(vector<int> data) {
    nodo* nuevo = new nodo(data, head);
    if (size == 0) {
        tail = nuevo;
    }
    head = nuevo;
    size++;
}

void LinkedList::insertLast(vector<int> data) {
    nodo* nuevo = new nodo(data, nullptr);
    if (size == 0) {
        head = nuevo;
        tail = nuevo;
    } else {
        tail->next = nuevo;
        tail = nuevo;
    }
    size++;
}