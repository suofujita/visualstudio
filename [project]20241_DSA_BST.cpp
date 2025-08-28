#include <iostream>
using namespace std;

struct treeNode {
    // giả sử khóa là 1 số nguyên
    int key;
    treeNode* leftChild;
    treeNode* rightChild;
};

class BinarySearchTree {
public:
    treeNode* root;                                // điểm truy nhập
    int numElements;                               // số lượng nút
    /* Các thao tác */
    BinarySearchTree();                            // khởi tạo cây
    treeNode* createNode(int val);                  // tạo một nút mới
    bool isEmpty();                                // kiểm tra cây rỗng
    void postOrderTravesal(treeNode* root);        // duyệt sau
    void preOrderTravesal(treeNode* root);         // duyệt trước
    void inOrderTraversal(treeNode* root);         // duyệt giữa
    treeNode* insertNode(int val, treeNode* root); // thêm một nút mới
    void readData(int* arr, int size);             // thêm đồng thời nhiều nút mới
    treeNode* findLargestNode(treeNode* node);     // hàm tìm nút thay thế cho nút cần xóa
    treeNode* deleteNode(int val, treeNode* root); // xóa một nút
    void deleteTree(treeNode* root);               // xóa toàn bộ cây
    treeNode* findNode(int val, treeNode* root);   // tìm kiếm nút
};
/* Khởi tạo cây */
BinarySearchTree::BinarySearchTree() {
    root = nullptr;
    numElements = 0;
}
/* Tạo một nút mới */
treeNode* BinarySearchTree::createNode(int val) {
    treeNode* node = new treeNode;
    node->key = val;
    node->leftChild = node->rightChild = nullptr;
    return node;
}
/* Kiểm tra cây rỗng */
bool BinarySearchTree::isEmpty() {
    if (root == nullptr)
        return true;
    return false;
}
/* Duyệt sau */
void BinarySearchTree::postOrderTravesal(treeNode* root) {
    if (root == nullptr) return;
    postOrderTravesal(root->leftChild);
    postOrderTravesal(root->rightChild);
    std::cout << root->key << " ";
}
/* Duyệt trước */
void BinarySearchTree::preOrderTravesal(treeNode* root) {
    if (root == nullptr) return;
    std::cout << root->key << " ";
    preOrderTravesal(root->leftChild);
    preOrderTravesal(root->rightChild);
}
/* Duyệt giữa */
void BinarySearchTree::inOrderTraversal(treeNode* root) {
    if (root == nullptr) return;
    inOrderTraversal(root->leftChild);
    std::cout << root->key << " ";
    inOrderTraversal(root->rightChild);
}
/* Thêm một nút mới */
treeNode* BinarySearchTree::insertNode(int val, treeNode* root) {
    /* cây rỗng */
    if (root == nullptr) {
        root = createNode(val);
        numElements++;
        return root;
    }
    /* cây không rỗng */
    // so sánh key để tìm vị trí thêm nút
    if (val > root->key) {
        // duyệt tiếp đến con phải của nút
        root->rightChild = insertNode(val, root->rightChild);
    }
    else if (val < root->key) {
        // duyệt tiếp đến con trái của nút
        root->leftChild = insertNode(val, root->leftChild);
    }
    else {
        // val == root->key không cần chèn trả về nút gốc
        return root;
    }
    // trả về nút gốc
    return root;
}
/* Thêm đồng thời nhiều nút mới */
void BinarySearchTree::readData(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        root = insertNode(arr[i], root);
    }
}
/* Xóa một phần tử */
// Case 1: Nút cần xóa là lá
// Case 2: Nút cần xóa có 1 con
// Case 3: Nút cần xóa có 2 con
// hàm bổ trợ 
treeNode* BinarySearchTree::findLargestNode(treeNode* node) {
    if (node == nullptr || node->rightChild == nullptr)
        return node;
    else
        return findLargestNode(node->rightChild);
}
treeNode* BinarySearchTree::deleteNode(int val, treeNode* root) {
    // kiểm tra cây rỗng
    if (root == nullptr) {
        return nullptr;
    }
    if (val > root->key) {
        root->rightChild = deleteNode(val, root->rightChild);
    }
    else if (val < root->key) {
        root->leftChild = deleteNode(val, root->leftChild);
    }
    else {
        // đã tìm được nút cần xóa
        // kiểm tra xem nút nằm trong trường hợp nào
        // case: nút có hai con
        if (root->leftChild != nullptr && root->rightChild != nullptr) {
            // phải nhất của con trái
            treeNode* tmp = findLargestNode(root->leftChild);
            root->key = tmp->key;
            root->leftChild = deleteNode(tmp->key, root->leftChild);
        }
        else {
            // trường hợp có tối đa 1 con
            // cho con trỏ tmp trỏ đến nút cần xóa
            treeNode* tmp = root;
            // case: nút có 1 con trái
            if (root->leftChild != nullptr) {
                root = root->leftChild;
            }
            // case: nút có 1 con phải
            else {
                root = root->rightChild;
            }
            delete tmp;
            numElements--;
        }
    }
    return root;
}
/* Tìm kiếm một nút */
treeNode* BinarySearchTree::findNode(int val, treeNode *root) {
    if (root == nullptr) return nullptr;
    if (val > root->key) {
        return findNode(val, root->rightChild);
    }
    else if (val < root->key) {
        return findNode(val, root->leftChild);
    }
    else {
        return root;
    }
}
void BinarySearchTree::deleteTree(treeNode* root) {
    if (root != nullptr) {
        deleteTree(root->leftChild);
        deleteTree(root->rightChild);
        delete root;
        numElements--;
        root = nullptr;
    }
}
int main() {
    int sample[] = { 5,7,70,80,45,105,101,103,0,-45,100 };
    BinarySearchTree bst;
    // chèn dữ liệu sample vào cây
    bst.readData(sample, 11);
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




