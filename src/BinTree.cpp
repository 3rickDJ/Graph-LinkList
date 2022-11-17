#include "BinTree.h"
#include <iostream>
using namespace std;

BinTree::BinTree() {
    //Asignacion de valor a pTree
    pTree = nullptr;
    height = 0;
}

//insertar el nodo en el arbol
//Variable para saber cuantas veces hemos llamado a la funcion insertarNodo

void BinTree::addNodo(int elm, NodoTree *&root, int &level) {
    level += 1;
    if(root== nullptr){ // Si no hay elementos en la raíz, inserta un nuevo nodo
        root = new NodoTree(elm, level);
        //Solo cuando se encuentre un nodo hoja  puesto que aqui solo se actualiza cuando el nivel sea mayor a altura se actualiza altura
        if(height<level)
            height = level;
    }else{  // Si no, inserta elementos a la derecha o a la izquierda del nodo seleccionado
        if(elm <= root->value){ // Si el elemento es menor al del nodo, entonces se va a insertar a la izquierda
            addNodo(elm, root->left, level);
        }else{ // si no, se va a la derecha
            addNodo(elm, root->right, level);
        }
    }
}

//Apuntador por referencia
void BinTree::insertarNodo(int elm) {
    int level=0;
    addNodo(elm, pTree, level);
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

void BinTree::BuscarPadre(int elm) {
    if(pTree->value == elm){ //Si el elemento es igual a la raiz entonces no tiene padre
        cout << "La raiz no tiene un nodo padre\n";
    }else{
        buscarPadre(elm, pTree); // si no, se va a la funcion buscar padre
    }
}


void BinTree::BuscarHermano(int elm) {
    if(pTree->value == elm){ //Si el elemento es igual a la raiz entonces no tiene padre
        cout << "La raiz no tiene hermanos\n";
    }else{
        buscarHermano(elm, pTree); // si no, se va a la funcion buscar padre
    }
}
void BinTree::Descendientes(int elm) {
   if(pTree->value == elm){ //Si el elemento es igual a la raiz entonces no tiene padre
        cout << "La raiz no tiene Descendientes\n";
    }else{
        buscarDescendientes(elm, pTree); // si no, se va a la funcion buscar padre
    }
}


void BinTree::findLevel(int elm, NodoTree* & root) {
    if(root != nullptr){
        if(root->value != elm){
            findLevel(elm, root->left);
            findLevel(elm, root->right);
            //Aqui si el valor en el nodo es igual del valor al que se le envia se imprime su nivel
        }else{
            cout << "[" << root->value <<"]=>" << (root->level-1) << "\n";
        }
    }
}
void BinTree::Nivel(int elm) {
    //Mandamos el elemento y el ptree para recorrer el arbol hasta encontrar el elemento
    findLevel(elm, pTree);

}
void BinTree::Altura() {
    cout << "La altura es: " << height << "\n";
}

void BinTree::buscarPadre(int elm, NodoTree *&root) {
    //Mientras el nodo sea diferente de null
    if(root!= nullptr){
        //Si el nodo en su campo izquierdo es diferente de null y en su campo valor es igual al elem enviado
        if(root->left != nullptr && root->left->value == elm){
            //Imprimimos el valor del nodo
            cout << "El padre: " << root->value << "\n";
            return;
        }
        //hacemos lo mismo pero con el nodo derecho
        if(root->right != nullptr && root->right->value == elm){
            cout << "El padre: " << root->value << "\n";
            return ;
        }
        buscarPadre(elm, root->right);
        buscarPadre(elm, root->left);
    }
}
void BinTree::buscarHermano(int elm, NodoTree *&root) {
    //Mientras el nodo sea diferente de null
    if(root!= nullptr){
        //Si el nodo en su campo izquierdo es diferente de null y en su campo valor es igual al elem enviado
        if(root->left != nullptr && root->left->value == elm){
            if(root->right == nullptr) {
                cout << "El nodo no tiene hermanos :( Pobrecito \n";
            } else {
                cout << "El hermano es: " << root->right->value << "\n";
            }
            //Imprimimos el valor del nodo
            return;
        }
        //hacemos lo mismo pero con el nodo derecho
        if(root->right != nullptr && root->right->value == elm){
            if(root->left == nullptr) {
                cout << "El nodo no tiene hermanos :( Pobrecito \n";
            } else {
                cout << "El hermano es: " << root->left->value << "\n";
            }
            return ;
        }
        buscarHermano(elm, root->right);
        buscarHermano(elm, root->left);
    }
}

void BinTree::buscarDescendientes(int elm, NodoTree *&root) {
    //Mientras el nodo sea diferente de null
    if(root!= nullptr){
        //Si el nodo en su campo izquierdo es diferente de null y en su campo valor es igual al elem enviado
        if(root->left != nullptr && root->left->value == elm){
            pathPreOrden(root->left);
            return;
        }
        //hacemos lo mismo pero con el nodo derecho
        if(root->right != nullptr && root->right->value == elm){
            pathPreOrden(root->right);
            return ;
        }
        buscarDescendientes(elm, root->right);
        buscarDescendientes(elm, root->left);
    }
}
