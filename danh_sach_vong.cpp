#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void Init(Node*& first) {
    first = nullptr;
}

void insertBegin(Node*& first, int data) {
    Node* curr = new Node;
    curr->data = data;
    if(first==nullptr) {
        curr->next = curr;
        first = curr;
        return;
    }
    Node *tmp = first;
    while(tmp->next != first) {
        tmp = tmp->next;
    }
    tmp->next = curr;
    curr->next = first;
    first = curr;
}

void insertAtEnd(Node*& first, int data) {
    Node *curr = new Node;
    curr->data = data;
    // danh sach rong
    if(first == nullptr) {
        curr->next = curr;
        first = curr;
        return;
    }
    Node *tmp = first;
    while(tmp->next != first) 
        tmp = tmp->next;
    tmp->next = curr;
    curr->next = first;
}
void deleteBegin(Node*& first) {
    // danh sach rong
    if(first==nullptr) 
        return;
    // danh sach co 1 nut
    if(first->next == first) {
        delete first;
        first = nullptr;
        return ;
    }
    Node *tmp = first;
    while(tmp->next != first) {
        tmp = tmp->next;
    }
    tmp->next = first->next;
    delete first;
    first = tmp->next;
}
void deleteAtEnd(Node*& first) {
    // danh sach khong co nut nao
    if(first==nullptr) 
        return;
    // danh sach co 1 nut
    if(first->next == first) {
        delete first;
        first = nullptr;
        return;
    }
    // danh sach co 2 nut tro len
    Node* curr = first;
    Node* preCurr = nullptr;
    while(curr->next != first) {
        preCurr = curr;
        curr = curr->next;
    }
    preCurr->next = first;
    delete curr;
}

void deleteList(Node*& first) {
    while(first != nullptr) {
        deleteAtEnd(first);
    }
}

void print(Node* first) {
    if(first==nullptr) {
        cout << "empty" << endl;
        return;
    }
    Node *tmp = first;
    do {
        cout << tmp->data << " ";
        tmp = tmp->next;
    } while(tmp != first);
    cout << endl;
}
int main(){
    Node *first;
    Init(first);
    insertBegin(first, 2);
    insertBegin(first, 4);
    insertBegin(first, 6);
    print(first);
    deleteAtEnd(first);
    print(first);
    insertAtEnd(first,9);
    insertAtEnd(first,10);
    print(first);
    deleteBegin(first);
    print(first);
    deleteList(first);
    print(first);
}