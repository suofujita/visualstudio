#include <iostream>
#include <string.h>
using namespace std;
#define max 1000
// xây dựng cấu trúc từ điển
struct dict {
    char key[max];
    char meaning[max];
};

// dữ liệu mẫu
dict sampleDict[] = {
        { "apple", "qua tao"},
        {"peach" , "qua dao"},
        {"cherry", "qua anh dao"},
        {"ant", "con kien"},
        {"monday", "thu hai"},
        {"moon", "mat trang"},
        {"sun", "mat troi" },
        {"tree", "cai cay"}
    };
struct treeNode {
    dict *word; 
    treeNode *leftChild;
    treeNode *rightChild;
    // khởi tạo
    treeNode(dict *p) {
        this->word = p;
        this->leftChild = nullptr;
        this->rightChild = nullptr;
    }
};
//  cây nhị phân tìm kiếm
struct BinarySearchTree {
    treeNode *root;
};
// khởi tạo cây nhị phân tìm kiếm
void init(BinarySearchTree *bst){
    bst->root = nullptr;
}
/*  hàm duyệt cây */
// left - right – root 
void postOrderTravesal(treeNode *p){
    if(p==nullptr) return;
    postOrderTravesal(p->leftChild);
    postOrderTravesal(p->rightChild);
    cout << p->word->key << " : " << p->word->meaning << endl;
}
// left – root – right
// in từ theo thứ tự bảng chữ cái abc
void inOrderTraversal(treeNode *p){
    if(p==nullptr) return;
    inOrderTraversal(p->leftChild);
    cout << p->word->key << ": " << p->word->meaning << endl;
    inOrderTraversal(p->rightChild);
}
/* Thêm từ vựng*/
// bổ sung từng từ một
treeNode* insertNode(dict *p, treeNode *node){
    if(node==nullptr) {
        return new treeNode(p);
    }
    if(strcmp(p->key,node->word->key)>0) {
        node->rightChild = insertNode(p,node->rightChild);
    }
    else if(strcmp(p->key,node->word->key)==0) {
        return node;
    }
    else {
        node->leftChild = insertNode(p,node->leftChild);
    }
    return node;
}
/* Nhập dữ liệu từ vựng từ cơ sở dữ liệu mẫu */
// bổ sung thêm nhiều dữ liệu cùng 1 lúc
void enterData(BinarySearchTree *bst) {
    int i;
    int dataSize = sizeof(sampleDict) / sizeof(sampleDict[0]);
    for(i=0;i<dataSize;i++) {
        bst->root = insertNode(&sampleDict[i], bst->root);
    }
}
int main() {
    BinarySearchTree *bst = new BinarySearchTree;
    init(bst);
// kiểm tra xem từ điển có rỗng không

// nhập 1 loạt từ từ sampleDict
    enterData(bst);
// in tất cả từ trong từ điển
    inOrderTraversal(bst->root);
// thêm một từ bất kì ví dụ "rose" "hoa hong"

 // in lại từ điển

 // tìm kiếm một từ 

 // giải phóng vùng nhớ
    delete bst->root;
    delete bst;
}


