#include <iostream>
using namespace std;

template <class dataType1, class dataType2>
class pair_ {
    public:
    dataType1 first;
    dataType2 second;
    // ham khoi tao mac dinh
    pair_();
    // ham tao khoi tao gia tri ban dau
    pair_(const dataType1 first, const dataType2 second) {
        this->first = first;
        this->second = second;
    }
    // ham tao copy
    pair_ (const pair_& p) {
        this->first = p.first;
        this->second = p.second;
    }
    // ham in ra pair
    void printPair() {
        cout << first << " " << second << endl;
    }
    // ham huy
    //~pair_();
};


int main() {
    pair_<int, char> pair1(100,'H'), pair2(pair1);
    //pair1.first = 100;
    //pair1.second = 'G';
    pair1.printPair();
    pair2.printPair();
}

