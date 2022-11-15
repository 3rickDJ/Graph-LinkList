#include "NodoTree.h"

using namespace std;
//Este constructor no tiene parametros para poner los valores por default
NodoTree::NodoTree() {
    this->value = -1;
    visited = 0;
    left = nullptr;
    right = nullptr;

}
//Constructor para cuando se crea un nodo con un valor digitado por el usuario
NodoTree::NodoTree(int value) {
    this->value = value;
    visited  = 0;
    left = nullptr;
    right = nullptr;
    left = 0;
    level = 0;
}

void NodoTree::operator=(const NodoTree &other) {
        this->value = other.value;
        this->left = other.left;
        this->right = other.right;
        this->visited = other.visited;
}
//Sobrecarga de operadores
NodoTree::NodoTree(int value, int level) {
    this->value = value;
    visited  = 0;
    left = nullptr;
    right = nullptr;
    left = 0;
    this->level = level;
}
