#pragma once
#include <vector>
#include <string>
using namespace std;

struct nodo{
    vector<int> ip;
    nodo* next;
    nodo(vector<int> ip, nodo* next) {
        this->ip = ip;
        this->next = next;
    }
    nodo(vector<int> ip) : nodo(ip, nullptr) {}
};

class LinkedList {
    public:
        nodo* head;
        nodo* tail;
        int size;
        LinkedList();
        void insertFirst(vector<int> data);
        void insertLast(vector<int> data);
        nodo* getHead();
        nodo* getTail();
};