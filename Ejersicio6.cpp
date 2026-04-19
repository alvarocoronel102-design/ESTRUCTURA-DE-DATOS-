#include <iostream>
using namespace std;

int main () {
    int A[4][4] = {
        {0, 0, 5, 0},
        {0, 8, 0, 0},
        {0, 0, 0, 0},
        {2, 0, 0, 0}
    };
    int M[10][3]; 
    int k = 1;
    int i, j;
for(int i = 0; i < 4;  i++) {
for(int j=  0;   j < 3;j++)  {
    if (A[i][j] !=0){
    M[k][0]= i ;
    M[k][1]= j;
    M[k][2]= A[i][j];
    k=k+1;
    
    }
    
   }
  }
 M[0][0]=4;
 M[0][1]=3;
 M[0][2]=k-1;
 
 cout<< "Matris Sparce Generada: "<< endl;
 cout << "Metadata: " << M[0][0] << "x" << M[0][1] << " con " << M[0][2] << " datos." << endl;
    
    for (int n = 1; n <= M[0][2]; n++) {
        cout << "Dato " << n << ": [" << M[n][0] << "," << M[n][1] << "] = " << M[n][2] << endl;
    }
 
 return 0;
}
