#include "BinTree.h"
#include <iostream>
using namespace std;

BinTree::BinTree() {
    //Asignacion de valor a pTree
    pTree = nullptr;
}

//insertar el nodo en el arbol
                        //Apuntador por referen
void BinTree::insertarNodo(int elm, NodoTree * &root) {
    if(root== nullptr){ // Si no hay elementos en la raíz, inserta un nuevo nodo
        root = new NodoTree(elm);
    }else{  // Si no, inserta elementos a la derecha o a la izquierda del nodo seleccionado
        if(elm <= root->value){ // Si el elemento es menor al del nodo, entonces se va a insertar a la izquierda
            insertarNodo(elm, root->left);
        }else{ // si no, se va a la derecha
            insertarNodo(elm, root->right);
        }
    }
}

//Empezar a hacer recorridos en pre-orden
void BinTree::PreOrden() {
    if(pTree== nullptr){   // Si el arbol esta vacio entonces no se hace nada
        cout << "El arbol esta vacio\n"; //y se imprime este mensaje
    }else{
        pathPreOrden(pTree); //Caso contrario, si el arbol tiene elementos vamos a llamar a la funcion pathPreOrden
    }
}
void BinTree::pathPreOrden(NodoTree *root) {
    if(root != nullptr){
        cout << "[" << root->value <<"], ";
        pathPreOrden(root->left);
        pathPreOrden(root->right);
    }
}

//Camino de recorrido en Post orden
void BinTree::PostOrden() {
    if(pTree== nullptr){   // Si el arbol esta vacio entonces no se hace nada
        cout << "El arbol esta vacio\n"; //y se imprime este mensaje
    }else{
        pathPostOrden(pTree); //Caso contrario, si el arbol tiene elementos vamos a llamar a la funcion pathPreOrden
        cout << "\n";
    }
}
void BinTree::pathPostOrden(NodoTree *root) {
    if(root != nullptr){
        pathPostOrden(root->left);
        pathPostOrden(root->right);
        cout << "[" << root->value <<"], ";
    }
}

//Camino de recorrido en orden
void BinTree::InOrden() {
    if(pTree== nullptr){   // Si el arbol esta vacio entonces no se hace nada
        cout << "El arbol esta vacio\n"; //y se imprime este mensaje
    }else{
        pathInOrden(pTree); //Caso contrario, si el arbol tiene elementos vamos a llamar a la funcion pathPreOrden
        cout << "\n";
    }
}
void BinTree::pathInOrden(NodoTree *root) {
    if(root != nullptr){
        pathInOrden(root->left);
        cout << "[" << root->value <<"], ";
        pathInOrden(root->right);
    }
}

void BinTree::MostrarElementos() {}
void BinTree::BuscarPadre(int elm) {}
void BinTree::BuscarHermano(int elm) {}
void BinTree::Descendientes(int elm) {}
void BinTree::Nivel(int elm) {}
void BinTree::Altura(int elm) {}
