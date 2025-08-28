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

void preOrderTravesal(Btree *root){
    if(root==nullptr) return;
    // code thực thi với nút {...}
    preOrderTravesal(root->left);
    preOrderTravesal(root->right);
}

int main(){
   Btree *node = new Btree(1);
   node->left = new Btree(2);
   node->right = new Btree(3);
   node->left->left = new Btree(4);
   node->left->right = new Btree(5);
   node->right->left = new Btree(6);
   node->right->right = new Btree(7);
   node->left->left->left  = new Btree(8);
   node->left->left->right = new Btree(9);
   node->left->right->left = new Btree(10);
   node->left->right->right = new Btree(11);
   node->right->left->left = new Btree(12);
   node->right->left->right = new Btree(13);
   node->right->right->left = new Btree(14);
   node->right->right->right = new Btree(15);




   preOrderTravesal(node);
   

}