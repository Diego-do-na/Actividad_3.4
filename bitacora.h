#pragma once
#include <vector>
#include <string>
#include "BST.h"
#include "LinkedList.h"
using namespace std;

class Bitacora {
    private:
        int contadorBusqueda = 1;
        string ip_str;
        vector<string> lineas_iniciales;
        LinkedList lista_ips;
        LinkedList lista_ordenada;
        BST arbol_frecuencia;
    public:
        // Métodos principales
        Bitacora(vector<string> l);
        void crear_archivo(const LinkedList& lista);
        void imprimir_ips();

        // Métodos de la linked list
        nodo* merge(nodo* izq, nodo* der);
        nodo* mergeSort(nodo* head, int size);
        bool comparar_nodo(nodo* a, nodo* b);
        void ordenar_ll();

        // Métodos del BST
        void crear_bst();
        bool comparar_ip(vector<int> a, vector<int> b);
};