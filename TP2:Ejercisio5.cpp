#include <iostream>

using namespace std;

const int N = 1000; // Capacidad máxima de la pila 

// --- ESTRUCTURA DE LA PILA SIMPLIFICADA ---
struct Pila {
    int S[N]; 
    int tope = 0; // Inicializamos el tope [cite: 53]

    // Procedimiento para agregar [cite: 59]
    void agregar(int x) {
        if (tope < N) {
            tope = tope + 1; // [cite: 60]
            S[tope] = x;     // [cite: 61]
        }
    }

    // Procedimiento para eliminar [cite: 64]
    void eliminar(int &x) {
        if (tope > 0) {
            x = S[tope];     // [cite: 65]
            tope = tope - 1; // [cite: 67]
        }
    }
    
    // Función rápida para saber si hay elementos
    bool estaVacia() {
        return tope == 0;
    }
};

int main() {
    Pila miPila;
    int inicial, final, numero;

    cout << "--- GENERADOR DE RANGOS ---" << endl;
    cout << "Ingrese el numero inicial (ej. 1): ";
    cin >> inicial;
    cout << "Ingrese el numero final (ej. 99): ";
    cin >> final;

    // FASE 1: Llenado automático en forma creciente
    // El bucle genera los números y los mete a la pila al instante
    for (int i = inicial; i <= final; i++) {
        miPila.agregar(i);
    }

    // FASE 2: Impresión decreciente usando la propiedad LIFO de la Pila
    cout << "\nLos numeros en orden decreciente son:\n";
    while (!miPila.estaVacia()) {
        miPila.eliminar(numero);
        cout << numero << " ";
    }
    
    cout << "\n\nPrograma finalizado con exito." << endl;

    return 0;
}
