#include <iostream>
#include <string>
#include <sstream> // Librería clave para simular el NEXT-TOKEN

using namespace std;

const int N = 100;

// --- ESTRUCTURA DE LA PILA (Para números enteros) ---
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
};

// --- PROCEDIMIENTO DE EVALUACIÓN (PROC. EVAL) ---
int evaluarPosfijo(string expresion) {
    Pila miPila;
    
    // stringstream nos permite extraer los elementos separados por espacios
    // Esto simula a la perfección el "NEXT-TOKEN" de la teoría.
    stringstream nextToken(expresion); 
    string token;
    
    int op1, op2, resultadoFinal;

    // Recorremos token por token hasta que no quede nada
    while (nextToken >> token) {
        
        // Si el token es un operador, sacamos dos elementos, operamos y guardamos el resultado
        if (token == "+") {
            miPila.eliminar(op2); // Cuidado con el orden: el primero que sale es el operando derecho
            miPila.eliminar(op1);
            miPila.agregar(op1 + op2);
        } 
        else if (token == "-") {
            miPila.eliminar(op2);
            miPila.eliminar(op1);
            miPila.agregar(op1 - op2);
        } 
        else if (token == "*") {
            miPila.eliminar(op2);
            miPila.eliminar(op1);
            miPila.agregar(op1 * op2);
        } 
        else if (token == "/") {
            miPila.eliminar(op2);
            miPila.eliminar(op1);
            miPila.agregar(op1 / op2); // Asumimos divisiones exactas por simplicidad
        } 
        else {
            // Si no es ningún operador, significa que es un operando (un número).
            // La función stoi() convierte el texto ("12") en un número entero (12)
            miPila.agregar(stoi(token));
        }
    }
    
    // Al final del proceso, el único elemento que queda en la pila es el resultado total
    miPila.eliminar(resultadoFinal);
    return resultadoFinal;
}

// --- PROGRAMA PRINCIPAL ---
int main() {
    cout << "--- EVALUADOR DE EXPRESIONES (EJERCICIO 4) ---" << endl << endl;

    // Punto i
    string posfijo1 = "12 7 3 - / 2 1 5 + * +";
    cout << "i) Expresion original: 12/(7-3)+2*(1+5)" << endl;
    cout << "   Posfijo utilizado:  " << posfijo1 << endl;
    cout << "   Resultado Final:    " << evaluarPosfijo(posfijo1) << endl << endl;

    // Punto ii
    string posfijo2 = "30 2 + 4 / 15 + 3 5 * -";
    cout << "ii) Expresion original: (30+2)/4+15-3*5" << endl;
    cout << "    Posfijo utilizado:  " << posfijo2 << endl;
    cout << "    Resultado Final:    " << evaluarPosfijo(posfijo2) << endl << endl;

    // Punto iii
    string posfijo3 = "10 5 - 21 7 / *";
    cout << "iii) Expresion original: (10-5)*(21/7)" << endl;
    cout << "     Posfijo utilizado:  " << posfijo3 << endl;
    cout << "     Resultado Final:    " << evaluarPosfijo(posfijo3) << endl << endl;

    return 0;
}
