/* Cây nhị phân tìm kiếm với ví dụ dataType chỉ gồm 1 kiểu dữ liệu int */
#include <iostream>
using namespace std;

struct dataType {
    // giả sử key là 1 số nguyên
    int key;
    // các kiểu dữ liệu thành viên khác
};

struct treeNode {
    dataType* data;
    treeNode* leftChild;
    treeNode* rightChild;
    treeNode(dataType* p){
        data = new dataType;
        this->data = p;
        this->leftChild = nullptr;
        this->rightChild = nullptr;
    }
};

class BinarySearchTree {
    public:
        treeNode *root;
        int numElements;

        BinarySearchTree() {
        root = nullptr;
        numElements = 0;
    }
    /* kiểm tra cây rỗng */
    bool isEmpty();

    /* Thêm 1 nút */
    treeNode* insertNode(dataType *p, treeNode *root);

    /* Thêm đồng thời nhiều nút */ 
    void enterData(dataType *arr, int size);

    /* Xóa một phần tử */
    // hàm bổ trợ 
    treeNode* findLargest(treeNode *node);
    treeNode* deleteNode(int val, treeNode *root);

    /* Xóa toàn bộ cây*/ 
    // Sử dụng duyệt sau
    void deleteTree(treeNode *root);

    /* duyệt sau */
    void postOrderTravesal(treeNode *root);

    /* duyệt trước */
    void preOrderTravesal(treeNode *root);
    
    /* duyệt giữa */
    void inOrderTraversal(treeNode *root);
};

int main(){
        dataType sample[]= {{5},{7},{70},{80},{45},{105},{101},{102},{0},{-45},{100}};
        BinarySearchTree bst;
        // chèn dữ liệu sample vào cây
        bst.enterData(sample, 11);
        // In cây
        cout << "Before Deleting..." << endl;
        bst.inOrderTraversal(bst.root); cout << endl;
        // xóa giá trị 105 ra khỏi cây
        bst.root = bst.deleteNode(105, bst.root);
        // xóa giá trị -45 ra khỏi cây
        bst.root = bst.deleteNode(-45, bst.root);
        // xóa giá trị 7 ra khỏi cây
        bst.root = bst.deleteNode(7, bst.root);
        cout << "After Deleting..." << endl;
        // In cây
        bst.inOrderTraversal(bst.root); cout << endl;
        // giải phóng vùng nhớ
        bst.deleteTree(bst.root);
}













       



