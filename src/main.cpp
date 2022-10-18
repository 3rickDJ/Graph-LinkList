// incluir header de la clase List
#include "List.h"
#include "iostream"
using std::cin;
using std::cout;
using std::endl;
int main() {
		//Delcaramos nuestras variables para usar dentro del menu
    int opt, elm, elmA;
    List lista; //Con esto hacemos un llamado de la clase List a lista
    do {
        cout << "=============================================================="
             << endl;
        cout << "                                     MENU                     "
             << endl;
        cout << "=============================================================="
             << endl;
        cout << " 1. Insertar nodo" << endl;
        cout << " 2. AÃ±adir adjacencia " << endl;
        cout << " 3. Son adjacentes" << endl;
        cout << " 4. Mostrar nodos" << endl;
        cout << " 5. Mostrar adjacencia (dado un nodo)" << endl;
        cout << " 6. Recorrido a lo ancho" << endl;
        cout << " 7. Recorrido en profundidad" << endl;
        cout << " 8. Salir" << endl;
        cout << " Ingrese una opcion: ";
        cin >> opt;
        cout << endl;

        // Mostrar opciones
        switch (opt) {
        case 1:
            // preguntar Elemento a insertar
            cout << "Elemento a insertar: ";
            cin >> elm;
            lista.insertarNodo(elm); //con esto podemos llamar a la clase Lista como lista. y la funcion con el elemento enviado
            break;
        case 2:
            // Añadir adjacencia
            cout << "Elemento a: \n";
            cin >> elmA;				 //Se necesita enviar el nodo donde se registrara la adyacencia
            cout << "Elemento b: \n";
            cin >> elm;					// Y el que se el añadira a ese como el adyacente
            lista.addAdjacency(elmA, elm);//Ahora llamamos a la funcion
            break;
        case 3:
            // preguntar por adjacencia
            cout << "Elemento a: ";
            cin >> elmA;
            cout << "Elemento b: ";
            cin >> elm;
                //Con esta funcion nos devuelve un valor donde si es true el elmA es adyacente a elmB
            if (lista.isAdj(elmA, elm)) {
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
            lista.imprimir();
            break;
        case 5:
            // mostarAdjacencia
            cout << "Nodo a: ";
            cin >> elmA;
            lista.imprimirAdj(elmA);//Para mostrar la adyencencia se le envia el nodo que queramos imprimir sus adyacentes
            break;
        case 6:
            //Recorrido a lo ancho
            cout << "Nodo inicial a: ";
            cin >> elmA;
            lista.pathWidth(elmA); //Se tiene que definir el elemento con el que se recorrera el grafo por anchura
            break;
        case 7:
            //Recorrido a lo ancho
            cout << "Nodo inicial a: ";
            cin >> elmA;
            lista.pathDepth(elmA); //Se tiene que definir el elemento con el que se recorrera el grafo por profundidad
            break;
        case 8:
            break;
        default:
            opt = 8;
            cout << "Opcion no valida.\nSaliendo\n";
        }
    } while (opt != 8);
}
