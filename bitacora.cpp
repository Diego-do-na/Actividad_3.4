#include "bitacora.h"

BST::BST(){
    this->size = 0;
    this->root = nullptr;
}

bool BST::insert(vector<int> ip){
    nodeBST *nuevo = new MyNodeBST(ip);
    if (this -> root == nullptr){
        this -> root = nuevo;
        this -> size++;
        return true;
    }
    MyNodeBST *current = this -> root;
    while (current != nullptr){
        if (data == current -> valor){
            delete nuevo;
            return false;
        }
        else if (data < current -> valor){
            if (current -> izq == nullptr){
                current -> izq = nuevo;
                this -> size++;
                return true;
            }
            current = current -> izq;
        }
        else{
            if (current -> der == nullptr){
                current -> der = nuevo;
                this -> size++;
                return true;
            }
            current = current -> der;
        }
    }
}