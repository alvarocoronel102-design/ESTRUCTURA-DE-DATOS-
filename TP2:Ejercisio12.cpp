#include <iostream>

using namespace std;

// Tamaño de la memoria de la cola circular
const int N = 6; 

// --- ESTRUCTURA DE LA COLA CIRCULAR ---
struct ColaCircular {
    char Q[N];
    int frente;   // Índice del primer elemento
    int final;    // Índice del último elemento
    int cantidad; // Contador para saber cuántos elementos hay

    // Constructor: Preparamos el estado inicial del ejercicio 12
    ColaCircular() {
        // Llenamos visualmente con guiones bajos
        for (int i = 0; i < N; i++) {
            Q[i] = '_';
        }
        
        // Estado inicial del Ejercicio 12
        // C++ usa índices del 0 al 5, así que restamos 1 a las posiciones dadas (Frente=2, Final=4)
        Q[1] = 'A'; 
        Q[2] = 'C';
        Q[3] = 'D';
        
        frente = 1; // Apunta a la posición 2 ('A')
        final = 3;  // Apunta a la posición 4 ('D')
        cantidad = 3; // Hay 3 letras cargadas inicialmente
    }

    // Procedimiento AGREGAR en cola circular
    void agregar(char letra) {
        if (cantidad == N) {
            cout << "  -> Error: La cola esta LLENA." << endl;
        } else {
            // Avanzamos el final dando la vuelta si es necesario
            final = (final + 1) % N; 
            Q[final] = letra;
            cantidad++;
            cout << "  -> Se agrego: " << letra << endl;
        }
    }

    // Procedimiento ELIMINAR en cola circular
    void eliminar(char &letraEliminada) {
        if (cantidad == 0) {
            cout << "  -> Error: La cola esta VACIA." << endl;
        } else {
            letraEliminada = Q[frente];
            Q[frente] = '_'; // Borramos visualmente el elemento
            // Avanzamos el frente dando la vuelta si es necesario
            frente = (frente + 1) % N; 
            cantidad--;
            cout << "  -> Se elimino: " << letraEliminada << endl;
        }
    }

    // Función para mostrar el estado de la memoria en pantalla
    void mostrarEstado(string paso) {
        cout << "\n[" << paso << "]" << endl;
        // Le sumamos 1 a los punteros solo para mostrarlos como pide el TP (del 1 al 6)
        cout << "Frente: " << (frente + 1) << " | Final: " << (final + 1) << endl;
        cout << "Memoria: [ ";
        for (int i = 0; i < N; i++) {
            cout << Q[i];
            if (i < N - 1) cout << " , ";
        }
        cout << " ]\n" << endl;
    }
};

// --- PROGRAMA PRINCIPAL ---
int main() {
    ColaCircular miCola;
    char letraBorrada;

    cout << "=========================================" << endl;
    cout << " SIMULADOR DE COLA CIRCULAR (EJ. 12)" << endl;
    cout << "=========================================" << endl;

    miCola.mostrarEstado("Estado Inicial");

    // i). Se añade F a la cola [cite: 384]
    miCola.agregar('F');
    miCola.mostrarEstado("i) Despues de anadir F");

    // ii). Se eliminan 2 letras [cite: 385]
    miCola.eliminar(letraBorrada);
    miCola.eliminar(letraBorrada);
    miCola.mostrarEstado("ii) Despues de eliminar 2 letras");

    // iii). Se añade K, L y M a la cola [cite: 386]
    miCola.agregar('K');
    miCola.agregar('L');
    miCola.agregar('M');
    miCola.mostrarEstado("iii) Despues de anadir K, L y M");

    // iv). Se eliminan dos letras [cite: 387]
    miCola.eliminar(letraBorrada);
    miCola.eliminar(letraBorrada);
    miCola.mostrarEstado("iv) Despues de eliminar 2 letras");

    // v). Se añade R a la cola [cite: 388]
    miCola.agregar('R');
    miCola.mostrarEstado("v) Despues de anadir R");

    // vi). Se eliminan dos letras [cite: 389]
    miCola.eliminar(letraBorrada);
    miCola.eliminar(letraBorrada);
    miCola.mostrarEstado("vi) Despues de eliminar 2 letras");

    // vii). Se añade S a la cola [cite: 390]
    miCola.agregar('S');
    miCola.mostrarEstado("vii) Despues de anadir S (Estado Final)");

    return 0;
}
