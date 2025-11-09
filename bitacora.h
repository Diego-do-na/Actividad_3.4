#pragma once
#include <vector>
#include <string>
#include "BST.h"
#include "LInkedList.h"
using namespace std;

class Bitacora {
    private:
        int contadorBusqueda = 1;
        LinkedList lista_ips;
        LinkedList lista_ordenada;
        BST arbol_frecuencia;
    public:
        // Métodos de la clase Bitacora
        bitacora(vector<string> l);
        void crear_archivo(const LinkedList& lista, int option);

        // Métodos de las Linked Lists
        bool ipMenoroIgual(vector<int> a, vector<int> b);
        bool ipMayoroIgual(vector<int> a, vector<int> b);
        LinkedList merge(nodo* izq, nodo* der);
        LinkedList mergeSort(const LinkedList& lista);
        void ordenar_ll();

        // Métodos del BST
        void crear_bst();
};