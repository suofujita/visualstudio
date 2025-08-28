#include <iostream>
using namespace std;
// thuat toan Euclid mo rong

int main(){
    int a=0, b=1, a_=1, b_=0, c, d, q, r,t;
    c=222; d=97;
    q=c/d;
    r=c%d;
    while(r != 0) {
        c = d; d = r;
        t = a_; a_ = a; a = t - q*a;
        t = b_; b_ = b; b = t - q*b;
        r = c%d;
        q = c/d;
    }
    cout << "(" << a << ", " << b << ")" << endl;
}