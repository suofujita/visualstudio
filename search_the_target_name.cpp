#include <iostream>
using namespace std;

int searchName (string key, string arr[], int size) {
    for(int i=0;i<size;i++)
        if(arr[i] == key) return i;
    return -1;
}

int main(){
    string names[]={ "alice", "bob", "carlos", "carol",
                      "craig", "dave", "erin", "eve",
                      "frank", "mallory", "oscar", "peggy",
                      "trent", "walter", "wendy"};
    int size = sizeof(names)/sizeof(names[0]);
    cout << searchName("oscar", names, size);
    return 0;
}