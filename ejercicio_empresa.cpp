#include <iostream>
using namespace std;

struct Nodo {
    int id;
    string nombre;
    float peso;
    Nodo* sig;
    Nodo* ant;

};

int main() {

    int opcion;
    
    do {
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
                break;
            case 2:
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
                cout << "Error en la seleccion" << endl;
                break;
        }

    } while(opcion =! 8);
    
    return 0;
}