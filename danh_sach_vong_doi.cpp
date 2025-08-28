#include <iostream>
using namespace std;

// cau truc 1 nut 
struct Node {
    int data;
    Node* prev, *next;
    Node(int data) {
        this->data = data;
        this->prev = this->next = nullptr;
    }
};
struct circularDoubly {
    Node *first;
    int size;
    circularDoubly() {
        first = nullptr;
        size = 0;
    }
};

bool isEmpty(circularDoubly &cDoubly) {
    return (cDoubly.first==nullptr);
}
void insertBegin (circularDoubly &cDoubly, int data) {
    Node *curr = new Node(data);
    // danh sach rong
    if(isEmpty(cDoubly)) {
        cDoubly.first = curr;
        cDoubly.first->next = cDoubly.first->prev = cDoubly.first;
    }
    // danh sach co phan tu
    else {
        Node *tmp = cDoubly.first;
        while(tmp->next != cDoubly.first) {
            tmp = tmp->next;
        }
        tmp->next = curr;
        curr->prev = tmp;
        curr->next = cDoubly.first;
        cDoubly.first->prev = curr;
        cDoubly.first = curr;
    }
    cDoubly.size++;
}
void insertAtEnd(circularDoubly &cDoubly, int data) {
    Node *curr = new Node(data);
    // danh sach rong
    if(isEmpty(cDoubly)) {
        cDoubly.first = curr;
        cDoubly.first->next = cDoubly.first->prev = cDoubly.first;
    }
    // danh sach co phan tu
    else {
       Node *tmp = cDoubly.first;
       while(tmp->next != cDoubly.first) {
           tmp = tmp->next;
       }
       curr->next = cDoubly.first;
       curr->prev = tmp;
       tmp->next = curr;
       cDoubly.first->prev = curr;
    }
    cDoubly.size++;
}
int getSize(circularDoubly &cDoubly) {
    return cDoubly.size;
}
void printList(circularDoubly &cDoubly) {
    if(isEmpty(cDoubly)) {
        cout << "empty" << endl;
        return;
    }
    Node *tmp = cDoubly.first;
    do {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    while(tmp != cDoubly.first);
    cout << endl;
}

void deleteBegin(circularDoubly &cDoubly) {
    if(isEmpty(cDoubly)) {
        return;
    }
    if(cDoubly.first->next == cDoubly.first) {
        delete cDoubly.first;
        cDoubly.first = nullptr;
    }
    else {
        Node *tmp = cDoubly.first;
        cDoubly.first = cDoubly.first->next;
        cDoubly.first->prev = tmp->prev;
        cDoubly.first->prev->next = cDoubly.first;
        delete tmp;
    }
    cDoubly.size--;
}

void deleteAtEnd(circularDoubly &cDoubly) {
    if(isEmpty(cDoubly)) {
        return;
    }
    if(cDoubly.first->next == cDoubly.first) {
        delete cDoubly.first;
        cDoubly.first = nullptr;
    }
    else {
        Node *tmp = cDoubly.first;
        while(tmp->next != cDoubly.first) {
            tmp = tmp->next;
        }
        tmp->prev->next = cDoubly.first;
        cDoubly.first->prev = tmp->prev;
        delete tmp;
    }
    cDoubly.size--;
}
void deleteList(circularDoubly &cDoubly) {
    while(cDoubly.first != nullptr) {
        deleteAtEnd(cDoubly);
    }
}

int main()
{
    circularDoubly ptr;
    insertBegin(ptr, 10);
    insertBegin(ptr, 20);
    insertBegin(ptr, 50);
    insertBegin(ptr, 100);
    insertBegin(ptr, 200);
    insertBegin(ptr, 5000);
    printList(ptr); 
    cout << "Size of List: " << getSize(ptr) << endl;
    
    insertAtEnd(ptr, 105);
    insertAtEnd(ptr, 2045);
    insertAtEnd(ptr, 5074);
    insertAtEnd(ptr, 1010);
    insertAtEnd(ptr, 2010);
    insertAtEnd(ptr, 500);
    printList(ptr);
    cout << "Size of List: " << getSize(ptr) << endl;
    
    deleteAtEnd(ptr);
    deleteAtEnd(ptr);
    printList(ptr);
    cout << "Size of List: " << getSize(ptr) << endl;
    
    deleteBegin(ptr);
    printList(ptr);
    cout << "Size of List: " << getSize(ptr) << endl;
    
    deleteList(ptr);
    printList(ptr);
    cout << "Size of List: " << getSize(ptr) << endl;
    return 0;
}