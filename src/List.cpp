#include "List.h"
#include "ADTQueue.h"
#include "NodeAdj.h"
#include "NodeGraph.h"
#include <iostream>
using std::cout;
using std::endl;
List::List() {
    // inicializar el apuntador en nullo
    pList = nullptr;
}
void List::insertarNodo(int x) {
    if (NodeGraph::find(pList, x) == nullptr) {
        // variable auxiliar
        NodeGraph *p = new NodeGraph();
        // asignar valor al nodo
        p->value = x;
        // linkear nodo a la lista
        p->next = pList;
        pList = p;
    } else {
        cout << "Elemento repetido\n";
    }
}
void List::imprimir() { NodeGraph::printList(pList); }
void List::imprimirAdj(int elm) {
    NodeGraph *p = NodeGraph::find(pList, elm);
    if (p == nullptr) {
        cout << "Nodo no encontrado\n";
    } else {
        cout << "[" << elm << "]\n |\n V\n";
        NodeAdj::printList(p->adj);
    }
}
bool List::listaVacia() {
    // lista no tiene elementos si apunta a nullo
    return pList == nullptr;
}

bool List::isAdj(int elmA, int elm) {
    NodeGraph *p = NodeGraph::find(pList, elmA);
    // verificar si el nodo del grafo es adjacente a elm
    return p->isAdj(elm);
}
void List::addAdjacency(int elmA, int elm) {
    NodeGraph *p = NodeGraph::find(pList, elmA);
    // se encontro nodo elmA en nodoGrafo
    if (p == nullptr) {
        cout << "Nodo " << elmA << " no encontrado\n";
        // se encontro nodo elm en list adyacencia
    } else if (NodeAdj::find(p->adj, elm) != nullptr) {
        cout << "Elemento " << elm << " ya se encuentra registrado\n";
        // no se encontro elm en lista de nodoGrafo
    } else if (NodeGraph::find(pList, elm) == nullptr) {
        cout << "Elemento " << elm << " no es un nodo (agregalo)\n";
    } else {
        // si es un Nodo en grafo y no ha sido registrado -> crear nodo
        addAdj(p, elm);
    }
}
void List::addAdj(NodeGraph *nodoGrafo, int elm) {
    NodeAdj *nuevoNodo = new NodeAdj();
    nuevoNodo->value = elm;
    if (nodoGrafo->adj == nullptr) {
        nodoGrafo->adj = nuevoNodo;
    } else {
        NodeAdj *iterator = nodoGrafo->adj;
        while (iterator->next != nullptr) {
            iterator = iterator->next;
        }
        iterator->next = nuevoNodo;
    }
}
void List::pathWidth(int elm) {

    NodeGraph *p = NodeGraph::find(pList, elm);
    if (p == nullptr) {
        cout << "El nodo " << elm << " no esta registrado\n";
    } else {
        printWidthPath(p);
    }
}

void List::printWidthPath(NodeGraph *p) {
    Queue cola;
    NodeGraph *aux = p;
    NodeGraph x;
    /* NodeAdj *y; */
    marcarVisitado(p);
    int valor2;
    int valor = p->value;
    cola.encolar(valor);
    while (cola.primero() != 0) {
        valor = cola.desencolar();
        cout << "[" << valor << "] - ";
        // para cada nodo adyacente a x
        // ubicar nodo
        aux = NodeGraph::find(pList, valor);
        NodeAdj *iterator = aux->adj;
        while (iterator != nullptr) {
            valor2 = iterator->value;
            if (!isVisited(valor2)) {
                marcarVisitado(valor2);
                cola.encolar(valor2);
            }
            iterator = iterator->next;
        }
    }
    cout << "\n\n";
}
void List::marcarVisitado(NodeAdj *p) {
    NodeGraph::find(pList, p->value)->visited = 1;
}
bool List::isVisited(NodeAdj *p) {
    return NodeGraph::find(pList, p->value)->visited == 1;
}
void List::marcarVisitado(NodeGraph *p) { p->visited = 1; }
bool List::isVisited(NodeGraph *p) { return p->visited == 1; }
void List::marcarVisitado(int elm){
    NodeGraph::find(pList,elm)->visited=1;
}
bool List::isVisited(int elm){
    return NodeGraph::find(pList,elm)->visited==1;
}
