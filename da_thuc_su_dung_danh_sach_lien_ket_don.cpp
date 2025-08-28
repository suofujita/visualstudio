#include <iostream>
using namespace std;
#include <math.h>

struct Node {
    int heSo;
    int bac;
    Node *next;
    Node(int heSo, int bac) {
        this->heSo = heSo;
        this->bac = bac;
        this->next = nullptr;
    }
};

struct Polynomial {
    Node *head, *tail;
    Polynomial() {
        head = tail = nullptr;
    }
};

bool isEmpty(Polynomial &po) {
    return po.head == nullptr;
}
void insertEnd(Polynomial &po, int heSo, int bac){
    Node *curr = new Node(heSo, bac);
    if(isEmpty(po)) {
        po.head = po.tail = curr;
        return ;
    }
    Node *tmp = po.tail; 
    po.tail->next = curr;
    po.tail = curr;
}
void printList(Polynomial &po) {
    if(isEmpty(po)) return;
    Node *tmp = po.head;
    while(tmp != nullptr) {
        cout << "He so bac " << tmp->bac << ": " << tmp->heSo << endl;
        tmp = tmp->next;
    } 
}

double calculateFun(Polynomial &po, double x) {
    Node *tmp = po.head;
    double result = po.tail->heSo;
    while(tmp->next != nullptr) {
        result += pow(x, tmp->bac)*tmp->heSo;
        tmp = tmp->next;
    }
    return result;
}

int main(){
    Polynomial ptr;
    insertEnd(ptr, 6,3);
    insertEnd(ptr, 9,2);
    insertEnd(ptr, 7,1);
    insertEnd(ptr, 1,0);
    printList(ptr);
    cout << calculateFun(ptr, 1) << endl;
}