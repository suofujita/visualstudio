#include <iostream>
#include <vector>
using namespace std;

template <typename T>
int linearSearch(vector<T> arr, T key) {
    for(int i=0;i<arr.size();i++) {
        if(arr[i]==key) {
            return i;
        }
    }
    return -1;
}
int main(){
    vector<string> arr = {"meo","hi","suo","Hint"};
    int pos = linearSearch(arr, string("hi"));
    if(pos>=0) {
        cout << "Da tim thay tai index " << pos;
    }
    else {
        cout << "Khong tim thay";
    }
}