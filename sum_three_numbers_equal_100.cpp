#include <iostream>
using namespace std;
int main(){
    int i,j,k, count = 0;
    for(i=1;i<=100;i++)
        for(j=1;j<=100;j++)
            for(k=1;k<=100;k++) {
                int sum = i+j+k;
                if(sum==100) count++;
                cout << count << " " << i << " " << j << " " << k << endl;
            }
    
    cout << count;
}