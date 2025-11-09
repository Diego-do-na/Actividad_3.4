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
        // Constructor
        Bitacora(vector<string> l);

        // Métodos principales
        void crear_archivo(const LinkedList& lista);
        void imprimir_ips();

        // Métodos auxiliares de LinkedList
        bool ipMenoroIgual(vector<int> a, vector<int> b);
        bool ipMayoroIgual(vector<int> a, vector<int> b);
        LinkedList merge(nodo* izq, nodo* der);
        LinkedList mergeSort(const LinkedList& lista);
        void ordenar_ll();

        // Métodos del BST
        void crear_bst();
};