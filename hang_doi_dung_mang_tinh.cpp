#include <iostream>
using namespace std;
#define max 10

// kiểm tra rỗng
bool isEmpty(int front,int rear) {
    return (front<0 || front > rear);  
}
// chốt code này
void enqueue (int queue[], int& front, int& rear, int data) {
    if(rear==max-1) {
        cout << "Full" << endl;
        return;
    } 
    if(front==-1 && rear==-1) 
        front = rear = 0; 
    else 
        rear += 1;
    queue[rear] = data;
}
// chốt code này
void dequeue(int queue[], int& front, int& rear) {
    if(isEmpty(front,rear)) {
        cout << "Empty" << endl;
    }

   /*   cách 1: dịch chuyển các phần tử về đầu
    else {
        for(int i=front;i<rear;i++)
            queue[i] = queue[i+1];
        rear--;
    } 
    */
   // cách 2: dịch chuyển front
   front++;
   if(front > rear) {
        front = rear = -1;
   }
}
// chốt code này
void printQueue(int queue[], int front, int rear) {
    if(isEmpty(front,rear)) {
        cout << "Empty" << endl;
        return;
    }
// cho chạy từ front vì front có thể khác 0
    for(int i=front;i<=rear;i++) 
        cout << queue[i] << " ";
    cout << endl;
}

int main() {
    int queue[max];
    int front = -1, rear = -1;
    enqueue(queue,front,rear,5);
    enqueue(queue,front,rear,6);
    enqueue(queue,front,rear,7);
    enqueue(queue,front,rear,8);
    enqueue(queue,front,rear,9);
    cout << rear << endl; printQueue(queue,front,rear);
    dequeue(queue,front,rear);
    cout << endl; printQueue(queue,front,rear);
    dequeue(queue,front,rear);
    cout << endl; printQueue(queue,front,rear);
    dequeue(queue,front,rear);
    cout << endl; printQueue(queue,front,rear);
    dequeue(queue,front,rear);
    cout << endl; printQueue(queue,front,rear);
    dequeue(queue,front,rear);
    cout << endl; printQueue(queue,front,rear);
    
    
}