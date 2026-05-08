#include <iostream>
#include <string>

using namespace std;

const int N = 100; // Capacidad máxima de la pila

// --- ESTRUCTURA DE LA PILA ---
struct Pila {
    char S[N]; 
    int tope = 0; 

    void agregar(char x) {
        if (tope < N) {
            tope = tope + 1;
            S[tope] = x;    
        }
    }

    void eliminar(char &x) {
        if (tope > 0) {
            x = S[tope];    
            tope = tope - 1;
        }
    }

    bool estaVacia() {
        return tope == 0;
    }
};

// --- FUNCIÓN AUXILIAR PARA VERIFICAR PAREJAS ---
// Nos devuelve true solo si el símbolo de apertura y el de cierre hacen "match"
bool sonPareja(char apertura, char cierre) {
    if (apertura == '(' && cierre == ')') return true;
    if (apertura == '[' && cierre == ']') return true;
    if (apertura == '{' && cierre == '}') return true;
    return false;
}

// --- PROCEDIMIENTO PARA VERIFICAR TODOS LOS SIGNOS ---
bool verificarAgrupamiento(string expresion) {
    Pila miPila;
    char simboloExtraido; 

    for (int i = 0; i < expresion.length(); i++) {
        char actual = expresion[i];

        // 1. Si es cualquier símbolo de APERTURA, va a la pila
        if (actual == '(' || actual == '[' || actual == '{') {
            miPila.agregar(actual);
        }
        // 2. Si es cualquier símbolo de CIERRE, lo evaluamos
        else if (actual == ')' || actual == ']' || actual == '}') {
            
            // Si llega un cierre y la pila está vacía, hay un error
            if (miPila.estaVacia()) {
                return false; 
            } else {
                // Sacamos el último símbolo que se abrió
                miPila.eliminar(simboloExtraido);
                
                // Comparamos: ¿el que sacamos hace pareja con el de cierre actual?
                if (!sonPareja(simboloExtraido, actual)) {
                    return false; // Error: Se cruzaron los símbolos (ej: abriste '[' pero cerraste ')')
                }
            }
        }
    }
    
    // Al final, la pila debe estar vacía para ser válida
    return miPila.estaVacia(); 
}

// --- PROGRAMA PRINCIPAL ---
int main() {
    string expresionMatematica;

    cout << "--- VALIDADOR AVANZADO DE EXPRESIONES ---" << endl;
    cout << "Ingrese una expresion (ej: {[(A+B)*C]-D} ): ";
    cin >> expresionMatematica;

    if (verificarAgrupamiento(expresionMatematica)) {
        cout << "\n[VALIDO] ¡Todos los signos estan perfectamente balanceados!" << endl;
    } else {
        cout << "\n[INVALIDO] Error: Los signos se cruzan o no estan balanceados." << endl;
    }

    return 0;
}
