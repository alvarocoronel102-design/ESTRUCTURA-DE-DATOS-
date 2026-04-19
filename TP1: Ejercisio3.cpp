#include <iostream>
#include <cmath> // Para la función pow()

using namespace std;

int main() {
    // ==========================================
    // 1. BLOQUE DE DECLARACIÓN (INICIO)
    // ==========================================
    // Datos del Polinomio: 3x^2 - 5x + 2
    // Formato: {m, exp1, coef1, exp2, coef2, exp3, coef3}
    int P[] = {3, 2, 3, 1, -5, 0, 2}; 
    
    int m;                  // Cantidad de términos
    double Xo;              // Punto de evaluación
    double resultado_final; // Acumulador del total
    int i;                  // Contador para el bucle
    
    // Variables auxiliares para el proceso
    int indice_exponente;
    int indice_coeficiente;
    int exponente;
    int coeficiente;
    double valor_termino;

    // ==========================================
    // 2. ENTRADA Y PREPARACIÓN
    // ==========================================
    m = P[0];               // El primer elemento es la cantidad de términos
    resultado_final = 0.0;  // Siempre inicializamos el acumulador en 0
    
    cout << "--- Evaluador de Polinomios ---" << endl;
    cout << "Ingrese el valor de Xo: ";
    cin >> Xo;

    // ==========================================
    // 3. PROCESO (LÓGICA MATEMÁTICA)
    // ==========================================
    for (i = 0; i < m; i++) {
        
        // Calculamos los índices basándonos en i (0, 1, 2...)
        // Si i=0 -> exp en 1, coef en 2
        // Si i=1 -> exp en 3, coef en 4
        indice_exponente = 1 + (i * 2); 
        indice_coeficiente = 2 + (i * 2); // El coeficiente siempre está una posición después del exponente

        // Extraemos los valores del arreglo
        exponente = P[indice_exponente];
        coeficiente = P[indice_coeficiente];

        // Calculamos el valor de este término: b * (Xo ^ e)
        valor_termino = coeficiente * pow(Xo, exponente);

        // Sumamos al acumulador
        resultado_final = resultado_final + valor_termino;
    }

    // ==========================================
    // 4. SALIDA DE RESULTADOS
    // ==========================================
    cout << "El resultado de evaluar el polinomio es: " << resultado_final << endl;

    return 0;
}
