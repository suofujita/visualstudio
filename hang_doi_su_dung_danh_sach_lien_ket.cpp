#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

struct queue {
    Node *front, *rear;
};

void Init(queue& q) {
    q.front = q.rear = nullptr;
}

// kiem tra rong 
bool isEmpty(queue& q) {
    return q.front==nullptr;
}
void enqueue(queue& q, int val) {
    Node *tmp = new Node;
    tmp->data = val;
    tmp->next = nullptr;
    if(q.front==nullptr) {
        q.front = q.rear = tmp;
    }
    else {
        q.rear->next = tmp;
        q.rear = tmp;
    }
}
void dequeue(queue& q) {
    if(isEmpty(q)) {
        cout << "Empty" << endl;
        return;
    }
    Node *tmp = q.front;
    q.front = q.front->next;
    delete tmp;
    
    if(q.front == nullptr) {
        q.rear = nullptr;
    }
}

void deleteQueue(queue& q) {
    while(q.front != nullptr) {
        dequeue(q);
    }
}
void printQueue(queue& q) {
    if(q.front == nullptr) {
        cout << "Empty" << endl;
        return;
    }
    Node *curr = q.front;
    while(curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {

    queue q;
    Init(q);
    
    enqueue(q,5);
   enqueue(q,4);
   enqueue(q,6);
   enqueue(q,8);
   enqueue(q,9);
   printQueue(q);

   dequeue(q);
   dequeue(q);
   dequeue(q);

   enqueue(q,2);
   enqueue(q,3);
   enqueue(q,1);

   printQueue(q);


    return 0;
    
}
