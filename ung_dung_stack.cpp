#include <iostream>
#include <stack>
using namespace std;
#include <vector>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
       void inorder(TreeNode* root, vector<int> &arr) {
               if(root==nullptr) return;
               inorder(root->left, arr);
               arr.push_back(root->val);
               inorder(root->right, arr);
           }
        vector<int> inorderTraversal(TreeNode* root) {
           vector<int> arr;
           inorder(root, arr);
           return arr;
     }
   
};
int main(){
    TreeNode *root = new TreeNode(1);
    TreeNode *n1 = new TreeNode(2);
    root->left = n1;
    TreeNode *n2 = new TreeNode(3);
    root->right = n2;
    TreeNode *n3 = new TreeNode(4);
    n1->left = n3; 
    TreeNode *n4 = new TreeNode(5); 
    n1->right = n4;
    TreeNode *n5 = new TreeNode(8);
    n2->right = n5; 
    TreeNode *n6 = new TreeNode(6);
    n4->left = n6;
    TreeNode *n7 = new TreeNode(7);
    n4->right = n7; 
    TreeNode *n8 = new TreeNode(9);
    n5->left = n8;
    Solution sol;
    vector<int> arr = sol.inorderTraversal(root);
    for(int i: arr) {
        cout << i << " ";
    }

}