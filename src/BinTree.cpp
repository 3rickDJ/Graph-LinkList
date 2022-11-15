#include "BinTree.h"

BinTree::BinTree() {
    //Asignacion de valor a pTree
    pTree = nullptr;
}

//insertar el nodo en el arbol
void BinTree::insertarNodo(int elm, NodoTree *root) {
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



