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
        //Y hacemos que PList sea igual a p
        pList = p;
    } else {
        cout << "Elemento repetido\n";
    }
}

//Mandamos a llamar la funcion de NodeGraph con el/los valores que tiene pList
void List::imprimir() { NodeGraph::printList(pList); }
//Ahora imprimimos la adjacencia con el elemento
void List::imprimirAdj(int elm) {
	//Definimos un puntero donde este sea igual al valor que nos devuelve la funcion NodeGraph con pList y el elm
    NodeGraph *p = NodeGraph::find(pList, elm);
    //Si este es igual a nullptr 
    if (p == nullptr) {
    	//Quiere decir que el nodo no existe 
        cout << "Nodo no encontrado\n";
    } //De otro modo
		else {
    	//Imprimimos el elemento 
        cout << "[" << elm << "]\n |\n V\n";
        //Y ahora imprimimos la lista con el valor de p en su campo adj
        NodeAdj::printList(p->adj);
    }
}

//Esto nos de vuelve 1 o 0(nullptr)
bool List::listaVacia() {
    // Si lista no tiene elementos quiere decir que apunta a nullo
    return pList == nullptr;
}

bool List::isAdj(int elmA, int elm) {
	//Definimos un puntero con el valor que devuelve la funcion dado pList y el elmA
    NodeGraph *p = NodeGraph::find(pList, elmA);
    // verificar si el nodo del grafo es adjacente a elm
    return p->isAdj(elm);
}

//Esta funcion añade una adyacencia
void List::addAdjacency(int elmA, int elm) {
	//Definimos un puntero con el valor que devuelve la funcion dado pList y elmA
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

//Añadimos un nodo adyacente
void List::addAdj(NodeGraph *nodoGrafo, int elm) {
	//Creamos un puntero con el valor de NodeAdj es decir un nuevo nodo de dos valores
    NodeAdj *nuevoNodo = new NodeAdj();
    //En su campo value ponemos el elemento
    nuevoNodo->value = elm;
    //Si en el nodoGrafo en su campo adj es igual a null quiere decir que no hay elementos por lo que 
    if (nodoGrafo->adj == nullptr) {
    	//Es el primero que se le añade 
        nodoGrafo->adj = nuevoNodo;
    } //Por lo menos tiene un dato
		else {
		//Creamos un apuntador iterador con el valor que tiene nodoGrafo en su campo adj
        NodeAdj *iterator = nodoGrafo->adj;
        //Mientras iterador en su campo siguiente sea diferente de nullptr
        while (iterator->next != nullptr) {
        	//Recorremos la lista (iterador)
            iterator = iterator->next;
        }
        //En el campo next añadimos el nuevoNodo
        iterator->next = nuevoNodo;
    }
}

void List::pathWidth(int elm) {
	//Creamos un puntero con el valor de la funcion NodeGraph con los valores de pList y elm
    NodeGraph *p = NodeGraph::find(pList, elm);
    //Si p es igual nullptr
    if (p == nullptr) {
    	//No hay elementos
        cout << "El nodo " << elm << " no esta registrado\n";
    } else {
    	//Mandamos a llamar a la funcion con el puntero p
        printWidthPath(p);
    }
}

void List::printWidthPath(NodeGraph *p) {
	//Definimos como llamaremos a la clase para sus funciones 
    Queue cola;
    NodeGraph *aux = p; //Un puntero aux con el valor de p
    marcarVisitado(p); //Mandamos a llamar a la funcion para que se marque como visitado a p
    int valor2; 		//Declaramos un valor2 que sera utilizado para guardar los valores en el ciclo
    int valor = p->value;	//La variable valor va a tener el elemento que tiene p en su campo value 
    cola.encolar(valor);	//mandamos a llamar a la funcion encolar de cola
    //Mientras el primer valor dee cola tenga datos
	while (cola.primero() != 0) {
		//El valor lo sacamos de la cola mandando a llamar a la funcion desencolar
        valor = cola.desencolar();
        //Imprimimos el valor
        cout << "[" << valor << "] - ";
        // para cada nodo adyacente a x
        // ubicar nodo
        aux = NodeGraph::find(pList, valor);
        NodeAdj *iterator = aux->adj;	//Definimos un nuevo apuntador con el valor de aux en su campo adj
        //Mientras tenga datos
		while (iterator != nullptr) {
			//Valor2 se le asignara lo que tiene iterador en su campo valor
            valor2 = iterator->value;
            //Si valor2 no a sido visitado
            if (!isVisited(valor2)) {
            	//Lo marcamos como visitado
                marcarVisitado(valor2);
                //Lo ponemos en la cola
                cola.encolar(valor2);
            }
            //Recorremos la lista
            iterator = iterator->next;
        }
    }
    cout << "\n\n";
    //Restauramos los campos de visitado para un nuevo recorrido
    restoreVisited();
}

//Dado un puntero marcamos como visitado en su campo visited
void List::marcarVisitado(NodeAdj *p) {
    NodeGraph::find(pList, p->value)->visited = 1;
}
//Aqui comprobamos si esta visitado ese puntero
bool List::isVisited(NodeAdj *p) {
    return NodeGraph::find(pList, p->value)->visited == 1;
}
void List::marcarVisitado(NodeGraph *p) { p->visited = 1; } //Marcamos el nodo como visitado
bool List::isVisited(NodeGraph *p) { return p->visited == 1; } //Si se cumple que el campo de p es igual a 1 se regresa true
void List::marcarVisitado(int elm) { NodeGraph::find(pList, elm)->visited = 1; } //Marcamos como visitado el elm
bool List::isVisited(int elm) {  return NodeGraph::find(pList, elm)->visited == 1;} //Verficamos si el elm esta visitado

//Restauramos los campos de visitados a 0
void List::restoreVisited() {
	//Definimos un nuevo puntero con el valor de pList
    NodeGraph *iter = pList;
    //Mientras tenga datos
    while (iter != nullptr) {
    	//El valor de iter en el campo visited es igual a 
		iter->visited = 0;
        iter = iter->next; //Recorremos la lista (iter)
    }
}

void List::pathDepth(int elmInicial) {
    // dado un elemento inicial imprime el recorrido en profundidad
    NodeGraph *p = NodeGraph::find(pList, elmInicial);
    if (p == nullptr) {
        cout << "Nodo :" << elmInicial << " no encontrado" << endl;
    } else {
        printDepthPath(p);
    }
}

void List::printDepthPath(NodeGraph *p) {
    if (!isVisited(p)) {
        bpp(p);
    }
    cout << "\n\n";
    restoreVisited();
}
//Aqui se realiza la busqueda por profundidad
void List::bpp(NodeGraph * p){
    marcarVisitado(p);
    cout << "["<< p->value<<"]  ";
    //para cada nodo w adyacente a v hacer
    NodeAdj * iter = p->adj;
    while(iter != nullptr){
        if(!isVisited(iter)){
            bpp(NodeGraph::find(pList, iter->value));
        }
        iter=iter->next;
    }
}
