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

    // Función rápida para saber si está vacía
    bool estaVacia() {
        return tope == 0;
    }
};

// --- PROCEDIMIENTO PARA VERIFICAR PARÉNTESIS ---
bool verificarParentesis(string expresion) {
    Pila miPila;
    char temp; // Variable temporal para cuando usemos "eliminar"

    // Recorremos la expresión carácter por carácter
    for (int i = 0; i < expresion.length(); i++) {
        
        // Si es un paréntesis que ABRE, lo metemos a la pila
        if (expresion[i] == '(') {
            miPila.agregar('(');
        }
        // Si es un paréntesis que CIERRA, intentamos emparejarlo
        else if (expresion[i] == ')') {
            
            // Si la pila está vacía, significa que cerramos un paréntesis que nunca abrimos
            if (miPila.estaVacia()) {
                return false; 
            } else {
                // Si hay elementos, sacamos el último '(' que entró
                miPila.eliminar(temp);
            }
        }
    }
    
    // Al finalizar de leer todo, la pila DEBE estar vacía.
    // Si miPila.estaVacia() es true, están balanceados. Si quedó algo (false), faltó cerrar.
    return miPila.estaVacia(); 
}

// --- PROGRAMA PRINCIPAL ---
int main() {
    string expresionMatematica;

    cout << "--- VALIDADOR DE EXPRESIONES MATEMATICAS ---" << endl;
    cout << "Ingrese una expresion (ej: (A+B)*(C-D) ): ";
    cin >> expresionMatematica;

    if (verificarParentesis(expresionMatematica)) {
        cout << "\n[VALIDO] ¡Los parentesis estan perfectamente balanceados!" << endl;
    } else {
        cout << "\n[INVALIDO] Error: Los parentesis NO estan balanceados." << endl;
    }

    return 0;
}
