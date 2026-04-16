#include <iostream>

using namespace std;

int main() {
    // Definimos los arreglos del primer ejemplo
    char A[] = {'A', 'M', 'A', 'D', 'O'};
    int n = 5; 

    char B[] = {'A', 'M', 'A', 'R', 'I', 'L', 'L', 'O'};
    int m = 5; 

    int resultado = 0; 
    bool diferencia_encontrada = false; 

    // ==========================================
    // PASO 1: Determinar el límite de seguridad
    // ==========================================
    int menor_tamano;
    
    if (n < m) {
        menor_tamano = n;
    } else {
        menor_tamano = m;
    }

    // ==========================================
    // PASO 2: Búsqueda de la primera diferencia
    // ==========================================
    for (int i = 0; i < menor_tamano; i++) {
        
        if (A[i] < B[i]) {
            resultado = -1;
            diferencia_encontrada = true;
            break; // Detenemos el bucle, ya encontramos el ganador
            
        } else if (A[i] > B[i]) {
            resultado = 1;
            diferencia_encontrada = true;
            break; // Detenemos el bucle
        }
        // Si A[i] == B[i], no hacemos nada, el bucle simplemente avanza a la siguiente letra.
    }

    // ==========================================
    // PASO 3: Desempate por longitud
    // ==========================================
    if (diferencia_encontrada == false) {
        
        if (n < m) {
            resultado = -1; // A es más corto, entonces A < B
        } else if (n > m) {
            resultado = 1;  // A es más largo, entonces A > B
        } else {
            resultado = 0;  // Son exactamente iguales en letras y tamaño
        }
        
    }

    // ==========================================
    // PASO 4: Impresión final
    // ==========================================
    cout << "El resultado de comparar A y B es: " << resultado << endl;

    return 0;
}
