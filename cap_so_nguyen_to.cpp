#include <iostream>
#include <math.h>
using namespace std;
int isPrime(int n) {
   for(int i=2;i<=sqrt(n);i++) {
        if(n%i==0) return 0;
   }
   return 1;
}
int main(){
    int i, j,k;
    for(i=6;i<31;i=i+2) {
        cout << i << " ";
        for(j=2;j<=i/2;j++) {
            if(isPrime(j)==1) {
                for(k=j;k<=i;k++){
                    if(isPrime(k)==1 && (j+k==i)) {
                            cout << " = " << j << " + " << k;
                        }
                    }
                }
            }    
        cout << endl;
    }
    return 0;
}