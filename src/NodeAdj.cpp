#include "NodeAdj.h"
#include <iostream>
using std::cout;

NodeAdj::NodeAdj() {
    value = 0;
    next = nullptr;
}
NodeAdj *NodeAdj::find(NodeAdj *inicio, int elm) {
    NodeAdj *p = inicio;
    while (p != nullptr) {
        if (p->value == elm) {
            return p;
        }
        p = p->next;
    }
    return p;
}

// imprime la lista ligada a inicio (tipo NodeAdj)
void NodeAdj::printList(NodeAdj *inicio) {
    NodeAdj *p = inicio;
    if (p == nullptr) {
        cout << "No hay datos en la lista";
    } else {
        while (p != nullptr) {
            std::cout << "[" << p->value << "] ->";
            p = p->next;
        }
        std::cout << "\n";
    }
}
