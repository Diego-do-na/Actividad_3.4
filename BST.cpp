#include "BST.h"
#include <stack>
#include <iostream>
using namespace std;

BST::BST(){
    this -> size = 0;
    root = nullptr;
}

BST::~BST(){
    destructor(root);
}

void BST::destructor(NodoBST* nodo){
    if (nodo != nullptr) {
        destructor(nodo -> izq);
        destructor(nodo -> der);
        delete nodo;
    }
}

void BST::insertar(string ip, int repeticion){
    NodoBST* current = root;
    if (root == nullptr) {
        NodoBST* nuevo = new NodoBST(repeticion);
        nuevo -> ips.push_back(ip);
        root = nuevo;
    }
    else {
        while (current != nullptr) {
            if (current -> repeticion == repeticion) {
                current -> ips.push_back(ip);
                return;
            } 
            else if (repeticion < current -> repeticion) {
                if (current -> izq == nullptr) {
                    NodoBST* nuevo = new NodoBST(repeticion);
                    nuevo -> ips.push_back(ip);
                    current -> izq = nuevo;
                    return;
                } 
                else {
                    current = current -> izq;
                }
            } 
            else {
                if (current -> der == nullptr) {
                    NodoBST* nuevo = new NodoBST(repeticion);
                    nuevo -> ips.push_back(ip);
                    current -> der = nuevo;
                    return;
                } 
                else {
                    current = current -> der;
                }
            }
        }
    }
}

void BST::imprimir_ips() {
    int numero_ips = 5; // Número máximo de IPs que se desea imprimir (las más frecuentes)
    int contador = 0;   // Contador de IPs impresas hasta el momento
    NodoBST* current = root;
    stack<NodoBST*> pila;

    while (!pila.empty() || current != nullptr) {
        while (current != nullptr) {
            pila.push(current);
            current = current->der;
        }

        current = pila.top();
        pila.pop();

        for (string ip : current->ips) {
            if (contador >= numero_ips) return;
            cout << contador + 1 << ". IP: " << ip << ", Frecuencia: " << current->repeticion << endl;
            contador++;
        }
        
        current = current->izq;
    }
}