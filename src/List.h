#pragma once
#include "NodeAdj.h"
#include "NodeGraph.h"
#include <cstdlib>
#include <iostream>
class List {
    NodeGraph *pList;

    void insertarInicio(int x);
    void insertarFinal(int x);
    void eliminarPrimero();
    void eliminarUltimo();
    bool listaVacia();

  public:
    List();

    void imprimirAdj(int elm);
    void imprimir();
    void insertarNodo(int x);
    bool isAdj(int elmA, int elm);
    void addAdjacency(int elmA, int elm);
    void addAdj(NodeGraph *nodoGrafo, int elm);
    /* void addEndAdj(NodeGraph *nodoGrafo, int elm); */
};
