#pragma once
#include "NodeAdj.h"
#include "NodeGraph.h"
#include <cstdlib>
#include <iostream>
class Graph {
    NodeGraph *pList; //Delcaramos un nuevo puntero llamado pList
    
	//Esta funcion inserta un elemento al inicio enviado un entero
    void insertarInicio(int x);
    
    //Esta funcion inserta un elemento al final enviado un entero
    void insertarFinal(int x);
    
    //Esta funcion elimina el primer elemento 
    void eliminarPrimero();
    
    //Esta funcion elimina el primer elemento 
    void eliminarUltimo();
    
    //Esta funcion nos devuelve un valor ya sea 1 o 0 dado se cumpla esta
    bool listaVacia();
    
    //Con esta funcion se realizara el recorrido por Ancho
    void printWidthPath(NodeGraph *inicio);
    
    //Esta funcion marca como visitado el puntero enviado de los adyacentes
    void marcarVisitado(NodeAdj *p);
    
    //Esta funcion marca como visitado el puntero enviado de la lista de los nodos
    void marcarVisitado(NodeGraph *p);
    
    //Marca como visitado el elemento que se el envio
    void marcarVisitado(int elm);
    
    //Nos devuelve un 1 o 0 si el elemento a sido visitado
    bool isVisited(int elm);
    
    //Nos devuelve un 1 o 0 si el puntero adyacente ha sido visitado o no
    bool isVisited(NodeAdj *p);
    
    //Nos devuelve un 1 o 0 si el puntero de los nodos ha sido visitado o no
    bool isVisited(NodeGraph *p);
    
    //Con esta funcion restauramos los campos de visitado cuando terminamos algun recorrido
    void restoreVisited();
    
    //Con esta funcion realizamos el recorrido por profundidad
    void printDepthPath(NodeGraph *p);
    
    //Esta funcion es recursiva y se utiliza con el uso de el recorrido por profunidad
    void bpp(NodeGraph *p);

  public:
    Graph();
    
	//Esta funcion imprime los nodos adyacentes, dado un elemento
    void imprimirAdj(int elm);
    
    //Esta funcion es utilizada para imprimir los nodos
    void imprimir();
    
    //Esta funcion inserta un nuevo nodo
    void insertarNodo(int x);
    
    //Esta funcion nos devuelve un 1 o 0 si el elmA es adyacente con el elm enviados
    bool isAdj(int elmA, int elm);
    
    //Esta funcion es para a�adir adyacencia con el elemA y el elm enviados
    void addAdjacency(int elmA, int elm, int peso);
    
    //A�adimos un nodo adyacente
    void addAdj(NodeGraph *nodoGrafo, int elm, int peso);
    
    // imprime el camino a lo ancho iniciando en elm
    void pathWidth(int elm);
    
    // imprime el camino a lo ancho iniciando en elmInicial
    void pathDepth(int elmInicial);
    void TREEPRIM(int i);
};
