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
}

