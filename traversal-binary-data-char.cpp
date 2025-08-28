#include <iostream>
using namespace std;
struct Btree{
    char data;
    Btree *left;
    Btree *right;
    Btree(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void preOrderTraversal(Btree *root){
    if(root==nullptr) return;
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Btree *root){
    if(root==nullptr) return;
    
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

void inOrderTraversal(Btree* root){
    if(root==nullptr) return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

int main(){
   Btree *node = new Btree('D');
   node->left = new Btree('B');
   node->right = new Btree('F');
   node->left->left = new Btree('C');
   node->left->right = new Btree('E');
   node->left->right->left = new Btree('H');
   node->right->left = new Btree('A');
   node->right->left->right = new Btree('I');
   node->right->left->right->left = new Btree('G');

   cout << "Pre-order binary tree traversal: "; preOrderTraversal(node); cout << endl;
   cout << "In-order binary tree traversal: "; inOrderTraversal(node); cout << endl;
   cout << "Post-order binary tree traversal: "; postOrderTraversal(node); cout << endl;

}