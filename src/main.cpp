// incluir header de la clase Graph
#include "Graph.h"
#include "iostream"
using std::cin;
using std::cout;
using std::endl;
int main() {
		//Delcaramos nuestras variables para usar dentro del menu
    int opt, elm, elmA, weight;
    Graph arbol; //Con esto hacemos un llamado de la clase Graph a arbol
    do {
        cout << "=============================================================="
             << endl;
        cout << "                                     MENU                     "
             << endl;
        cout << "=============================================================="
             << endl;
        cout << " 1. Insertar nodo" << endl;
        cout << " 2. Mostra arbol" << endl;
        cout << " Dado un nodo" << endl;
        cout << " 3. Hallar padre " << endl;
        cout << " 4. Hallar hermano " << endl;
        cout << " 5. Descendientes " << endl;
        cout << " 6. Nivel" << endl;
        cout << " 7. Altura" << endl;
        cout << " 8. Recorrido en Pre-orden" << endl;
        cout << " 9. Recorrido en Pos-orden" << endl;
        cout << " 10. Recorrido en In-orden" << endl;
        cout << " 11. Salir" << endl;
        cout << " Ingrese una opcion: ";
        cin >> opt;
        cout << endl;
        // Mostrar opciones
        switch (opt) {
        case 1:
            // preguntar Elemento a insertar
            cout << "Elemento a insertar: ";
            cin >> elm;
            arbol.insertarNodo(elm); //con esto podemos llamar a la clase Lista como arbol. y la funcion con el elemento enviado
            break;
        case 2:
            //Mostrar los elementos del arbol
            arbol.MostrarElementos();
            break;
        case 3:
            //Encontrar Padre dado el Nodo
            //Se pregunta por el nodo
            cout << "Dame el elemento a buscar su padre: ";
            cin  >> elm;
            //Ahora la funcion a llamar pasamos el valor anterior
            arbol.BuscarPadre(elm);
            break;
        case 4:
            //Encontrar Hermano dado el Nodo
            //Se pregunta por el nodo
            cout << "Dame el elemento a buscar su Hermano: ";
            cin  >> elm;
            //Ahora la funcion a llamar pasamos el valor anterior
            arbol.BuscarHermano(elm);
            break;
        case 5:
            //Encontrar Descendientes dado el Nodo
            //Se pregunta por el nodo
            cout << "Dame el elemento a buscar su(s) Descendientes: ";
            cin  >> elm;
            //Ahora la funcion a llamar pasamos el valor anterior
            arbol.Descendientes(elm);
            break;
        case 6:
            //Encontrar el Nivel dado el Nodo
            //Se pregunta por el nodo
            cout << "Dame el elemento a buscar su Nivel: ";
            cin  >> elm;
            //Ahora la funcion a llamar pasamos el valor anterior
            arbol.Nivel(elm);
            break;
        case 7:
            //Encontrar la Altura dado el Nodo
            // Se pregunta por el nodo
            cout << "Dame el elemento a buscar su Altura: ";
            cin  >> elm;
            //Ahora la funcion a llamar pasamos el valor anterior
            arbol.Altura(elm);
            break;
        case 8:
            //Recorrido a lo Preorden
            cout << "Nodo inicial a: ";
            cin >> elmA;
            arbol.pathDepth(elmA); //Se tiene que definir el elemento con el que se recorrera el grafo por profundidad
            break;
        case 9:
            //Recorrido a lo Post-Orden
            cout << "Nodo inicial a: ";
            cin >> elmA;
            arbol.pathDepth(elmA); //Se tiene que definir el elemento con el que se recorrera el grafo por profundidad
            break;
        case 10:
            //Recorrido a lo In-Orden
            cout << "Nodo inicial a: ";
            cin >> elmA;
            arbol.pathDepth(elmA); //Se tiene que definir el elemento con el que se recorrera el grafo por profundidad
            break;
        case 11:
            cout << "Adios...\n ";
            break;
        default:
            opt = 11;
            cout << "Opcion no valida.\nSaliendo\n";
        }
    } while (opt != 11);
}
