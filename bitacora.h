#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct nodo{
    vector<int> ip;
    nodo *izq, *der;
    nodo(vector<int> ip, nodo *izq, nodo *der){
        this->ip = ip;
        this->izq = izq;
        this->der = der;
    };
    nodo(vector<int> ip){
        this->ip = ip;
        this->izq = nullptr;
        this->der = nullptr;
    };
    ~nodo();
};

class BST{
    private:
        int size;
        nodo *root;
    public:
        BST();
};