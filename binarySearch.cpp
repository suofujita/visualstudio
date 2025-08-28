#include <iostream>
using namespace std;

/* Neu du lieu la mot so*/
 typedef  string dataType;
// typedef  float/double/... dataType;

void binarySearch(dataType* arr, int low, int high, dataType key, int& loc, bool& found) {
    if (low > high) {
        return;
    }
    loc = low + (high - low) / 2;
    if (arr[loc] == key) {
        found = true;
        return;
    }
    else if (key > arr[loc]) {
        binarySearch(arr, loc + 1, high, key, loc, found);
    }
    else {
        binarySearch(arr, low, loc - 1, key, loc, found);
    }
}

void findAllValues(dataType *arr, dataType key,int high, int loc) {
    int left = loc - 1;
    int right = loc + 1;
    cout << "Find in index " << loc << endl;
    while(left>0 && (arr[left]==key)) {
        cout << "Find in index " << left << endl;
        left--;
    }
    while (right<=high && (arr[right]==key)) {
        cout << "Find in index " << right << endl;
        right++;
    }

}

int main() {
    //dataType arr[] = { 2, 5, 8, 12, 16, 23, 38, 56, 72, 91 };
    string arr[]={ "alice", "bob", "bob", "bob", "carlos", "carol",
                      "craig", "dave", "erin", "eve",
                      "frank", "mallory", "oscar", "peggy",
                      "trent", "walter", "wendy", "wendy", "wendy", "wendy", "wendy", "wendy"};
    int loc = -1;
    int low = 0, high = sizeof(arr) / sizeof(arr[0]) - 1;
    bool found = false;
    binarySearch(arr, low, high, "wendy", loc, found);
    if (found == false) cout << "Found not in arr" << endl;
    else {
        findAllValues(arr,"wendy",high,loc);
    }
    return 0;
}
