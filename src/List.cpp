#include "List.h"
#include "NodeGraph.h"
#include "NodeAdj.h"
using std::cout;
List::List() {
    // inicializar el apuntador en nullo
    pList = nullptr;
}
void List::insertarNodo(int x) {
    // variable auxiliar
    NodeGraph *p = new NodeGraph();
    // asignar valor al nodo
    p->value = x;
    // linkear nodo a la lista
    p->next = pList;
    pList = p;
}
void List::imprimir() {
    NodeGraph::printList(pList);
}
void List::imprimirAdj(int elm) {
    NodeGraph *p = NodeGraph::find(pList,elm);
    // recorrer cada nodo mientras no apuntemos a nulo
    NodeAdj::printList(p->adj);
}
/* void List::eliminarPrimero() { */
/*     if (listaVacia()) { */
/*         // verificar si esta vacia */
/*         std::cout << "No hay elementos.\n"; */
/*     } else { */
/*         NodeGraph *p = pList; */
/*         // apuntar al siguiente elemento */
/*         pList = pList->next; */
/*         // eliminar el primer elemento */
/*         free(p); */
/*     } */
/* } */
/* void List::eliminarUltimo() { */
/*     NodeGraph *p = pList; */
/*     // si esta vacio no podemos acceder a p->next->next */
/*     // nos da un error */
/*     if (listaVacia()) { */
/*         // si esta vacia mandar mensaje */
/*         std::cout << "No hay elementos.\n"; */
/*     } else if (p->next == 0) { */
/*         free(p); */
/*         pList = 0; */
/*     } else { */
/*         // iterar hasta llegar al penultimo nodo */
/*         while (p->next->next != 0) { */
/*             // siguiente nodo */
/*             p = p->next; */
/*         } */
/*         // liberar el ultimo nodo */
/*         free(p->next); */
/*         // ultimo nodo apuntando a null */
/*         p->next = 0; */
/*     } */
/* } */
bool List::listaVacia() {
    // lista no tiene elementos si apunta a nullo
    return pList == nullptr;
}

bool List::isAdj(int elmA, int elm) {
    NodeGraph *p = NodeGraph::find(pList,elmA);
    // verificar si el nodo del grafo es adjacente a elm
    return p->isAdj(elm);
}
void List::addAdjacency(int elmA, int elm) {
    NodeGraph *p = NodeGraph::find(pList,elmA);
    if (p == 0) {
        cout << "Nodo " << elmA << " no encontrado\n";
    } else {
        addAdj(p, elm);
    }
}
void List::addAdj(NodeGraph *nodoGrafo, int elm) {
    NodeAdj* nuevoNodo = new NodeAdj();
    nuevoNodo->value = elm;
    if(nodoGrafo->adj == nullptr){
        nodoGrafo->adj = nuevoNodo;
    }
    if(nodoGrafo->adj != nullptr){
        NodeAdj* iterator = nodoGrafo->adj;
        while(iterator->next !=nullptr){
            iterator = iterator->next;
        }
        iterator->next = nuevoNodo;

    }
    NodeAdj *p = nodoGrafo->adj;
    NodeAdj *nuevoAdj = new NodeAdj();
    nuevoAdj->value = elm;
    //linkear nodo a lista adj
    if(p==nullptr){
        p=nuevoAdj;
    }else{
        while(p!=nullptr){
            p=p->next;
        }
        p=nuevoAdj;
    }
}
