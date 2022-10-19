#pragma once
#include "NodeAdj.h"

class NodeGraph {
  public:
    int value;  //Este valor es ocupado para guardar los valores que tendra el nodo
    int visited;	//Este sera un campo donde se actualizara a 1 o 0 si es que ya fue visitado cuando se realice los recorridos
    NodeAdj *adj;	//Este puntero es necesario para determinar el campo donde se agregaran los nodos de tipo 2 que seran los adyacentes en este
    NodeGraph *next;	//Este marcara el siguiente nodo que se relacionara 
    // initializer
    NodeGraph();
    // Sera verdadero su el elemento esta en adyacente, de otra manera sería falso
    bool isAdj(int elm);
    // Imprime la lista de adyacencia
    void printAdj();
    //En este nodo mandaremos dos datos, el puntero de "inicio" (o el cual iniciara el recorrido) y el elemento que queremos encontrar en la lista
    static NodeGraph *find(NodeGraph *inicio, int elm);
    //Este sera para im´primir la lista desde el puntero "inicio"
    static void printList(NodeGraph *inicio);
};
