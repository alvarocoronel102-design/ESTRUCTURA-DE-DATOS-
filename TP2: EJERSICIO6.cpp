#include <iostream>
#include <string>

using namespace std;

const int N = 100; // Capacidad máxima de la pila

// --- ESTRUCTURA DE LA PILA ---
struct Pila {
    char S[N]; 
    int tope = 0; 

    // Procedimiento para agregar (Push)
    void agregar(char x) {
        if (tope < N) {
            tope = tope + 1;
            S[tope] = x;    
        }
    }

    // Procedimiento para eliminar (Pop)
    void eliminar(char &x) {
        if (tope > 0) {
            x = S[tope];    
            tope = tope - 1;
        }
    }
};

// --- PROCEDIMIENTO PARA DETERMINAR SI ES CAPICÚA ---
bool esCapicua(string palabra) {
    Pila miPila;
    int longitud = palabra.length();

    // Paso 1: Metemos todas las letras de la palabra en la pila
    for (int i = 0; i < longitud; i++) {
        miPila.agregar(palabra[i]);
    }

    // Paso 2: Sacamos las letras y las comparamos con la palabra original
    char letraExtraida;
    for (int i = 0; i < longitud; i++) {
        miPila.eliminar(letraExtraida);
        
        // Si la letra original no coincide con la letra sacada de la pila (que viene al revés)
        if (palabra[i] != letraExtraida) {
            return false; // No es capicúa, cortamos la ejecución acá
        }
    }
    
    // Si terminamos de revisar todas las letras y nunca falló, entonces sí es capicúa
    return true; 
}

// --- PROGRAMA PRINCIPAL ---
int main() {
    string palabraIngresada;

    cout << "--- DETECTOR DE PALABRAS CAPICUAS ---" << endl;
    cout << "Ingrese una palabra (sin espacios ni mayusculas): ";
    cin >> palabraIngresada;

    // Llamamos a nuestro procedimiento
    if (esCapicua(palabraIngresada)) {
        cout << "\n¡Excelente! La palabra '" << palabraIngresada << "' ES capicua." << endl;
    } else {
        cout << "\nLa palabra '" << palabraIngresada << "' NO es capicua." << endl;
    }

    return 0;
}
