#include <iostream>
#include <vector>
using namespace std;
int main() {
    int i, j, k, count=0, icol=0, irow=0;
    vector<int> arr;
    for(i=1;i<7;i++) 
        for(j=1;j<7;j++)
            for(k=1;k<7;k++) {
               ++count;
               cout << count << " ";
               cout << i << j << k << " " << i+j+k << endl;
}

}