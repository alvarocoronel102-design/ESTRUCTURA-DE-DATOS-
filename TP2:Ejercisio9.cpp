#include <iostream>

using namespace std;

const int N = 100;

// --- ESTRUCTURA DE LA PILA (Invierte los impares) ---
struct Pila {
    int S[N];
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

    bool estaVacia() { return tope == 0; }
    
    // Nos permite ver el número sin sacarlo de la pila
    int verTope() { return S[tope]; } 
};

// --- ESTRUCTURA DE LA COLA (Mantiene el orden de los pares) ---
struct Cola {
    int Q[N];
    int front = 0; // Apunta a uno antes del primer elemento
    int rear = 0;  // Apunta al último elemento

    void agregar(int x) {
        if (rear < N - 1) {
            rear++;
            Q[rear] = x;
        }
    }

    void eliminar(int &x) {
        if (front < rear) {
            front++;
            x = Q[front];
        }
    }

    bool estaVacia() { return front == rear; }
    
    // Nos permite ver el número sin sacarlo de la cola
    int verFrente() { return Q[front + 1]; }
};

// --- PROGRAMA PRINCIPAL ---
int main() {
    // Simulamos la lista original mezclada (Pares crecientes, Impares decrecientes)
    int listaMezclada[] = {2, 9, 4, 7, 3, 6, 8, 1};
    int cantidadElementos = 8;
    
    Pila pilaImpares;
    Cola colaPares;

    cout << "--- ORDENADOR DE PARES E IMPARES ---" << endl;
    cout << "Lista original: 2, 9, 4, 7, 3, 6, 8, 1\n" << endl;

    // FASE 1: Separar los números
    for (int i = 0; i < cantidadElementos; i++) {
        int numero = listaMezclada[i];
        
        if (numero % 2 == 0) {
            // Es PAR: Va a la COLA para mantener su orden
            colaPares.agregar(numero);
        } else {
            // Es IMPAR: Va a la PILA para invertir su orden
            pilaImpares.agregar(numero);
        }
    }

    // FASE 2: Fusión (Merge) en orden creciente
    int listaFinal[N];
    int indiceFinal = 0;
    int extraido;

    // Mientras ambas estructuras tengan números para comparar
    while (!colaPares.estaVacia() && !pilaImpares.estaVacia()) {
        
        // Comparamos el frente de la cola con el tope de la pila
        if (colaPares.verFrente() < pilaImpares.verTope()) {
            colaPares.eliminar(extraido);
        } else {
            pilaImpares.eliminar(extraido);
        }
        
        listaFinal[indiceFinal] = extraido;
        indiceFinal++;
    }

    // FASE 3: Vaciar lo que haya sobrado
    // (Si se acabaron los impares, metemos todos los pares que quedaron, y viceversa)
    while (!colaPares.estaVacia()) {
        colaPares.eliminar(extraido);
        listaFinal[indiceFinal] = extraido;
        indiceFinal++;
    }

    while (!pilaImpares.estaVacia()) {
        pilaImpares.eliminar(extraido);
        listaFinal[indiceFinal] = extraido;
        indiceFinal++;
    }

    // RESULTADO
    cout << "Lista final ordenada de forma creciente: ";
    for (int i = 0; i < cantidadElementos; i++) {
        cout << listaFinal[i] << " ";
    }
    cout << endl;

    return 0;
}
