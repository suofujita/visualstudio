#include <iostream>
using namespace std;

int modPrime(int k) {
    return k%97;  // sẽ có 97 ô nhớ không bị đụng độ
}
int midSquareHashing(int k) {
    // trả về các số ở giữa
    long long key;
    key = k*k;

}
int main() {
    for(int i=0;i<97;i++) {
        cout << modPrime(i) << " ";
    }
}
