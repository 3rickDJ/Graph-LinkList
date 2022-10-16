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
    void printWidthPath(NodeGraph *inicio);
    void marcarVisitado(NodeAdj *p);
    void marcarVisitado(NodeGraph *p);
    void marcarVisitado(int elm);
    bool isVisited(int elm);
    bool isVisited(NodeAdj *p);
    bool isVisited(NodeGraph *p);

  public:
    List();

    void imprimirAdj(int elm);
    void imprimir();
    void insertarNodo(int x);
    bool isAdj(int elmA, int elm);
    void addAdjacency(int elmA, int elm);
    void addAdj(NodeGraph *nodoGrafo, int elm);
    // imprime el camino a lo ancho iniciando en elm
    void pathWidth(int elm);
};
