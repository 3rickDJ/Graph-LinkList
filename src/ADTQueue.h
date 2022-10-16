#pragma once
#include "NodeAdj.h"
class Queue{
public:
    NodeAdj* queue;
    Queue();
    //insertar un elemento al final de la cola
    void encolar(int elm);
    //recuperar y eliminar un elemento al inicio de la cola
    int desencolar();
    //obtener el primer elemento de la cola sin eliminarlo
    int primero();
    void imprimir();
};
