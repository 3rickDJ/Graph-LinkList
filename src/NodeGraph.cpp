#include "NodeGraph.h"
#include <iostream>

using namespace std;

NodeGraph::NodeGraph() {
    // set null by default
    value = 0;
    visited = 0;
    adj = nullptr;
    next = nullptr;
}
void NodeGraph::printAdj() {
    NodeAdj *p = adj;
    // recorrer cada nodo mientras no apuntemos a nulo
    while (p != 0) {
        // imprimir el valor del i-esimo nodo
        std::cout << " |" << p->value;
        // pasar al siguiente nodo
        p = p->next;
    }
    // imprimir enter final
    if (p == 0) {
        cout << " Lista de adjacencia vacia\n";
    } else {
        // imprimir salto de line del while
        cout << "|\n";
    }
}
bool NodeGraph::isAdj(int elm) {
    // buscar si esta el elemento elm, en adj y retornar el resultado
    NodeAdj *p = adj;
    while (p != 0) {
        //si se encuentra se corta la iteracion
        if (p->value == elm) {
            return true;
        }
        p = p->next;
    }
    //se recorrio la lista entera sin coincidencias
    return false;
}
