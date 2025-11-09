#pragma once
#include <vector>
#include <string>
using namespace std;

struct NodoBST{
    int repeticion;
    vector<string> ips;
    NodoBST* izq;
    NodoBST* der;
    NodoBST(int repeticion, NodoBST*izq, NodoBST*der){
        this -> repeticion = repeticion;
        this -> izq = izq;
        this -> der = der;
    }
    NodoBST(int repeticion){
        this -> repeticion = repeticion;
        this -> izq = nullptr;
        this -> der = nullptr;
    }
};

class BST {
    private:
        NodoBST* root;
        int size;
        void destructor(NodoBST* nodo);
    public:
        BST();
        ~BST();
        void insertar(string ip, int repeticion);
        void imprimir_ips();
};