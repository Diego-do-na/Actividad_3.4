#include "bitacora.h"

bitacora::bitacora(vector<string> l) {
    lineas_iniciales = l;

    for (int c = 0; c < l.size(); ++c) {
        string linea = l[c];
        string ip_string = linea.substr(15, linea.find(" ", 16) - 16);
        vector<int> ip_vector;
        string temp;

        for (char ch : ip_string) {
            if (ch == '.' || ch == ':') {
                ip_vector.push_back(stoi(temp));
                temp.clear();
            } else {
                temp += ch;
            }
        }

        if (!temp.empty()) {
            ip_vector.push_back(stoi(temp));
        }

        ip_vector.push_back(c);

        if (c == 0) {
            lista_ips.insertFirst(ip_vector);
        } else {
            lista_ips.insertLast(ip_vector);
        }
    }
}