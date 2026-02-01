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

// ----------------------------------------------------------------
// Funcion mostrar lista adelante (desde head a tail)
void mostrarAdelante(Nodo* head) {
    // Verifica si la lista esta vacia
    if(head == nullptr) {
        cout << "La lista esta vacia" << endl;
        return;
    }

    // Si la lista no esta vacia, muestra los datos de la lista
    Nodo* actual = head;
    while(actual != nullptr) {
        cout << "-> ID: " << actual->id
            << ", Nombre: " << actual->nombre
            << ", Peso: " << actual->peso << endl;
        actual = actual->sig;
    }
}

// ----------------------------------------------------------------
// Funcion mostrar lista atras (desde tail a head)
void mostrarAtras(Nodo* tail) {
    // Verifica si la lista esta vacia
    if(tail == nullptr) {
        cout << "La lista esta vacia" << endl;
        return;
    }

    // Si la lista no esta vacia, muestra los datos de la lista
    Nodo* actual = tail;
    while(actual != nullptr) {
        cout << "-> ID: " << actual->id
            << ", Nombre: " << actual->nombre
            << ", Peso: " << actual->peso << endl;
        actual = actual->ant;
    }
}

/*Funcion buscar paquete por ID*/
void buscarPorID (Nodo* head){
    if(head == nullptr) {
        cout << "La lista esta vacia\n";
        return;
    }
    int ID;
    cout << "Digite el ID a buscar: ";
    cin>> ID;

    Nodo* encontrado = verificadorID(head, ID);
    
    if(encontrado == nullptr){
        cout << "No se encontro ningun paquete con el ID: " << ID << '\n';

    } else {
        cout << "Paquete encontrado: \n";
        cout << "ID: " << encontrado->id << '\n';
        cout << " , nombre: " << encontrado->nombre
        << ", peso: " << encontrado->peso << "Kg " << '\n';
    }
}

/*PUNTO EXTRA
OPCION B*/
void editarPaquetePorID(Nodo* head) {
    if (head == nullptr) {
        cout << "La lista esta vacia.\n";
        return;
    }

    int id;
    cout << "Digite el ID del paquete a editar: ";
    cin >> id;

    Nodo* encontrado = verificadorID(head, id);
    if (encontrado == nullptr) {
        cout << "No se encontro el paquete.\n";
        return;
    }

    cout << "Ingrese el NUEVO nombre (sin espacios): ";
    cin >> encontrado->nombre;

    cout << "Ingrese el NUEVO peso (kg): ";
    cin >> encontrado->peso;

    cout << "Paquete editado correctamente.\n";
}

bool eliminarPorID( Nodo*& head, Nodo*& tail) {
    if(head == nullptr) {
        cout << "La lista esta vacia, no hay nada que eliminar. \n";
        return false; 
    }
    int id;
    cout << " Digite el id a eliminar: ";
    cin >> id;

    Nodo* actual = verificadorID(head, id);
    if(actual == nullptr) {
        cout << "No se encontro el paquete con ID " << id << endl;
        return false;
    }
    /*caso con 1 nodo*/
    if(head == tail){ 
        delete actual;
        head = tail = nullptr;
        cout << "Paquete eliminado (era el unico en la lista) " << endl;
        return true;
    }
    /*borrar head*/
    if(actual == head) {
        head = head->sig;
        head->ant = nullptr;
        delete actual;
        cout << "Paquete eliminado ( se elimino el primero). \n";
        return true;
    }
    /*borrar tail*/
    if(actual == tail) {
        tail = tail->ant;
        tail->sig = nullptr;
        delete actual;
        cout << "Paquete eliminado (se elimino el ultimo). \n";
        return true;
    }
    /*borrar en medio*/
    actual->ant->sig = actual->sig;
    actual->sig->ant = actual->ant;

    delete actual;
    cout << "Paquete eliminado (se elimino un nodo de en medio). \n";
    return true;
}
int contarPaquetes(Nodo* head) {
    int contador = 0;
    Nodo* actual = head;

    while(actual != nullptr) {
        contador++;
        actual = actual->sig;
    }
    return contador;
}

void liberarLista (Nodo*& head, Nodo*& tail){
    Nodo* actual = head;
        while(actual != nullptr) {
            Nodo* aux = actual;
            actual = actual->sig;
            delete aux; 
        }
        head = nullptr;
        tail = nullptr;
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
                mostrarAdelante(head);
                break;

            case 4:
                mostrarAtras(tail);
                break;

            case 5:
            buscarPorID(head);
                break;

            case 6:
            eliminarPorID(head, tail);
                break;

            case 7:
            cout<< "Cantidad de paquetes " << contarPaquetes(head) << endl;
                break;

            case 8:
                cout << "Saliendo...";
                break;

            default:
                cout << "Error en la seleccion, vuelva a intentarlo" << endl;
                break;
        }

    } while(opcion != 8);

    liberarLista(head, tail);
    
    return 0;
}