#include <iostream>
using namespace std;
// thuat toan Euclid
int ucln(int m, int n) {
    if(m==0 || n==0)
        return -1;
    int r = m%n;
    while(r != 0) {
        m = n;
        n = r;
        r = m%n;
    }
    return n;
}
int main(){
    cout << ucln(32,24);
}