#include "NodeAdj.h"
#include <climits>
#include <iostream>
using std::cout;

NodeAdj::NodeAdj() {
	//Inicializamos valor en 0
    value = 0;
    //Ahora tambien el puntero next igual NULLPTR
    next = nullptr;
    weight = INT_MAX;

}

//Ahora dado un nodo y un elemento encontraremos la adyacencia
NodeAdj *NodeAdj::find(NodeAdj *inicio, int elm) {
	//Definimos un puntero con el valor de "inicio"
    NodeAdj *p = inicio;
    //Mientras que nuestro puntero p sea diferente de nullptr
    while (p != nullptr) {
    	//Si en el campo value de p es igual al elemento enviado
        if (p->value == elm) {
        	//regresamos ese p
            return p;
        }
        //Recorremos la lista 
        p = p->next;
    }
    //Si no lo encontro p tomara el valor de null
    return p;
}

// imprime la lista ligada a inicio (tipo NodeAdj)
void NodeAdj::printList(NodeAdj *inicio) {
	//Deinifimos nuestro nodo con el valor de "inicio"
    NodeAdj *p = inicio;
    //Si nuestro puntero p es igual a nullptr
    if (p == nullptr) {
    	//No hay datos
        cout << "No hay datos en la lista";
    } else {
    	//Mientras sea diferente de nullptr
        while (p != nullptr) {
        	//Imprimimos el valor que existe en el campo value de p
            std::cout << "[" << p->value << "] ->";
            //Recorremos la lista para que en algun punto se rompa el ciclo
            p = p->next;
        }
        std::cout << "\n";
    }
}
