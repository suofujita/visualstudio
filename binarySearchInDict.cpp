#include <iostream>
using namespace std;

struct dict {
    string key, meaning;
};
typedef  dict dataType;

void binarySearch(dataType* arr, int low, int high, string key, int& loc, bool& found) {
    if (low > high) {
        return;
    }
    loc = low + (high - low) / 2;
    if (arr[loc].key == key) {
        found = true;
        return;
    }
    else if (key > arr[loc].key) {
        binarySearch(arr, loc + 1, high, key, loc, found);
    }
    else {
        binarySearch(arr, low, loc - 1, key, loc, found);
    }
}

int main() {
    dataType arr[] = {
        {"ant", "con kien"},
        {"apple", "qua tao"},
        {"cherry", "qua anh dao"},
        {"monday", "thu hai"},
        {"moon", "mat trang"},
        {"peach" , "qua dao"},
        {"sun", "mat troi" },
        {"tree", "cai cay"}
    };
    int index = -1;
    int low = 0, high = sizeof(arr) / sizeof(arr[0]) - 1;
    bool found = false;
    binarySearch(arr, low, high, "apple", index, found);
 
    if (found == false) cout << "Found not in arr" << endl;
    else {
        cout << "Found in index " << index << endl;
    }
    return 0;
}
