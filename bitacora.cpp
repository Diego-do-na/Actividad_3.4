#include <fstream>
#include <iostream>
#include "Bitacora.h"
using namespace std;

// Constructor
Bitacora::Bitacora(vector<string> l) {
    lineas_iniciales = l;
    for (int c = 0; c < l.size(); ++c) {
        string linea = l[c];
        string ip_string = linea.substr(15, linea.find(" ", 16) - 16);

        vector<int> ip_vector;
        string temp;

        for (char ch : ip_string) {
            if (ch == '.') {
                ip_vector.push_back(stoi(temp));
                temp.clear();
            } 
            else if (ch == ':') {
                ip_vector.push_back(stoi(temp));
                temp.clear();
                break;
            } 
            else {
                temp += ch;
            }
        }

        if (!temp.empty()) {
            ip_vector.push_back(stoi(temp));
        }

        ip_vector.push_back(c);
        lista_ips.insertLast(ip_vector);
    }
}

// Crear archivo
void Bitacora::crear_archivo(const LinkedList& lista) {
    string nombre_archivo = "bitacoraOrdenada.txt";
    ofstream archivo(nombre_archivo);
    if (archivo.is_open()) {
        nodo* current = lista.head;
        while (current != nullptr) {
            vector<int> ip = current->ip;
            archivo << lineas_iniciales[ip[4]] << endl;
            current = current->next;
        }
        archivo.close();
    } 
    else {
        cout << "No se pudo crear el archivo." << endl;
    }
}

// Ordenar la LinkedList
void Bitacora::ordenar_ll() {
    lista_ordenada.head = mergeSort(lista_ips.head, lista_ips.size);
    lista_ordenada.size = lista_ips.size;
    lista_ordenada.tail = lista_ordenada.head;
    if (lista_ordenada.tail) {
        while (lista_ordenada.tail->next) {
            lista_ordenada.tail = lista_ordenada.tail->next;
        }
    }
    crear_archivo(lista_ordenada);
}

bool Bitacora::comparar_nodo(nodo* a, nodo* b) {
    for (int i = 0; i < 4; i++) {
        if (a->ip[i] < b->ip[i]) {
            return true;
        }
        if (a->ip[i] > b->ip[i]) {
            return false;
        }
    }
    return a->ip[4] <= b->ip[4];
}

// MergeSort de la LinkedList
nodo* Bitacora::merge(nodo* izq, nodo* der) {
    if (!izq) return der;
    if (!der) return izq;

    nodo* head = nullptr;
    nodo* tail = nullptr;

    while (izq && der) {
        nodo* siguiente;
        if (comparar_nodo(izq, der)) {
            siguiente = izq;
            izq = izq->next;
        } else {
            siguiente = der;
            der = der->next;
        }

        if (!head) {
            head = siguiente;
            tail = siguiente;
        } else {
            tail->next = siguiente;
            tail = siguiente;
        }
    }

    if (izq) {
        if (!tail) head = izq;
        else tail->next = izq;
    } else if (der) {
        if (!tail) head = der;
        else tail->next = der;
    }

    return head;
}

nodo* Bitacora::mergeSort(nodo* head, int size) {
    if (size <= 1) return head;

    int mitad = size / 2;
    nodo* temp = head;
    for (int i = 1; i < mitad; i++) {
        temp = temp->next;
    }

    nodo* mid = temp->next;
    temp->next = nullptr;

    nodo* izq = mergeSort(head, mitad);
    nodo* der = mergeSort(mid, size - mitad);

    return merge(izq, der);
}

// Crear el árbol de frecuencias
void Bitacora::crear_bst() {
    nodo* current = lista_ordenada.head;
    while (current != nullptr) {
        if (current->next != nullptr && comparar_ip(current->ip, current->next->ip)) {
            contadorBusqueda++;
            current = current->next;
        } else {
            ip_str = to_string(current->ip[0]) + "." + to_string(current->ip[1]) + "." + to_string(current->ip[2]) + "." + to_string(current->ip[3]);
            arbol_frecuencia.insertar(ip_str, contadorBusqueda);
            contadorBusqueda = 1;
            current = current->next;
        }
    }
}

bool Bitacora::comparar_ip(vector<int> a, vector<int> b) {
    for (int i = 0; i < 4; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

void Bitacora::imprimir_ips() {
    arbol_frecuencia.imprimir_ips();
}