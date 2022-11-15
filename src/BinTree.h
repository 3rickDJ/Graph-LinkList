//Incluir una clase mas para la creacion del Nodo


#pragma  once
class BinTree {
    NodoTree *pTree;
    //Funciones del Menu
    void insertarNodo(elm);

    void MostrarElementos();

    void BuscarPadre(elm);

    void BuscarHermano(elm);

    void Descendientes(elm);

    void Nivel(elm);

    void Altura(elm);

    void PreOrden(elmA);

    void PostOrden(elmA);

    void InOrden(elmA);
};
