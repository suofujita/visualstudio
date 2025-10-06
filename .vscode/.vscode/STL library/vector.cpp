#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

bool comp(int a, int b) {
    return a > b;
}

/*You are required to complete below methods*/

/*inserts an element x at
the back of the vector A */
void add_to_vector(vector<int> &A, int x) {
    // Your code here
    A.push_back(x);
}

/*sort the vector A in ascending order*/
void sort_vector_asc(vector<int> &A) {
    
    // Your code here
    sort(A.begin(), A.end());
}

/*reverses the vector A*/
    
void reverse_vector(vector<int> &A) {
    // Your code here
    reverse(A.begin(), A.end());
}

    
/*returns the size of the vector  A */
int size_of_vector(vector<int> &A) {
    // Your code here
    return A.size();
}
    

/*sorts the vector A in descending order*/
void sort_vector_desc(vector<int> &A) {
    // Your code here
    sort(A.begin(), A.end(), comp);
}
    

/*prints space separated
elements of vector A*/
void print_vector(vector<int> &A) {
    // Your code here
    for(int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }
}
int main(){
    vector<int> v = {1, 2, 2, 4, 8,10};
    print_vector(v);
    return 0;
}