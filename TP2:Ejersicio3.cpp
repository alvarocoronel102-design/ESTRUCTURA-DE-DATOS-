#include <iostream>
#include <string>

using namespace std;

const int N = 100;

// --- ESTRUCTURA DE LA PILA ---
struct Pila {
    char S[N];
    int tope = 0;

    void agregar(char x) {
        if (tope < N - 1) {
            tope++;
            S[tope] = x;
        }
    }

    void eliminar(char &x) {
        if (tope > 0) {
            x = S[tope];
            tope--;
        }
    }

    // Función extra para "mirar" qué hay en el tope sin sacarlo
    char verTope() {
        if (tope > 0) return S[tope];
        return '#'; // Usamos '#' para representar el fondo de la pila o vacío
    }
};

// --- PRIORIDAD EN PILA (PP) ---
int PP(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    if (op == '(') return 0; // El paréntesis en la pila tiene la menor prioridad
    if (op == '#') return -1; 
    return -1;
}

// --- PRIORIDAD EN EXPRESIÓN (PE) ---
int PE(char op) {
    if (op == '^') return 4;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    if (op == '(') return 4; // El paréntesis en la expresión tiene la mayor prioridad
    return -1;
}

// Verifica si el carácter es una letra (operando)
bool esOperando(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

// --- PROCEDIMIENTO PRINCIPAL ---
void infijoAPosfijo(string expresion) {
    Pila miPila;
    miPila.agregar('#'); // Metemos un símbolo base para no intentar sacar de una pila vacía
    
    string posfijo = "";
    char temp;

    for (int i = 0; i < expresion.length(); i++) {
        char x = expresion[i];

        // Regla 1: Si es operando (letra), va directo al resultado
        if (esOperando(x)) {
            posfijo += x;
        } 
        // Regla 2: Si es ')', vaciamos la pila hasta encontrar el '('
        else if (x == ')') {
            while (miPila.verTope() != '(' && miPila.verTope() != '#') {
                miPila.eliminar(temp);
                posfijo += temp;
            }
            miPila.eliminar(temp); // Sacamos y descartamos el '(' de la pila
        } 
        // Regla 3: Si es un operador o '('
        else {
            // Mientras la prioridad en pila sea MAYOR O IGUAL a la de la expresión...
            while (PP(miPila.verTope()) >= PE(x)) {
                miPila.eliminar(temp);
                posfijo += temp; // ...sacamos de la pila y lo mandamos al resultado
            }
            // Finalmente, metemos el operador actual a la pila
            miPila.agregar(x);
        }
    }

    // Regla 4: Al terminar de leer la expresión, vaciamos lo que haya quedado en la pila
    while (miPila.verTope() != '#') {
        miPila.eliminar(temp);
        posfijo += temp;
    }

    cout << "  Expresion Infija (Original): " << expresion << endl;
    cout << "  Expresion Posfija (Resultado): " << posfijo << endl << endl;
}

int main() {
    cout << "--- RESOLUCION DEL EJERCICIO 3 ---" << endl << endl;

    // Nota: Usamos el símbolo '^' en lugar de la flecha hacia arriba para la potencia
    
    cout << "Punto i):" << endl;
    infijoAPosfijo("A+(B*C-(D/E^F)*G)*H");

    cout << "Punto ii):" << endl;
    infijoAPosfijo("(A-B)*(D/E)");

    cout << "Punto iii):" << endl;
    infijoAPosfijo("((A+B)*D)^(E-F)");

    return 0;
}
