#include "NodeGraph.h"
#include <climits>
#include <iostream>

using namespace std;

NodeGraph::NodeGraph() {
    // Todos los valores sera 0 o NULL
    value = 0;
    visited = 0;
    adj = nullptr;
    next = nullptr;
    leastWeight = INT_MAX;
    leastNode = -1;

}
//Dentro de la funcion llamamos a la otra funcion enviando el puntero adj
void NodeGraph::printAdj() { NodeAdj::printList(adj); }

// retorna true si tiene adyacencia, falso de otra forma
bool NodeGraph::isAdj(int elm) {
    // buscar elm en adj
    return NodeAdj::find(adj, elm) != nullptr;
}

//Dado el nodo que se le envio y el elemento, se buscara en la lista de la siguiente manera
NodeGraph *NodeGraph::find(NodeGraph *inicio, int elm) {
    //Definimos un puntero p, que sera igual al "inicio" que le mandamos
    NodeGraph *p = inicio;
    //Mientras sea diferente de NULLPTR
    while (p != nullptr) {
    	//Si el valor en el campo donde apunta p->value es igual al elem enviado 
        if (p->value == elm) {
            //Nos regresa p
            return p;
        }
        //Recorremos la lista
        p = p->next;
    }
    //Si no lo encuentra nos regresara p como NULL
    return p;
}

//Se le envia un puntero "inicio" para empezar a imprimir los datos desde ese valor
void NodeGraph::printList(NodeGraph *inicio) {
	//Definimos a un puntero donde sea igual al enviado
    NodeGraph *p = inicio;
    //Si el puntero es igual a NULLPTR
    if (p == nullptr) {
        cout << "No hay datos en la lista";
    }//De otra manera 
	 else {
	 	//Mientras sea diferente de NULLPTR
        while (p != nullptr) {
            std::cout << "[" << p->value << "] ->"; //Imprimiremos el valor que existe en el puntero en el campo value
            p = p->next; //Y recorremos al siguiente nodo hasta terminar la condicion de la linea 49
        }
        std::cout << "\n";
    }
}
