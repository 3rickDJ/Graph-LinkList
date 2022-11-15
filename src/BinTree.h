//Incluir una clase mas para la creacion del Nodo
#include "NodoTree.h"

#pragma  once
class BinTree {
    void pathPreOrden(NodoTree *root);
    void pathPostOrden(NodoTree *root);
    void pathInOrden(NodoTree *root);
    void addNodo(int elm, NodoTree * &root, int & level);
    void findLevel(int elm, NodoTree * &root);
  public:
    NodoTree *pTree;

    BinTree();
    //Funciones del Menu
    void insertarNodo(int elm);

    void MostrarElementos();

    void BuscarPadre(int elm);

    void BuscarHermano(int elm);

    void Descendientes(int elm);

    void Nivel(int elm);

    void Altura(int elm);

    void PreOrden();

    void PostOrden();

    void InOrden();
};
