#include <iostream>
using namespace std;
struct Btree{
    int data;
    Btree *left;
    Btree *right;
    Btree(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void postOrderTravesal(Btree *root){
    if(root==nullptr) return;
    
    postOrderTravesal(root->left);
    postOrderTravesal(root->right);
    cout << root->data << " ";
}

int main(){
   Btree *node = new Btree(60);
   node->left = new Btree(50);
   node->right = new Btree(70);
   node->left->left = new Btree(10);
   node->left->right = new Btree(30);
   node->right->left = new Btree(20);
   node->right->right = new Btree(40);
   postOrderTravesal(node);
   
   

}