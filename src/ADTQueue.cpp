#include "ADTQueue.h"
#include <iostream>
// insertar un elemento al final de la cola
void Queue::encolar(int elm) {
    NodeAdj *p = new NodeAdj();
    p->value = elm;
    if (queue == nullptr) {
        queue = p;
    } else {
        NodeAdj *iterator = queue;
        while (iterator->next != nullptr) {
            iterator = iterator->next;
        }
        iterator->next = p;
    }
}
// recuperar y eliminar un elemento al inicio de la cola
int Queue::desencolar() {
    if (queue == nullptr) {
        return 0;
    } else {
        int tmp = queue->value;
        NodeAdj *tmpQ = queue;
        queue = queue->next;
        free(tmpQ);
        return tmp;
    }
}
// obtener el primer elemento de la cola sin eliminarlo
int Queue::primero() {
    if(queue==nullptr){
        return 0;
    }else{
        return queue->value; }
    }

void Queue::imprimir() {
    NodeAdj *iter = queue;
    while (iter != nullptr) {
        std::cout << "[" << iter->value << "]..";
        iter = iter->next;
    }
}
