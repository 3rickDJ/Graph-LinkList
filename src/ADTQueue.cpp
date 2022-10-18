#include "ADTQueue.h"
#include <iostream>
Queue::Queue(){
	//Inicializamos el puntero para que sea igual a NULLPTR
    queue = nullptr;
}
// insertar un elemento al final de la cola
void Queue::encolar(int elm) {
	//Definimos que nuestro nuevo puntero p tome el valor de un nuevo NodoAdj 
    NodeAdj *p = new NodeAdj();
    //Su campo value toma el valor de elm
    p->value = elm;
    //Mientras la queue sea igual a null (es decir vacia)
    if (queue == nullptr) {
    	//Queue toma el valor del puntero p
        queue = p;
    } //Si es que cuenta con al menos un dato 
		else {
    	//Deifinimos un nuevo puntero iterador con el valor de queue
        NodeAdj *iterator = queue;
        //Mientras nuestro puntero iterador en su cambio siguiente sea diferente de nullptr
        while (iterator->next != nullptr) {
        	//Recorremos el iterador de la siguiente manera
            iterator = iterator->next;
        }
        //Iterador en su campo siguiente es igual a el puntero p
        iterator->next = p;
    }
}
// recuperar y eliminar un elemento al inicio de la cola
int Queue::desencolar() {
	//Si la queue es igual nullptr 
    if (queue == nullptr) {
    	//No hay nada que recuperar por eso retornamos un 0
        return 0;
    } else {
    	//definimos una variable entera donde guardaremos lo que tiene queue en su campo value
        int tmp = queue->value;
        //Definimos ahora un puntero que guarde queue
        NodeAdj *tmpQ = queue;
        //A queue le asignamos el siguiente valor es decir queue en su campo next
        queue = queue->next;
        //Liberamos la variable tmpQ
        free(tmpQ);
        //Regresamos el valor que se le fue asignado a la variable tmp en la linea 38
        return tmp;
    }
}

// obtener el primer elemento de la cola sin eliminarlo
int Queue::primero() {
	//Si la queue es igual nullptr
    if(queue==nullptr){
    	//No hay elementos en la cola por lo que no podemos imprimir nada
        return 0;
    }//Si es que cuenta con almenos un dato
	else{
    	//Regresamos lo que esta en la queue en el campo value 
        return queue->value; }
    }

//Imprimimos lo que tiene queue
void Queue::imprimir() {
	//Creamos un puntero llamado iter asignandole el/los valor que tiene queue
    NodeAdj *iter = queue;
    //Mientras que iter sea diferente de nullptr
    while (iter != nullptr) {
    	//Imprimimos lo que tiene el apuntador iter en su campo value 
        std::cout << "[" << iter->value << "]..";
        //Recorremos el apuntador para acabar en algun punto con el ciclo
        iter = iter->next;
    }
}
