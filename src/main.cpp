// incluir header de la clase Graph
#include "Graph.h"
#include "iostream"
using std::cin;
using std::cout;
using std::endl;
int main() {
		//Delcaramos nuestras variables para usar dentro del menu
    int opt, elm, elmA, weight;
    Graph graph; //Con esto hacemos un llamado de la clase Graph a graph
    do {
        cout << "=============================================================="
             << endl;
        cout << "                                     MENU                     "
             << endl;
        cout << "=============================================================="
             << endl;
        cout << " 1. Insertar nodo" << endl;
        cout << " 2. Añadir adjacencia " << endl;
        cout << " 3. Son adjacentes" << endl;
        cout << " 4. Mostrar nodos" << endl;
        cout << " 5. Mostrar adjacencia (dado un nodo)" << endl;
        cout << " 6. Recorrido a lo ancho" << endl;
        cout << " 7. Recorrido en profundidad" << endl;
        cout << " 8. Arbol de extension minima PRIM " << endl;
        cout << " 9. Salir" << endl;
        cout << " Ingrese una opcion: ";
        cin >> opt;
        cout << endl;

        // Mostrar opciones
        switch (opt) {
        case 1:
            // preguntar Elemento a insertar
            cout << "Elemento a insertar: ";
            cin >> elm;
            graph.insertarNodo(elm); //con esto podemos llamar a la clase Lista como graph. y la funcion con el elemento enviado
            break;
        case 2:
            // A�adir adjacencia
            cout << "Elemento a: \n";
            cin >> elmA;				 //Se necesita enviar el nodo donde se registrara la adyacencia
            cout << "Elemento b: \n";
            cin >> elm;					// Y el que se el a�adira a ese como el adyacente
            cout << "Peso entre a y b\n";
            cin >> weight;
            graph.addAdjacency(elmA, elm, weight);//Ahora llamamos a la funcion
            break;
        case 3:
            // preguntar por adjacencia
            cout << "Elemento a: ";
            cin >> elmA;
            cout << "Elemento b: ";
            cin >> elm;
                //Con esta funcion nos devuelve un valor donde si es true el elmA es adyacente a elmB
            if (graph.isAdj(elmA, elm)) {
                cout << "Elemento a=" << elmA << " SI es adyacente a b=" << elm
                     << "\n";
            }//Si no es que los elementos enviados no son adyacentes
			 else {
                cout << "Elemento a=" << elmA << " NO es adyacente a b=" << elm
                     << "\n";
            }
            break;
        case 4:
            // mostrar nodos
            graph.imprimir();
            break;
        case 5:
            // mostarAdjacencia
            cout << "Nodo a: ";
            cin >> elmA;
            graph.imprimirAdj(elmA);//Para mostrar la adyencencia se le envia el nodo que queramos imprimir sus adyacentes
            break;
        case 6:
            //Recorrido a lo ancho
            cout << "Nodo inicial a: ";
            cin >> elmA;
            graph.pathWidth(elmA); //Se tiene que definir el elemento con el que se recorrera el grafo por anchura
            break;
        case 7:
            //Recorrido a lo Profundo
            cout << "Nodo inicial a: ";
            cin >> elmA;
            graph.pathDepth(elmA); //Se tiene que definir el elemento con el que se recorrera el grafo por profundidad
            break;
        case 8:
            //Arbol de extension minima PRIM
            cout << "Nodo inicial a: ";
            cin >> elmA;
            graph.TREEPRIM(elmA);
            break;
        default:
            opt = 9;
            cout << "Opcion no valida.\nSaliendo\n";
        }
    } while (opt != 9);
}
