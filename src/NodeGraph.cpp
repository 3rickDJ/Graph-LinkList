#include "NodeGraph.h"
#include <iostream>

using namespace std;

NodeGraph::NodeGraph() {
    // set null by default
    value = 0;
    visited = 0;
    adj = nullptr;
    next = nullptr;
}
void NodeGraph::printAdj() {
    NodeAdj::printList(adj);
}
//retorna true si tiene adyacencia, falso de otra forma
bool NodeGraph::isAdj(int elm) {
    //buscar elm en adj
    return NodeAdj::find(adj,elm)==nullptr;
}
NodeGraph* NodeGraph::find(NodeGraph* inicio, int elm){
    NodeGraph* p = inicio;
    while(p!=nullptr){
        if(p->value==elm){
            return p;
        }
        p = p->next;
    }
    return p;
}
void NodeGraph::printList(NodeGraph* inicio){
    NodeGraph* p = inicio;
    if(p==nullptr){
        cout << "No hay datos en la lista";
    }else{
        while(p!=nullptr){
            std::cout << "["<<p->value<<"] ->";
            p=p->next;
        }
        std::cout <<"\n";
    }
}
