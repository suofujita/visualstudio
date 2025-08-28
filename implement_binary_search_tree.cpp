#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* leftChild;
    Node* rightChild;
    Node(int data) {
        this->data = data;
        this->leftChild = nullptr;
        this->rightChild = nullptr;
    }
};

struct BinarySearchTree {
    Node* Root;
};

void Init(BinarySearchTree *bst){
    bst->Root = nullptr;
}

int isEmpty(BinarySearchTree *bst){
    return bst->Root==nullptr;
}

void postOrderTravesal(Node *p){
    if(p==nullptr) return;
    
    postOrderTravesal(p->leftChild);
    postOrderTravesal(p->rightChild);
    cout << p->data << " ";
}

void preOrderTravesal(Node *p){
    if(p==nullptr) return;
    cout << p->data << " ";
    preOrderTravesal(p->leftChild);
    preOrderTravesal(p->rightChild);
}

void inOrderTraversal(Node *p){
    if(p==nullptr) return;
    inOrderTraversal(p->leftChild);
    cout << p->data << " ";
    inOrderTraversal(p->rightChild);
}

Node* searchData(Node* p, int target) {
    if(p != nullptr) {
        if(p->data == target) return p;
        if(p->data > target) return searchData(p->leftChild,target);
        if(p->data < target) return searchData(p->rightChild,target);
    }
    return nullptr;
} 

int main() {
    BinarySearchTree *bst = new BinarySearchTree;
    Init(bst);
    bst->Root = new Node(46);
    bst->Root->leftChild = new Node(26);
    bst->Root->rightChild = new Node(76);
    bst->Root->leftChild->leftChild = new Node(24);
    bst->Root->leftChild->rightChild = new Node(30);
    bst->Root->leftChild->rightChild->leftChild = new Node(29);
    bst->Root->leftChild->rightChild->rightChild = new Node(34);
    bst->Root->rightChild->leftChild = new Node(58);
    bst->Root->rightChild->rightChild = new Node(80);
    bst->Root->rightChild->rightChild->leftChild = new Node(78);
    bst->Root->rightChild->rightChild->rightChild = new Node(96);
    cout << isEmpty(bst) << endl;

    postOrderTravesal(bst->Root); cout << endl;
    preOrderTravesal(bst->Root); cout << endl;
    inOrderTraversal(bst->Root); cout << endl;
    searchData(bst->Root, 50);
}
