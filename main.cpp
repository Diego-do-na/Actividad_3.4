#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Bitacora.h"
using namespace std;

int main() {
    vector<string> lineas;
    string linea;
    ifstream archivoEntrada("bitacora.txt");

    if (!archivoEntrada.is_open()) {
        cout << "No se pudo abrir el archivo bitacora.txt" << endl;
        return 1;
    }

    while (getline(archivoEntrada, linea)) {
        lineas.push_back(linea);
    }
    archivoEntrada.close();

    Bitacora b(lineas);

    cout << "----------------------------------" << endl;
    cout << "Bitácora ordenada e inserción en BST" << endl;
    cout << "----------------------------------" << endl;

    cout << "\nOrdenando IPs..." << endl;
    b.ordenar_ll();

    cout << "Creando árbol de frecuencias..." << endl;
    b.crear_bst();

    cout << "\nLas IPs más buscadas son:\n" << endl;
    b.imprimir_ips();

    cout << "\nProceso completado exitosamente." << endl;
    return 0;
}