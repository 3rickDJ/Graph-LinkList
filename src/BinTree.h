//Incluir una clase mas para la creacion del Nodo
#include "NodoTree.h"

#pragma  once
class BinTree {
    NodoTree *pTree;
    public:
    //Funciones del Menu
    void insertarNodo(int elm);

    void MostrarElementos();

    void BuscarPadre(int elm);

    void BuscarHermano(int elm);

    void Descendientes(int elm);

    void Nivel(int elm);

    void Altura(int elm);

    void PreOrden(int elm);

    void PostOrden(int elem);

    void InOrden(int elm);
};
