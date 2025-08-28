#include <iostream>
using namespace std;
#include <vector>

void binarySearch(vector<int> arr, int lower, int upper, int key){
    int begin = lower;
    int end = upper;
    int pos = -1;
    while(begin<=end) {
       int mid = (begin+end)/2;
       if(arr[mid]==key) {
            pos = mid;
            return;
       }
       else if(arr[mid]>key) {
            end = mid-1;       
        }
        else {
            begin = mid + 1;
        }
        for(int i=begin;i<=end; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    if(pos==-1) cout << "khong ton tai";
}
int main() {
    vector<int> arr = {11,22,30,33,40,44,55,60,66,77,80,88,99};
    binarySearch(arr,0,12,75);
    return 0;
}