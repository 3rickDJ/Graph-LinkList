//incluir header de la clase List
#include "List.h"
#include "NodeGraph.h"
#include "iostream"
using std::cin;
using std::cout;
using std::endl;
int main(){
    int opt, elm, elmA;
    List lista;
    do{
    cout << "================================================================================" <<endl;
    cout << "                                     MENU                                       " <<endl;
    cout << "================================================================================" <<endl;
    cout << " 1. Insertar nodo"<<endl;
    cout << " 2. Añadir adjacencia "<<endl;
    cout << " 3. Son adjacentes"<<endl;
    cout << " 4. Mostrar nodos"<<endl;
    cout << " 5. Mostrar adjacencia (dado un nodo)"<<endl;
    cout << " 6. Salir"<<endl;
    cout << " Ingrese una opcion: ";
    cin >> opt;
    cout << endl;

    //Mostrar opciones
    switch(opt){
        case 1:
            //preguntar Elemento a insertar
            cout << "Elemento a insertar: " ;
            cin >> elm;
            lista.insertarNodo(elm);
            break;
        case 2:
            //Añadir adjacencia
            cout << "Elemento a: " ;
            cin >> elmA;
            cout << "Elemento b: " ;
            cin >> elm;
            lista.addAdjacency(elmA, elm);
            break;
        case 3:
            //preguntar por adjacencia
            cout << "Elemento a: " ;
            cin >> elmA;
            cout << "Elemento b: " ;
            cin >> elm;
            if(lista.isAdj(elmA,elm)){
                cout << "Elemento a="<<elmA<< " SI es adyacente a b="<<elm<<"\n";
            }else{
                cout << "Elemento a="<<elmA<< " NO es adyacente a b="<<elm<<"\n";
            }
            break;
        case 4:
            //mostrar nodos
            lista.imprimir();
            break;
        case 5:
            //mostarAdjacencia
            cout << "Elemento a: " ;
            cin >> elmA;
            lista.imprimirAdj(elmA);
            break;
        case 6:
            break;
        default:
            opt=6;
            cout << "Opcion no valida.\nSaliendo\n";
    }
    }while(opt!=6);
}
