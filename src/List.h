#pragma once
#include "NodeAdj.h"
#include "NodeGraph.h"
#include <cstdlib>
#include <iostream>
using std::cout;
template <typename T> class List {
    T *pList;

  public:
    List() {
        // inicializar el apuntador en nullo
        pList = nullptr;
    }
    T *find(int elm) {
        T *p;
        while (p != 0 && (p->value != elm)) {
            p = p->next;
        }
        if (p == 0) {
            return nullptr;
        }
        // no es nulo --> encontro el elemento
        return p;
    }
    void insertarInicio(int x) {
        // variable auxiliar
        T *p;
        p = (T *)malloc(sizeof(T));
        // asignar valor al nodo
        p->value = x;
        // linkear nodo a la lista
        p->next = pList;
        pList = p;
    }
    void insertarFinal(int x) {
        // si esta vacio no podemos acceder a p->next->next
        // nos da un error
        if (listaVacia()) {
            // por si es el primer elemento
            insertarInicio(x);
        } else {
            T *p = pList;
            // avanzar al siguiente nodo mientras no sea el ultimo
            while (p->next != 0) {
                p = p->next;
            }
            // encontrando el ultimo nodo
            // obtenemos espacio para el siguiente nodo
            p->next = (T *)malloc(sizeof(T));
            // ultimo elemento apunta a nulo
            p->next->next = 0;
            // asignar el valor del ultimo elemento
            p->next->value = x;
        }
    }
    void imprimir() {
        T *p = pList;
        // recorrer cada nodo mientras no apuntemos a nulo
        while (p != 0) {
            // imprimir el valor del i-esimo nodo
            std::cout << p->value << ", ";
            // pasar al siguiente nodo
            p = p->next;
        }
        // imprimir enter final
        std::cout << "\n";
    }
    void imprimirAdj(int elm) {
        T *p = find(elm);
        // recorrer cada nodo mientras no apuntemos a nulo
        cout <<"Nodos adyacentes a "<<elm<<" son:\n";
        while (p != 0) {
            // imprimir el valor del i-esimo nodo
            std::cout << p->value << ", ";
            // pasar al siguiente nodo
            p = p->next;
        }
        // imprimir enter final
        std::cout << "\n";
    }
    void eliminarPrimero() {
        if (listaVacia()) {
            // verificar si esta vacia
            std::cout << "No hay elementos.\n";
        } else {
            T *p = pList;
            // apuntar al siguiente elemento
            pList = pList->next;
            // eliminar el primer elemento
            free(p);
        }
    }
    void eliminarUltimo() {
        T *p = pList;
        // si esta vacio no podemos acceder a p->next->next
        // nos da un error
        if (listaVacia()) {
            // si esta vacia mandar mensaje
            std::cout << "No hay elementos.\n";
        } else if (p->next == 0) {
            free(p);
            pList = 0;
        } else {
            // iterar hasta llegar al penultimo nodo
            while (p->next->next != 0) {
                // siguiente nodo
                p = p->next;
            }
            // liberar el ultimo nodo
            free(p->next);
            // ultimo nodo apuntando a null
            p->next = 0;
        }
    }
    bool listaVacia() {
        // lista no tiene elementos si apunta a nullo
        return pList == 0;
    }

    bool isAdj(int elmA, int elm) {
        T *p = pList;
        // recorrer cada nodo mientras no apuntemos a nulo o encontremos elmA
        while (p != 0 && (p->value != elmA)) {
            // pasar al siguiente nodo
            p = p->next;
        }
        if (p == 0) {
            return false;
        }
        // verificar si el nodo del grafo es adjacente a elm
        return p->isAdj(elm);
    }
    void addAdjacency(int elmA, int elm) {
        T *p = find(elmA);
        if (p == 0) {
            cout << "Nodo " << elmA << " no encontrado\n";
        } else {
            addEndAdj(p, elm);
        }
    }
    void addEndAdj(T *nodoGrafo, int elm) {
        NodeAdj *p = nodoGrafo->adj;
        NodeAdj *nuevoAdj = (NodeAdj *)malloc(sizeof(NodeAdj));
        nuevoAdj->value = elm;
        if (p == 0) {
            p = nuevoAdj;
        } else {
            while (p->next != 0) {
                p = p->next;
            }
            p->next = nuevoAdj;
        }
    }
};
