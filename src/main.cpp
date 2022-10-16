// incluir header de la clase List
#include "List.h"
#include "NodeGraph.h"
#include "iostream"
using std::cin;
using std::cout;
using std::endl;
int main() {
    int opt, elm, elmA;
    List lista;
    do {
        cout << "=============================================================="
                "=================="
             << endl;
        cout << "                                     MENU                     "
                "                  "
             << endl;
        cout << "=============================================================="
                "=================="
             << endl;
        cout << " 1. Insertar nodo" << endl;
        cout << " 2. Añadir adjacencia " << endl;
        cout << " 3. Son adjacentes" << endl;
        cout << " 4. Mostrar nodos" << endl;
        cout << " 5. Mostrar adjacencia (dado un nodo)" << endl;
        cout << " 6. Recorrido a lo ancho" << endl;
        cout << " 7. Salir" << endl;
        cout << " Ingrese una opcion: ";
        cin >> opt;
        cout << endl;

        // Mostrar opciones
        switch (opt) {
        case 1:
            // preguntar Elemento a insertar
            cout << "Elemento a insertar: ";
            cin >> elm;
            lista.insertarNodo(elm);
            break;
        case 2:
            // Añadir adjacencia
            cout << "Elemento a: \n";
            cin >> elmA;
            cout << "Elemento b: \n";
            cin >> elm;
            lista.addAdjacency(elmA, elm);
            break;
        case 3:
            // preguntar por adjacencia
            cout << "Elemento a: ";
            cin >> elmA;
            cout << "Elemento b: ";
            cin >> elm;
            if (lista.isAdj(elmA, elm)) {
                cout << "Elemento a=" << elmA << " SI es adyacente a b=" << elm
                     << "\n";
            } else {
                cout << "Elemento a=" << elmA << " NO es adyacente a b=" << elm
                     << "\n";
            }
            break;
        case 4:
            // mostrar nodos
            lista.imprimir();
            break;
        case 5:
            // mostarAdjacencia
            cout << "Nodo a: ";
            cin >> elmA;
            lista.imprimirAdj(elmA);
            break;
        case 6:
            //Recorrido a lo ancho
            cout << "Nodo inicial a: ";
            cin >> elmA;
            lista.pathWidth(elmA);
            break;
        case 7:
            break;
        default:
            opt = 7;
            cout << "Opcion no valida.\nSaliendo\n";
        }
    } while (opt != 7);
}
