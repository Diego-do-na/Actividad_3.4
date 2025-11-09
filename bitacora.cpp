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
            } else if (ch == ':') {
                ip_vector.push_back(stoi(temp));
                temp.clear();
                break;
            } else {
                temp += ch;
            }
        }

        if (!temp.empty()) {
            ip_vector.push_back(stoi(temp));
        }

        ip_vector.push_back(c);

        if (c == 0) lista_ips.insertFirst(ip_vector);
        else lista_ips.insertLast(ip_vector);
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
    } else {
        cout << "No se pudo crear el archivo." << endl;
    }
}

// Ordenar la LinkedList
void Bitacora::ordenar_ll() {
    lista_ordenada = mergeSort(lista_ips);
    crear_archivo(lista_ordenada);
}

// MergeSort de la LinkedList
LinkedList Bitacora::merge(nodo* izq, nodo* der) {
    LinkedList resultado;
    while (izq != nullptr && der != nullptr) {
        if (ipMenoroIgual(izq->ip, der->ip)) {
            resultado.insertLast(izq->ip);
            izq = izq->next;
        } else {
            resultado.insertLast(der->ip);
            der = der->next;
        }
    }

    while (izq != nullptr) {
        resultado.insertLast(izq->ip);
        izq = izq->next;
    }
    while (der != nullptr) {
        resultado.insertLast(der->ip);
        der = der->next;
    }
    return resultado;
}

LinkedList Bitacora::mergeSort(const LinkedList& lista) {
    nodo* head = lista.head;
    if (head == nullptr || head->next == nullptr) return lista;

    nodo* slow = head;
    nodo* fast = head->next;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    nodo* mid = slow->next;
    slow->next = nullptr;

    LinkedList left, right;
    left.insertFirst(head->ip);
    right.insertFirst(mid->ip);

    LinkedList izq_ordenada = mergeSort(left);
    LinkedList der_ordenada = mergeSort(right);

    return merge(izq_ordenada.getHead(), der_ordenada.getHead());
}

bool Bitacora::ipMenoroIgual(vector<int> a, vector<int> b) {
    for (int i = 0; i < 4; i++) {
        if (a[i] < b[i]) return true;
        if (a[i] > b[i]) return false;
    }
    return true;
}

bool Bitacora::ipMayoroIgual(vector<int> a, vector<int> b) {
    for (int i = 0; i < 4; i++) {
        if (a[i] > b[i]) return true;
        if (a[i] < b[i]) return false;
    }
    return true;
}

// Crear el árbol de frecuencias
void Bitacora::crear_bst() {
    nodo* current = lista_ordenada.getHead();
    while (current != nullptr) {
        if (current->next != nullptr && current->ip == current->next->ip) {
            contadorBusqueda++;
            current = current->next;
        } else {
            ip_str = to_string(current->ip[0]) + "." + to_string(current->ip[1]) + "." +
                     to_string(current->ip[2]) + "." + to_string(current->ip[3]);
            arbol_frecuencia.insertar(ip_str, contadorBusqueda);
            contadorBusqueda = 1;
            current = current->next;
        }
    }
}

void Bitacora::imprimir_ips() {
    arbol_frecuencia.imprimir_ips();
}