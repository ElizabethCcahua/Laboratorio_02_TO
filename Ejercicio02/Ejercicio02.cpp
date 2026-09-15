#include <iostream>
using namespace std;

// ==========================================
// CLASE NODO
// ==========================================
class Nodo {
public:
    int dato;
    Nodo* anterior;
    Nodo* siguiente;

    Nodo(int valor) {
        dato = valor;
        anterior = nullptr;
        siguiente = nullptr;
    }
};


// ==========================================
// CLASE LISTA DOBLEMENTE ENLAZADA
// ==========================================
class ListaDoble {
private:
    Nodo* inicio;
    Nodo* fin;

public:

    ListaDoble() {
        inicio = nullptr;
        fin = nullptr;
    }

    void insertar(int valor) {

        Nodo* nuevo = new Nodo(valor);

        if (inicio == nullptr) {
            inicio = nuevo;
            fin = nuevo;
        }
        else {
            fin->siguiente = nuevo;
            nuevo->anterior = fin;
            fin = nuevo;
        }

        cout << "Elemento " << valor << " insertado." << endl;
    }

    void mostrarAdelante() {

        if (inicio == nullptr) {
            cout << "La lista esta vacia." << endl;
            return;
        }

        Nodo* actual = inicio;

        cout << "NULL <- ";

        while (actual != nullptr) {
            cout << actual->dato;

            if (actual->siguiente != nullptr) {
                cout << " <-> ";
            }

            actual = actual->siguiente;
        }

        cout << " -> NULL" << endl;
    }

    void mostrarAtras() {

        if (fin == nullptr) {
            cout << "La lista esta vacia." << endl;
            return;
        }

        Nodo* actual = fin;

        cout << "NULL <- ";

        while (actual != nullptr) {
            cout << actual->dato;

            if (actual->anterior != nullptr) {
                cout << " <-> ";
            }

            actual = actual->anterior;
        }

        cout << " -> NULL" << endl;
    }

    void buscar(int valor) {

        Nodo* actual = inicio;

        while (actual != nullptr) {

            if (actual->dato == valor) {
                cout << "El elemento " << valor
                     << " se encuentra en la lista." << endl;
                return;
            }

            actual = actual->siguiente;
        }

        cout << "El elemento " << valor
             << " no se encuentra en la lista." << endl;
    }

    void eliminar(int valor) {

        Nodo* actual = inicio;

        while (actual != nullptr && actual->dato != valor) {
            actual = actual->siguiente;
        }

        if (actual == nullptr) {
            cout << "Elemento no encontrado." << endl;
            return;
        }

        if (actual->anterior != nullptr) {
            actual->anterior->siguiente = actual->siguiente;
        }
        else {
            inicio = actual->siguiente;
        }

        if (actual->siguiente != nullptr) {
            actual->siguiente->anterior = actual->anterior;
        }
        else {
            fin = actual->anterior;
        }

        delete actual;

        cout << "Elemento " << valor << " eliminado." << endl;
    }

    ~ListaDoble() {

        Nodo* actual = inicio;

        while (actual != nullptr) {

            Nodo* siguiente = actual->siguiente;

            delete actual;

            actual = siguiente;
        }
    }
};


// ==========================================
// PROGRAMA PRINCIPAL
// ==========================================
int main() {

    ListaDoble lista;

    int opcion;
    int valor;

    do {

        cout << "\n====================================" << endl;
        cout << "   LISTA DOBLEMENTE ENLAZADA" << endl;
        cout << "====================================" << endl;

        cout << "1. Insertar elemento" << endl;
        cout << "2. Mostrar de inicio a fin" << endl;
        cout << "3. Mostrar de fin a inicio" << endl;
        cout << "4. Buscar elemento" << endl;
        cout << "5. Eliminar elemento" << endl;
        cout << "6. Salir" << endl;

        cout << "\nSeleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {

        case 1:
            cout << "Ingrese el valor: ";
            cin >> valor;

            lista.insertar(valor);
            break;


        case 2:
            cout << "\nLista de inicio a fin:" << endl;
            lista.mostrarAdelante();
            break;


        case 3:
            cout << "\nLista de fin a inicio:" << endl;
            lista.mostrarAtras();
            break;


        case 4:
            cout << "Ingrese el valor a buscar: ";
            cin >> valor;

            lista.buscar(valor);
            break;


        case 5:
            cout << "Ingrese el valor a eliminar: ";
            cin >> valor;

            lista.eliminar(valor);
            break;


        case 6:
            cout << "Programa finalizado." << endl;
            break;


        default:
            cout << "Opcion no valida." << endl;
        }

    } while (opcion != 6);

    return 0;
}