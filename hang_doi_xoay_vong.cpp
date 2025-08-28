// chốt
#include <iostream>
using namespace std;
#define N 5

struct queue {
    int arr[N];
    int front;
    int rear;
};
// circular queue
void Init(queue& q) {
    q.front = q.rear = -1;
}
bool isEmpty(queue& q) {
    return ((q.front==-1) && (q.rear == -1));
}
bool isFull(queue& q) {
    return ((q.front==0 && q.rear == N-1)||(q.front == q.rear+1)) ;
}
void enqueue(queue& q, int val) {
    if(isFull(q)) {
       cout << "Full" << endl;
       return;
    }
    if (q.front==-1) q.front = 0;
    q.rear = (q.rear+1)%N;
    q.arr[q.rear] = val;
}

void dequeue(queue& q) {
    if(isEmpty(q)) {
        cout << "Empty" << endl;
        return;
    }
    if (q.front == q.rear) { 
        q.front = q.rear = -1;
    } else {
        q.front = (q.front + 1) % N;
    }
}

void printQueue(queue& q) {
      if(isEmpty(q)) {
        cout << "Empty" << endl;
        return;
      }
      for(int i=q.front;;i=(i+1)%N) {
        cout << q.arr[i] << " ";
        if(i==q.rear) break;
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


}