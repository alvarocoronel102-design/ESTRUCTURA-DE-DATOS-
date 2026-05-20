#include <iostream>

using namespace std;

// Funciones de error
void LLENA() {
    cout << "Error: La pila esta LLENA." << endl;
}

void VACIA() {
    cout << "Error: La pila esta VACIA." << endl;
}

// Procedimiento 1: AGREGAR
void AGREGAR(int x, int S[], int n, int &tope) {
    if (tope == n - 1) { 
        LLENA();
        return;
    }
    tope = tope + 1;
    S[tope] = x;
    cout << "-> Elemento " << x << " agregado con exito." << endl;
}

// Procedimiento 2: ELIMINAR
void ELIMINAR(int &x, int S[], int &tope) {
    if (tope < 0) { 
        VACIA();
        return;
    }
    x = S[tope];
    tope = tope - 1;
    cout << "-> Se elimino el elemento: " << x << endl;
}

// Programa principal que controla los dos procedimientos
int main() {
    int n = 5;           // Dimension de la pila
    int S[5];            // El vector de la pila
    int tope = -1;       // Pila vacia al inicio
    int x;               // Variable temporal
    int opcion;          // Variable para elegir el procedimiento

    do {
        // Menu para separar las acciones
        cout << "\n--- GESTION DE PILA ---" << endl;
        cout << "1. Ejecutar procedimiento AGREGAR" << endl;
        cout << "2. Ejecutar procedimiento ELIMINAR" << endl;
        cout << "3. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            cout << "Que numero deseas agregar?: ";
            cin >> x;
            AGREGAR(x, S, n, tope);
        } 
        else if (opcion == 2) {
            ELIMINAR(x, S, tope);
        }

    } while (opcion != 3);

    return 0;
}
