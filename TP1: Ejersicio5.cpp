#include <iostream>
#include <string>

using namespace std;

// ==========================================
// 1. PROCEDIMIENTO (El Motor de los 2 Dedos)
// ==========================================
void darAumento(string A[][3], int n, string B[][3], int m) {
    int i = 0; // Puntero para la matriz A (Empleados)
    int j = 0; // Puntero para la matriz B (Alumnos)

    // Mientras no lleguemos al final de ninguna de las dos listas
    while (i < n && j < m) {
        
        // CASO 1: Los apellidos coinciden
        if (A[i][0] == B[j][0]) {
            
            // Si el apellido es igual, desempatamos con el nombre
            if (A[i][1] == B[j][1]) {
                // ¡BINGO! Encontramos a alguien que está en ambas listas.
                
                // Convertimos el texto del promedio a un número para poder evaluarlo
                float promedio = stof(B[j][2]); 
                
                if (promedio > 7.0) {
                    // Convertimos el texto del sueldo a número
                    float sueldo = stof(A[i][2]);
                    
                    // Aplicamos el aumento del 10% (multiplicar por 1.10)
                    sueldo = sueldo * 1.10; 
                    
                    // Lo volvemos a guardar como texto en la matriz A
                    A[i][2] = to_string(sueldo); 
                }
                
                // Avanzamos AMBOS punteros porque ya procesamos a esta persona
                i++;
                j++;
            } 
            // Si el nombre de A va antes alfabéticamente
            else if (A[i][1] < B[j][1]) {
                i++;
            } 
            // Si el nombre de B va antes
            else {
                j++;
            }
        } 
        // CASO 2: El apellido de A va antes alfabéticamente (ej. A="Alvarez", B="Blanco")
        else if (A[i][0] < B[j][0]) {
            i++;
        } 
        // CASO 3: El apellido de B va antes alfabéticamente
        else {
            j++;
        }
    }
}

// ==========================================
// 2. PROGRAMA PRINCIPAL (La Fábrica)
// ==========================================
int main() {
    
    // Matriz A (Empleados): {Apellido, Nombre, Sueldo}
    // ¡IMPORTANTE: Ordenados alfabéticamente!
    string Empleados[3][3] = {
        {"Alvarez", "Juan", "1000"},
        {"Blanco", "Maria", "1200"},
        {"Gomez", "Pedro", "1500"}
    };
    
    // Matriz B (Alumnos): {Apellido, Nombre, Promedio}
    // ¡IMPORTANTE: Ordenados alfabéticamente!
    string Alumnos[3][3] = {
        {"Blanco", "Maria", "8.5"}, // Esta coincide con empleado y tiene > 7
        {"Gomez", "Pedro", "5.0"},  // Esta coincide pero tiene < 7
        {"Juarez", "Ana", "9.0"}    // Solo alumna
    };

    // Mostramos cómo están los sueldos ANTES
    cout << "--- SUELDOS ANTES DEL PROCESO ---" << endl;
    for(int i = 0; i < 3; i++) {
        cout << Empleados[i][0] << ", " << Empleados[i][1] << ": $" << Empleados[i][2] << endl;
    }
    cout << "---------------------------------" << endl << endl;

    // Ejecutamos el procedimiento mágico
    // Le pasamos la matriz de empleados, su tamaño (3), la de alumnos y su tamaño (3)
    darAumento(Empleados, 3, Alumnos, 3);

    // Mostramos cómo quedaron los sueldos DESPUÉS
    cout << "--- SUELDOS DESPUES DEL AUMENTO ---" << endl;
    for(int i = 0; i < 3; i++) {
        cout << Empleados[i][0] << ", " << Empleados[i][1] << ": $" << Empleados[i][2] << endl;
    }
    cout << "-----------------------------------" << endl;

    return 0;
}
