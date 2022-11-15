#pragma once
class NodoTree {
  public:
    int value;
    int visited;
    int level;
    NodoTree *left;
    NodoTree *right;
    //Constructor no arg
    NodoTree();
    //Constructor con un value
    NodoTree(int value);
    NodoTree(int value, int level);
    void operator=(const NodoTree &other);

    /*
    //Encontrar un elemento de la lista
    static NodoTree *find(NodoTree *inicio, int elm);
    //Este sera para imprimir la lista desde el puntero "inicio"
    static void printList(NodoTree *inicio);
    }
    */
};