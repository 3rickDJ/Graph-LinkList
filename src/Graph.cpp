#include "Graph.h"
#include "ADTQueue.h"
#include "NodeAdj.h"
#include "NodeGraph.h"
#include <climits>
#include <iostream>
using std::cout;
using std::endl;
Graph::Graph() {
    // inicializar el apuntador en nullo
    pGraph = nullptr;
}
void Graph::insertarNodo(int x) {
    if (NodeGraph::find(pGraph, x) == nullptr) {
        // variable auxiliar
        NodeGraph *p = new NodeGraph();
        // asignar valor al nodo
        p->value = x;
        // linkear nodo a la lista
        p->next = pGraph;
        //Y hacemos que PList sea igual a p
        pGraph = p;
    } else {
        cout << "Elemento repetido\n";
    }
}

//Mandamos a llamar la funcion de NodeGraph con el/los valores que tiene pGraph
void Graph::imprimir() { NodeGraph::printList(pGraph); }
//Ahora imprimimos la adjacencia con el elemento
void Graph::imprimirAdj(int elm) {
	//Definimos un puntero donde este sea igual al valor que nos devuelve la funcion NodeGraph con pGraph y el elm
    NodeGraph *p = NodeGraph::find(pGraph, elm);
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
bool Graph::listaVacia() {
    // Si lista no tiene elementos quiere decir que apunta a nullo
    return pGraph == nullptr;
}

bool Graph::isAdj(int elmA, int elm) {
	//Definimos un puntero con el valor que devuelve la funcion dado pGraph y el elmA
    NodeGraph *p = NodeGraph::find(pGraph, elmA);
    // verificar si el nodo del grafo es adjacente a elm
    return p->isAdj(elm);
}

//Esta funcion a�ade una adyacencia
void Graph::addAdjacency(int elmA, int elm, int peso) {
	//Definimos un puntero con el valor que devuelve la funcion dado pGraph y elmA
    NodeGraph *p = NodeGraph::find(pGraph, elmA);
    // se encontro nodo elmA en nodoGrafo
    if (p == nullptr) {
        cout << "Nodo " << elmA << " no encontrado\n";
        // se encontro nodo elm en list adyacencia
    } else if (NodeAdj::find(p->adj, elm) != nullptr) {
        cout << "Elemento " << elm << " ya se encuentra registrado\n";
        // no se encontro elm en lista de nodoGrafo
    } else if (NodeGraph::find(pGraph, elm) == nullptr) {
        cout << "Elemento " << elm << " no es un nodo (agregalo)\n";
    } else {
        // si es un Nodo en grafo y no ha sido registrado -> crear nodo
        addAdj(p, elm, peso);
    }
}

//A�adimos un nodo adyacente
void Graph::addAdj(NodeGraph *nodoGrafo, int elm, int peso) {
	//Creamos un puntero con el valor de NodeAdj es decir un nuevo nodo de dos valores
    NodeAdj *nuevoNodo = new NodeAdj();
    //En su campo value ponemos el elemento
    nuevoNodo->value = elm;
    //Aqui se le agrega un peso en su campo weigth
    nuevoNodo->weight = peso;

    //Si en el nodoGrafo en su campo adj es igual a null quiere decir que no hay elementos por lo que 
    if (nodoGrafo->adj == nullptr) {
    	//Es el primero que se le a�ade 
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
        //En el campo next a�adimos el nuevoNodo
        iterator->next = nuevoNodo;
    }
}

void Graph::pathWidth(int elm) {
	//Creamos un puntero con el valor de la funcion NodeGraph con los valores de pGraph y elm
    NodeGraph *p = NodeGraph::find(pGraph, elm);
    //Si p es igual nullptr
    if (p == nullptr) {
    	//No hay elementos
        cout << "El nodo " << elm << " no esta registrado\n";
    } else {
    	//Mandamos a llamar a la funcion con el puntero p
        printWidthPath(p);
    }
}

void Graph::printWidthPath(NodeGraph *p) {
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
        aux = NodeGraph::find(pGraph, valor);
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
void Graph::marcarVisitado(NodeAdj *p) {
    NodeGraph::find(pGraph, p->value)->visited = 1;
}
//Aqui comprobamos si esta visitado ese puntero
bool Graph::isVisited(NodeAdj *p) {
    return NodeGraph::find(pGraph, p->value)->visited == 1;
}
void Graph::marcarVisitado(NodeGraph *p) { p->visited = 1; } //Marcamos el nodo como visitado
bool Graph::isVisited(NodeGraph *p) { return p->visited == 1; } //Si se cumple que el campo de p es igual a 1 se regresa true
void Graph::marcarVisitado(int elm) { NodeGraph::find(pGraph, elm)->visited = 1; } //Marcamos como visitado el elm
bool Graph::isVisited(int elm) {  return NodeGraph::find(pGraph, elm)->visited == 1;} //Verficamos si el elm esta visitado

//Restauramos los campos de visitados a 0
void Graph::restoreVisited() {
	//Definimos un puntero con el valor de pGraph
    NodeGraph *iter = pGraph;
    //Mientras tenga datos
    while (iter != nullptr) {
    	//El valor de iter en el campo visited es igual a 
		iter->visited = 0;
        iter = iter->next; //Recorremos la lista (iter)
    }
}

 // dado un elemento inicial imprime el recorrido en profundidad
void Graph::pathDepth(int elmInicial) {
	//Declaramos un puntero con el valor de la funcion dado pGraph y el elmInicial
    NodeGraph *p = NodeGraph::find(pGraph, elmInicial);
    //Si p es igual a nullptr
    if (p == nullptr) {
    	//Quiere decir que el nodo enviado no existe
        cout << "Nodo :" << elmInicial << " no encontrado" << endl;
    } else {
    	//Llamamos a la funcion para el recorrido por profundidad enviando p
        printDepthPath(p);
    }
}

//Funcion para el recorrimiento dado un puntero (nodo) p
void Graph::printDepthPath(NodeGraph *p) {
	//Si el nodo no a sido visitado
    if (!isVisited(p)) {
    	//Mandamos a llamar a la funcion
        bpp(p);
    }
    cout << "\n\n";
    //Restauramos los campos de p visited a 0 para el nuevo recorrido
    restoreVisited();
}
//Aqui se realiza la busqueda por profundidad
void Graph::bpp(NodeGraph * p){
	//Mandamos a llamar a la funcion marcarVisitado con el puntero p
    marcarVisitado(p);
    cout << "["<< p->value<<"]  "; //Imprimimos el valor
    //para cada nodo w adyacente a v hacer
    NodeAdj * iter = p->adj; //creamos un nuevo puntero donde guardara el/los valores de p en su campos adj
    //Mientras sea diferente de nullptr
	while(iter != nullptr){
		//Si el iter no a sido visitado
        if(!isVisited(iter)){
        	//Mandamos a llamar de nuevo a la funcion enviando NodeGraph para regresar un puntero y que la funcion lo acepte
            bpp(NodeGraph::find(pGraph, iter->value));
        }
        //Recorremos la lista (iter)
        iter=iter->next;
    }
}
//fUNCION PARA EL ARBOL RECORRIDO MINIMO prim
void Graph::TREEPRIM(int i) {
    //Creamos un nuevo grafo para agregar el recorrido
    Graph tree;
    //hasta que todos los nodos hayan sido visitados
    NodeGraph * v = NodeGraph::find(pGraph,i);
    bool primero = true;
    while(getNoVisited()!= nullptr){
        if(primero){
            primero = false;
        }else{
            v = getLeastNoVisited();
        }
        //marcar como visitado
        v->visited = 1;
        //anadir v a F
        tree.insertarNodo(v->value);
        //para cada arista w adyacente a v
        NodeAdj * w = v->adj;
        while (w!= nullptr){
            //si w no ha sido visitado y el peso de la arista es menor al peso minimo asociado al nodo
            if(!isVisited(w) && (w->weight < leastWeight(w))){
                //peso minimo asociado al nodo w, es igual al peso de la arista
                changeLeastWeight(w->value, w->weight);
                //arista de menor peso asociado a w, es igual a la arista v-w
                changeLeastEdge(w->value, v->value);
            }
            w = w->next;
        }
    }
    NodeGraph * iter = pGraph;
    //Recorremos la lista
    while (iter!= nullptr){
        //Definimo w con el menor nodo
        int w = iter->leastNode;
        //A v con el menor valor
        int v = iter->value;
        //Y a weight con el menor peso del grafo
        int weight = iter->leastWeight;
        //Si el peso es diferente de a leastNode esto quiere decir que es el primero
        if(w!=-1){
            //Añadimos la adyacencia de v a w y w a v
            tree.addAdjacency(v, w, weight);
            tree.addAdjacency(w, v, weight);
        }
        //Recorremos el grafo
        iter = iter->next;
    }

    iter = pGraph;
    int index =0;
    while (iter!= nullptr){
        index+= 1;
        tree.imprimirAdj(index);
        iter = iter->next;
    }
    //Restauramos los valores
    restoreVisited();
    restoreLeastWeight();
}


// retorna la primera direccion de memoria de un elemento no visitado
// si todos los elementos han sido visitados, retorna nullptr
NodeGraph *Graph::getNoVisited() {
    NodeGraph *iter = pGraph;
    //Recorremos hasta que no quede ningun valor en el grafo
    while(iter!= nullptr){
        //Si iter en su campo visitado es igual a 0 quiere decir que no ha sido visitado el nodo
        if(iter->visited==0){
            return iter;
        }
        //Recorremos
        iter = iter->next;
    }
    //Si ninguno fue no visitado regresamos null
    return nullptr;
}
//le pasas un nodo w, y te retorna su menor peso asociado
int Graph::leastWeight(NodeAdj *pAdj) {
    NodeGraph *p = NodeGraph::find(pGraph, pAdj->value);
    return p->leastWeight;
}
void Graph::changeLeastWeight(int value, int weight) {
    NodeGraph *p = NodeGraph::find(pGraph, value);
    p->leastWeight = weight;
}
void Graph::changeLeastEdge(int nodo, int menorArista) {
    NodeGraph *p = NodeGraph::find(pGraph, nodo);
    p->leastNode = menorArista;
}
void Graph::restoreLeastWeight() {
    //Definimos un puntero con el valor de pGraph
    NodeGraph *iter = pGraph;
    //Mientras tenga datos
    while (iter != nullptr) {
        //El valor de iter en el campo visited es igual a
        iter->leastWeight = INT_MAX;
        iter->leastNode = -1;
        iter = iter->next; //Recorremos la lista (iter)
    }
}
//obtener el nodo que no ha sido visitado con el menor costo de conexion
//retorna nullptr si todos los nodos estan visitados
// retorna el pointer al nodo con el menor valor en leastWeight
NodeGraph *Graph::getLeastNoVisited() {
    NodeGraph * iter = pGraph;
    //Digamos que el minCost sea hasta infinito
    int minCost = INT_MAX;
    //Direccion del elemento
    NodeGraph * pMinCost = nullptr;
    while (iter!=nullptr){
        if(iter->visited == 0 && (iter->leastWeight < minCost) ){
            pMinCost = iter;
            minCost = iter->leastWeight;
        }
        iter = iter->next;
    }
    return pMinCost;
}
