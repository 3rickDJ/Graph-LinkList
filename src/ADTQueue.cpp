#include "ADTQueue.h"
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
        delete(tmpQ);
        return tmp;
    }
}
// obtener el primer elemento de la cola sin eliminarlo
int Queue::primero() { return queue->value; }
