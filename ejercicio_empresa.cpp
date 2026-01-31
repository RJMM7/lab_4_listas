#include <iostream>
using namespace std;

// Estructura del nodo
struct Nodo {
    int id;
    string nombre;
    float peso;
    Nodo* sig;
    Nodo* ant;

};

// ----------------------------------------------------------------
// Funcion que verifica si hay ID repetido
Nodo* verificadorID(Nodo* head, int id) {
    Nodo* actual = head;

    while (actual != nullptr) {
        if (actual->id == id) {
            return actual;
        }
        actual = actual->sig;
    }
    return nullptr;
}

// ----------------------------------------------------------------
// Funcion insertar paquete al final
void insertarFinal(Nodo*& head, Nodo*& tail) {
    int id;
    cout << "Digite el ID: ";
    cin >> id;

    // Verifica si el ID ya existe
    if(verificadorID(head, id) != nullptr) {
        cout << "El ID digitado ya existe" << endl;
        return;
    }

    Nodo* nuevo = new Nodo;

    nuevo->id = id;
    cout << "Ingrese nombre del paquete: ";
    cin.ignore();
    getline(cin, nuevo->nombre);

    cout << "Ingrese el peso del paquete (kg): ";
    cin >> nuevo->peso;

    nuevo->sig = nullptr;
    nuevo->ant = tail;

    if(tail == nullptr) {
        head = tail = nuevo;
    } else {
        tail->sig = nuevo;
        tail = nuevo;
    }

    cout << "Paquete insertado al final correctamente" << endl;
}

// ----------------------------------------------------------------
// Funcion insertar paquete al inicio
void insertarInicio(Nodo*& head, Nodo*& tail) {
    int id;
    cout << "Digite el ID: ";
    cin >> id;

    // Verifica si el ID ya existe
    if(verificadorID(head, id) != nullptr) {
        cout << "El ID digitado ya existe" << endl;
        return;
    }

    Nodo* nuevo = new Nodo;

    nuevo->id = id;
    cout << "Ingrese nombre del paquete: ";
    cin.ignore();
    getline(cin, nuevo->nombre);

    cout << "Ingrese el peso del paquete (kg): ";
    cin >> nuevo->peso;

    nuevo->ant = nullptr;
    nuevo->sig = head;

    if(head == nullptr) {
        head = tail = nuevo;
    } else {
        head->ant = nuevo;
        head = nuevo;
    }

    cout << "Paquete insertado al inicio correctamente" << endl;
}

int main() {

    Nodo* head = nullptr;
    Nodo* tail = nullptr;

    int opcion;
    
    do {
        // Menu de opciones
        cout << "---------------- MENU ----------------" << endl;
        cout << "1. Insertar paquete al final" << endl;
        cout << "2. Insertar paquete al inicio" << endl;
        cout << "3. Mostrar lista adelante (desde head a tail)" << endl;
        cout << "4. Mostrar lista atras (desde tail a head)" << endl;
        cout << "5. Buscar paquete por ID" << endl;
        cout << "6. Eliminar paquete por ID" << endl;
        cout << "7. Mostrar cantidad de paquetes (contador o recorrido)" << endl;
        cout << "8. Salir" << endl;
        cout << "Digite su opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                insertarFinal(head, tail);
                break;

            case 2:
                insertarInicio(head, tail);
                break;

            case 3:
                break;

            case 4:
                break;

            case 5:
                break;

            case 6:
                break;

            case 7:
                break;

            case 8:
                cout << "Saliendo...";
                break;

            default:
                cout << "Error en la seleccion, vuelva a intentarlo" << endl;
                break;
        }

    } while(opcion != 8);
    
    return 0;
}