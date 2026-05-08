#include <iostream>

using namespace std;

const int N = 100;

// --- ESTRUCTURA DE LA PILA ---
struct Pila {
    int S[N];
    // Iniciamos el tope en 0. Al agregar, sumamos 1, 
    // así el primer elemento queda en la posición 1, respetando la teoría.
    int tope = 0; 

    void agregar(int x) {
        if (tope < N - 1) {
            tope++;
            S[tope] = x;
        }
    }

    void eliminar(int &x) {
        if (tope > 0) {
            x = S[tope];
            tope--;
        }
    }

    bool estaVacia() {
        return tope == 0;
    }
};

// --- PROGRAMA PRINCIPAL ---
int main() {
    Pila pilaOriginal;
    Pila pilaAuxiliar; // Generamos la pila extra que pide el ejercicio

    // Llenamos la pila con 5 elementos.
    // Recuerda que el primero en entrar es la BASE (posicion 1)
    pilaOriginal.agregar(8); // Posicion 1
    pilaOriginal.agregar(7); // Posicion 2
    pilaOriginal.agregar(3); // Posicion 3 <-- ¡Este coincide con su posicion!
    pilaOriginal.agregar(9); // Posicion 4
    pilaOriginal.agregar(1); // Posicion 5 (TOPE)

    cout << "--- BUSCADOR Y ELIMINADOR EN PILA ---" << endl;
    cout << "Buscando el elemento que coincide con su posicion..." << endl;

    int extraido;
    int posicionActual;

    // FASE 1: Vaciamos la pila original buscando el elemento
    while (!pilaOriginal.estaVacia()) {
        // Guardamos la posicion actual antes de sacarlo (porque al sacarlo, el tope baja)
        posicionActual = pilaOriginal.tope; 
        
        pilaOriginal.eliminar(extraido);

        if (extraido == posicionActual) {
            cout << "-> ¡Encontrado! El numero " << extraido << " estaba en la posicion " << posicionActual << ". Se elimina." << endl;
            // Al no hacer nada mas aqui, el numero "desaparece" (lo eliminamos)
        } else {
            // Si no es el que buscamos, lo resguardamos en la pila auxiliar
            pilaAuxiliar.agregar(extraido);
        }
    }

    // FASE 2: Restauramos la pila original
    // Volcamos la auxiliar de regreso a la original para que recuperen su orden
    while (!pilaAuxiliar.estaVacia()) {
        pilaAuxiliar.eliminar(extraido);
        pilaOriginal.agregar(extraido);
    }

    cout << "\nProceso terminado. La pila original ha sido restaurada sin ese elemento." << endl;

    return 0;
}
