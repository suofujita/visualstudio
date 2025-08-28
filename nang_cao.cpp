#include <iostream>
#include <vector>
#define max 10
using namespace std;

struct pair_ {
    int key;
    int value;
};

struct map_ {
    pair_ data[max];
    int left, right;
    int size;
};

void Init(map_ *&ptr) {
    ptr->left = ptr->right = max/2;
    ptr->size = 0;
}

void addLeft(map_ *&ptr,int key, int value) {
    if(ptr->size==0) {
        ptr->data[ptr->left].key = key;
        ptr->data[ptr->left].value = value;
        ptr->size++;
        return;
    } 
    for(int i=ptr->left;i<=ptr->right;i++) {
        if(ptr->data[i].key == key) {
            ptr->data[i].value = value;
            return;
            }
        }
    if(ptr->left>0) {
            ptr->left--;
            ptr->data[ptr->left].key = key;
            ptr->data[ptr->left].value = value;
            ptr->size++;
    }
    else 
            cout << "Left full" << endl;   
}




void addRight(map_ *&ptr, int key, int value) {
if(ptr->size==0) {
        ptr->data[ptr->right].key = key;
        ptr->data[ptr->right].value = value;
        ptr->size++;
        return;
    } 
    for(int i=ptr->left;i<=ptr->right;i++) {
        if(ptr->data[i].key == key) {
            ptr->data[i].value = value;
            return;
            }
    }

    if(ptr->right < max-1) {
            ptr->right++;
            ptr->data[ptr->right].key = key;
            ptr->data[ptr->right].value = value;
            ptr->size++;
    }
    else 
            cout << "Right full" << endl; 
}

void remove(map_ *ptr, int k) {
    bool found = false;
    for(int i=ptr->left;i<=ptr->right;i++) {
        if(ptr->data[i].key == k) {
            found = true;
            for(int j=i; j<ptr->right;j++) {
                ptr->data[j] = ptr->data[j+1];
            }
            ptr->right--;
            ptr->size--;
            break;
        }
    }
    if(!found)
        cout << "Khong ton tai phan tu" << endl;
}