#include <iostream>
#include <string>

using namespace std;

// Tamaño de la memoria de la cola
const int N = 6; 

// --- ESTRUCTURA DE LA COLA CIRCULAR ---
struct ColaCircular {
    string Q[N];
    int frente;   // Índice del primer elemento
    int final;    // Índice del último elemento
    int cantidad; // Contador para saber si está llena o vacía

    // Constructor: Preparamos el estado inicial del ejercicio
    ColaCircular() {
        // Llenamos visualmente con espacios vacíos
        for (int i = 0; i < N; i++) {
            Q[i] = "_";
        }
        
        // Estado inicial del Ejercicio 13
        // C++ usa índices del 0 al 5, así que restamos 1 a las posiciones dadas (2 a 5)
        Q[1] = "Londres"; 
        Q[2] = "Berlin";
        Q[3] = "Roma";
        Q[4] = "Paris";
        
        frente = 1; // Apunta a la posición 2 (Londres)
        final = 4;  // Apunta a la posición 5 (Paris)
        cantidad = 4; // Hay 4 ciudades cargadas
    }

    // Procedimiento AGREGAR en cola circular
    void agregar(string ciudad) {
        if (cantidad == N) {
            cout << "  -> Error: La cola esta LLENA." << endl;
        } else {
            // La fórmula mágica de la cola circular usando el operador módulo (%)
            final = (final + 1) % N; 
            Q[final] = ciudad;
            cantidad++;
            cout << "  -> Se agrego: " << ciudad << endl;
        }
    }

    // Procedimiento ELIMINAR en cola circular
    void eliminar(string &ciudadEliminada) {
        if (cantidad == 0) {
            cout << "  -> Error: La cola esta VACIA." << endl;
        } else {
            ciudadEliminada = Q[frente];
            Q[frente] = "_"; // Borramos visualmente el elemento
            // El frente también da la vuelta con el operador módulo
            frente = (frente + 1) % N; 
            cantidad--;
            cout << "  -> Se elimino: " << ciudadEliminada << endl;
        }
    }

    // Función para mostrar el estado de la memoria
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
    string ciudadBorrada;

    cout << "=========================================" << endl;
    cout << " SIMULADOR DE COLA CIRCULAR (EJ. 13)" << endl;
    cout << "=========================================" << endl;

    miCola.mostrarEstado("Estado Inicial");

    // i). Se añade Atenas
    miCola.agregar("Atenas");
    miCola.mostrarEstado("i) Despues de anadir Atenas");

    // ii). Se eliminan dos ciudades
    miCola.eliminar(ciudadBorrada);
    miCola.eliminar(ciudadBorrada);
    miCola.mostrarEstado("ii) Despues de eliminar 2 ciudades");

    // iii). Se añade Madrid
    miCola.agregar("Madrid");
    miCola.mostrarEstado("iii) Despues de anadir Madrid (Da la vuelta)");

    // iv). Se elimina Paris 
    // (Aclaración: Por regla FIFO, eliminamos el que está al frente, que es Roma)
    miCola.eliminar(ciudadBorrada); 
    miCola.mostrarEstado("iv) Despues de eliminar el frente (Roma)");

    // v). Se añade Moscú
    miCola.agregar("Moscu");
    miCola.mostrarEstado("v) Despues de anadir Moscu");

    // vi). Se eliminan tres ciudades
    miCola.eliminar(ciudadBorrada);
    miCola.eliminar(ciudadBorrada);
    miCola.eliminar(ciudadBorrada);
    miCola.mostrarEstado("vi) Despues de eliminar 3 ciudades (El Frente da la vuelta)");

    // vii). Se añade Oslo
    miCola.agregar("Oslo");
    miCola.mostrarEstado("vii) Despues de anadir Oslo (Estado Final)");

    return 0;
}
