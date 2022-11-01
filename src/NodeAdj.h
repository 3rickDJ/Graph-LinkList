#pragma once

class NodeAdj {
  public:
    int value; //Con esto guardamos un valor 
    NodeAdj *next; //Con esto podremos apuntar al siguiente nodo
    int weight;
    // initializer
    NodeAdj(); 
    //Esta funcion es para encontrar si habra adyacencia con el nodo (puntero) enviado y el elemento solicitado
    static NodeAdj *find(NodeAdj *inicio, int elm);
    //Esta funcion es para imprimir la lista de adyacencia dado un nodo
    static void printList(NodeAdj *inicio);
};
