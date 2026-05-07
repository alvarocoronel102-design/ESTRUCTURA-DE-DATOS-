#include <iostream>

using namespace std;

// Definimos la capacidad máxima de la pila según el ejercicio
const int N = 8; 

struct Pila {
    char elementos[N];
    int tope;

    // Constructor: Inicializa la pila
    Pila() {
        tope = -1; // -1 indica que la pila está vacía
        // Llenamos el arreglo con '_' para simular visualmente las celdas vacías
        for(int i = 0; i < N; i++) {
            elementos[i] = '_';
        }
    }

    // Verifica si la pila está llena
    bool estaLlena() {
        return tope == N - 1;
    }

    // Verifica si la pila está vacía
    bool estaVacia() {
        return tope == -1;
    }

    // Función METER (Push)
    void meter(char item) {
        if (!estaLlena()) {
            tope++; // Movemos el tope una posición arriba
            elementos[tope] = item; // Insertamos el elemento
        } else {
            cout << "Error: La pila está LLENA (Desbordamiento/Overflow)" << endl;
        }
    }

    // Función SACAR (Pop)
    void sacar(char &item) {
        if (!estaVacia()) {
            item = elementos[tope]; // Guardamos el valor que está en el tope
            elementos[tope] = '_';  // Limpiamos visualmente la celda
            tope--;                 // Movemos el tope una posición abajo
        } else {
            cout << "Error: La pila está VACÍA (Subdesbordamiento/Underflow)" << endl;
        }
    }

    // Función auxiliar para mostrar el estado actual de la pila
    void mostrar() {
        cout << "PILA: ";
        for (int i = 0; i < N; i++) {
            cout << elementos[i];
            if (i < N - 1) cout << ", ";
        }
        cout << "   (El TOPE está en la posición " << tope << ")" << endl;
    }
};

int main() {
    Pila miPila;
    char itemExtraido;

    // --- CONFIGURACIÓN DEL ESTADO INICIAL ---
    // Ingresamos los elementos para que queden: A, C, D, F, K
    miPila.meter('A');
    miPila.meter('C');
    miPila.meter('D');
    miPila.meter('F');
    miPila.meter('K');
    
    cout << "--- ESTADO INICIAL ---" << endl;
    miPila.mostrar();
    cout << "\n=========================================\n\n";

    // --- EJECUCIÓN DE LOS PASOS DEL EJERCICIO ---

    // a. Sacar(PILA, Item)
    cout << "a. Sacar(PILA, Item)" << endl;
    miPila.sacar(itemExtraido);
    cout << "   -> Item extraido: " << itemExtraido << endl;
    miPila.mostrar();
    cout << "-----------------------------------------" << endl;

    // b. Sacar(PILA, Item)
    cout << "b. Sacar(PILA, Item)" << endl;
    miPila.sacar(itemExtraido);
    cout << "   -> Item extraido: " << itemExtraido << endl;
    miPila.mostrar();
    cout << "-----------------------------------------" << endl;

    // c. Meter (PILA, L)
    cout << "c. Meter(PILA, 'L')" << endl;
    miPila.meter('L');
    miPila.mostrar();
    cout << "-----------------------------------------" << endl;

    // d. Meter (PILA, P)
    cout << "d. Meter(PILA, 'P')" << endl;
    miPila.meter('P');
    miPila.mostrar();
    cout << "-----------------------------------------" << endl;

    // e. Sacar(PILA, Item)
    cout << "e. Sacar(PILA, Item)" << endl;
    miPila.sacar(itemExtraido);
    cout << "   -> Item extraido: " << itemExtraido << endl;
    miPila.mostrar();
    cout << "=========================================\n";

    return 0;
}
