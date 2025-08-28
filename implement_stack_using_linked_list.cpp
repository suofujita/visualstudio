#include <iostream>
#define cap 10
using namespace std;

struct stackNode {
    int data;
    stackNode* next;
};
class STACK {
    int n=0;
public:
// con tro top hay tmp không phải vùng nhớ kieu du lieu stackNode mà nó chỉ trỏ đến vùng nhớ kiểu dữ liệu stackNode
    stackNode* top = new stackNode;
    void Initial() {
        top = nullptr;
    }
    void push(stackNode *s, int value) {
          stackNode *tmp = new stackNode;
          tmp->data = value;
          tmp->next = top;
          top = tmp;
          n++;  
    }

    void pop(stackNode *s) {

    }
}




