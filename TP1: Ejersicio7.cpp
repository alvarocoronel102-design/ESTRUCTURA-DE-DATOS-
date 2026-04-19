#include <iostream>
using namespace std;

int main () {
    int A[4][3] = {
        {3, 7, 2},
        {1, 5, 0},
        {4, 6, 1},
        {2, 4, 3}
    };

    int filas = 4;
    int columnas = 3;
    bool existePuntoSilla = false; // <-- Tenía error acá (faltaba ;)

    for (int i = 0; i < filas; i++) {
        // A. Buscamos el MÁXIMO de la fila actual
        int max_fila = A[i][0];
        int col_max = 0;

        for (int j = 1; j < columnas; j++) {
            if (A[i][j] > max_fila) {
                max_fila = A[i][j];
                col_max = j; 
            }
        }
 
        // B. TEST VERTICAL
        bool es_punto_silla = true;
        for (int k = 0; k < filas; k++) {
            // Corregido: usamos minúsculas como las declaramos
            if (A[k][col_max] < max_fila) { 
                es_punto_silla = false;
                break;
            }
        }

        // C. RESULTADO
        if (es_punto_silla) {
            cout << "Punto silla encontrado!" << endl;
            cout << "Valor: " << max_fila << " en la posicion [" << i << "][" << col_max << "]" << endl;
            existePuntoSilla = true; // <-- Corregido: asignamos a la variable
            break; 
        }
    }

    if (!existePuntoSilla) {
        cout << "La matriz no tiene punto de silla." << endl;
    }

    return 0;
}
