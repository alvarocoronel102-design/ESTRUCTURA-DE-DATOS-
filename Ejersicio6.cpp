#include <iostream>
using namespace std;

int main () {
   
   // ==========================================
    // 1. BLOQUE DE DECLARACIÓN (INICIO)
    // ==========================================
    
    // FORMATO: {Fila, Columna, Valor}
    // Posición [0]: {TotalFilasOriginal, TotalColsOriginal, CantidadDatosReales}
    
    // Matriz A (Imagina una grilla de 4x4, pero que solo tiene 3 números)
    int A[4][3] = {
        {4, 4, 3},
        {0, 2, 5},  // Dato 1: En Fila 0, Columna 2 hay un 5
        {1, 1, 8},  // Dato 2: En Fila 1, Columna 1 hay un 8
        {3, 0, 2},
    };
  int B[3][3]  = {
      {4, 4, 2},  // Metadata: Matriz original 4x4. Tiene 2 datos.
        {1, 1, 4},  // Dato 1: En Fila 1, Columna 1 hay un 4 (¡Hará            match con la A!)
        {2, 3, 7}   // Dato 2: En Fila 2, Columna 3 hay un 7
    };
  int C[10][3];
  
  // 2. ENTRADA Y PREPARACIÓN (Calibrando la máquina)
 
    // ==========================================
    int m_A = A[0][2]; // Cantidad de datos reales en A (3)
    int m_B = B[0][2]; // Cantidad de datos reales en B (2)
    int m_C = 0;       // Total de datos finales (lo calcularemos al final)

    int i = 1; // Puntero para recorrer los datos de A (empieza en 1 para saltar la metadata)
    int j = 1; // Puntero para recorrer los datos de B
    int proxima_posicion_C = 1; // Puntero para escribir en C

    // ==========================================
    // 3. PROCESO (LÓGICA DE SUMA SPARSE)
    // ==========================================
    
    // FASE 1: Mientras ambas matrices tengan datos por comparar
    while (i <= m_A && j <= m_B) {
        
        // Comparamos Filas
        if (A[i][0] < B[j][0]) {
            C[proxima_posicion_C][0] = A[i][0];
            C[proxima_posicion_C][1] = A[i][1];
            C[proxima_posicion_C][2] = A[i][2];
            i++;
            proxima_posicion_C++;
        }
        else if (A[i][0] > B[j][0]) {
            C[proxima_posicion_C][0] = B[j][0];
            C[proxima_posicion_C][1] = B[j][1];
            C[proxima_posicion_C][2] = B[j][2];
            j++;
            proxima_posicion_C++;
        }
        else {
            // ¡Están en la misma FILA! Ahora desempatamos por COLUMNA
            if (A[i][1] < B[j][1]) {
                C[proxima_posicion_C][0] = A[i][0];
                C[proxima_posicion_C][1] = A[i][1];
                C[proxima_posicion_C][2] = A[i][2];
                i++;
                proxima_posicion_C++;
            }
            else if (A[i][1] > B[j][1]) {
                C[proxima_posicion_C][0] = B[j][0];
                C[proxima_posicion_C][1] = B[j][1];
                C[proxima_posicion_C][2] = B[j][2];
                j++;
                proxima_posicion_C++;
            }
            else {
                // ¡CHOQUE TOTAL! Misma Fila y Misma Columna. SE SUMAN.
                C[proxima_posicion_C][0] = A[i][0];
                C[proxima_posicion_C][1] = A[i][1];
                C[proxima_posicion_C][2] = A[i][2] + B[j][2]; // La suma de los valores
                i++;
                j++;
                proxima_posicion_C++;
            }
        }
    }

    // FASE 2: Si A todavía tiene datos pero B se acabó
    while (i <= m_A) {
        C[proxima_posicion_C][0] = A[i][0];
        C[proxima_posicion_C][1] = A[i][1];
        C[proxima_posicion_C][2] = A[i][2];
        i++;
        proxima_posicion_C++;
    }

    // FASE 3: Si B todavía tiene datos pero A se acabó
    while (j <= m_B) {
        C[proxima_posicion_C][0] = B[j][0];
        C[proxima_posicion_C][1] = B[j][1];
        C[proxima_posicion_C][2] = B[j][2];
        j++;
        proxima_posicion_C++;
    }

    // Guardamos la metadata final en la fila 0 de C
    m_C = proxima_posicion_C - 1; // Cantidad total de datos que quedaron en C
    C[0][0] = A[0][0]; // Filas originales de la grilla
    C[0][1] = A[0][1]; // Columnas originales de la grilla
    C[0][2] = m_C;     // Total de paquetes guardados

    // ==========================================
    // 4. SALIDA
    // ==========================================
    cout << "--- Resultado de la Suma (Matriz Sparse C) ---" << endl;
    cout << "Metadatos iniciales -> Grilla de " << C[0][0] << "x" << C[0][1] << " con " << C[0][2] << " datos." << endl;
    cout << "----------------------------------------------" << endl;
    
    // Imprimimos el arreglo a partir de la posición 1
    for (int k = 1; k <= m_C; k++) {
        cout << "Paquete " << k << ": [Fila " << C[k][0] << ", Columna " << C[k][1] << "] -> Valor = " << C[k][2] << endl;
    }

    return 0;

  
  
  
  
  
  
  
  
  
 }
