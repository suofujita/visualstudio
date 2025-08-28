#include <iostream>
#include <string.h>
using namespace std;
#define max 100
struct dataType {
    char key[max];
    char meaning[max];
};
struct treeNode {
    dataType *data; 
    treeNode *leftChild;
    treeNode *rightChild;
    treeNode(dataType *p) {
        this->data = p;
        this->leftChild = nullptr;
        this->rightChild = nullptr;
    }
};

struct BinarySearchTree {
    treeNode *root;
};

void init(BinarySearchTree *bst){
    bst->root = nullptr;
}

// in cay
void postOrderTravesal(treeNode *p){
    if(p==nullptr) return;
    
    postOrderTravesal(p->leftChild);
    postOrderTravesal(p->rightChild);
    cout << p->data->key << " : " << p->data->meaning << endl;
}
// nhập dữ liệu

int main() {
    BinarySearchTree *bst = new BinarySearchTree;
    init(bst);
    dataType *ptr = new dataType;
    strcpy(ptr->key, "apple");
    strcpy(ptr->meaning, "qua tao");
    bst->root = new treeNode(ptr);
    postOrderTravesal(bst->root);


    // giải phóng
    delete ptr;
    delete bst->root;
    delete bst;
}

