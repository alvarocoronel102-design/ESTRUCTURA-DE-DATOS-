// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
   int L[5] = {10, 20, 30, 40, 50};
   int n=5;
   int x;
   cout<<"ingrese el valor del numero";
   cin >> x;
   int posicion=-1; 
   for (int i= 0; i< n; i++) {
       if (L[i] == x){
           posicion =i;
           break;
           
       }
       if(posicion !=-1){
           cout<<"el numero encontrado es la posicion" ;
         
       }
       else{
           cout<<"el elemento no se encuentra en la lista " ;
           
       }
   }
   
   
   
    return 0;
}
