#pragma once
#include "NodeAdj.h"
class Queue{
public:
	//Definimos un puntero llamado queue ("cola")
    NodeAdj* queue;
    Queue(); //Inicializamos 
    //insertar un elemento al final de la cola
    void encolar(int elm);
    //recuperar y eliminar un elemento al inicio de la cola
    int desencolar();
    //obtener el primer elemento de la cola sin eliminarlo
    int primero();
    //Funcion para imprimirla 
    void imprimir();
};
