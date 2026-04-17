#include <iostream>


using namespace std;

int main() {
    // ==========================================
    // 1. BLOQUE DE DECLARACIÓN (INICIO)
    // ==========================================
    // Datos del Polinomio: 3x^2 - 5x + 2
    // Formato: {m, exp1, coef1, exp2, coef2, exp3, coef3}
    int P[] = {3, 2, 3, 1, -5, 0, 2}; 
    int D[20] ; //maximo de derrivdas, podemos poner mas o menos 
    int m_original;  
    int m_derrivada= 0;
      
    int i;                  // Contador para el bucle
    
    // Variables auxiliares para el proceso
    int indice_exponente_P;
    int indice_coeficiente_P;
    int proxima_posicion_D = 1; //sustituimos por los exponentes y coeficeintes de la derrivada
    int exponente_viejo;
    int coeficiente_viejo;
    int exponente_nuevo;
    int coeficiente_nuevo;
    

    // ==========================================
    // 2. ENTRADA Y PREPARACIÓN
    // ==========================================
    m_original = P[0];               // El primer elemento es la cantidad de términos
   
    


    // ==========================================
    // 3. PROCESO (LÓGICA MATEMÁTICA)
    // ==========================================
    for (i = 0; i < m_original; i++) {
        
        // Calculamos los índices basándonos en i (0, 1, 2...)
        // Si i=0 -> exp en 1, coef en 2
        // Si i=1 -> exp en 3, coef en 4
        indice_exponente_P = 1 + (i * 2); 
        indice_coeficiente_P = 2 + (i * 2); // El coeficiente siempre está una posición después del exponente

        // Extraemos los valores del arreglo
        exponente_viejo = P[indice_exponente_P];
        coeficiente_viejo = P[indice_coeficiente_P];

  
 if(exponente_viejo > 0 ) {
  coeficiente_nuevo =  exponente_viejo * coeficiente_viejo;
  exponente_nuevo = exponente_viejo-1;
  
  D[proxima_posicion_D] = exponente_nuevo;   // Guardamos el exp
  D[proxima_posicion_D + 1] = coeficiente_nuevo; // Guardamos el coef
            
            // 4. ACTUALIZAMOS LOS CONTADORES
            proxima_posicion_D = proxima_posicion_D + 2; // Saltamos 2 lugares en D
            m_derrivada = m_derrivada + 1;               // Contamos un término más
        }
}
    // Al terminar el bucle, guardamos en la posición 0 cuántos términos sobrevivieron
    D[0] = m_derrivada;
cout << "--- Resultado de la Derivada ---" << endl;
    cout << "Arreglo D = { " << D[0]; // Imprimimos la cantidad de términos
    
    // Este bucle imprime los pares (exponente, coeficiente) que guardamos en D
    for (i = 1; i < (1 + m_derrivada * 2); i++) {
        cout << ", " << D[i];
    }
    
    cout << " }" << endl;
    cout << "Representacion: ";
    
    // Un toque extra para que se vea como un polinomio real
    // Corregimos el orden: Primero el coeficiente, luego el exponente
    for (i = 0; i < m_derrivada; i++) {
        // Multiplicamos i*2 para saltar de par en par
        // El coeficiente está en la posición (2, 4, 6...) -> 2 + i*2
        // El exponente está en la posición (1, 3, 5...)   -> 1 + i*2
        
        cout << D[2 + i*2] << "x^" << D[1 + i*2] << " ";
        
        if (i < m_derrivada - 1) cout << ", ";
    }
    cout << endl;
    return 0;
}
