#include <iostream>
#define max 20
using namespace std;

struct queue {
    int arr[max];
    int front;
    int rear;
    queue() {
        front = rear = -1;
    }
};

void enqueue(queue &q, int data) {
    if(q.rear == max-1) 
        return;
    if(q.front ==-1 && q.rear == -1) {
        q.front = q.rear = 0;
    }
    else {
        q.rear += 1;
    }
    q.arr[q.rear]  = data;
}

void printQueue(queue &q) {
    if(q.front<0) {
        cout << "empty" << endl;
        return;
    }
    for(int i = q.front;i<=q.rear;i++) 
        cout << q.arr[i] << " ";
    cout << endl;
}

int main() {
    int nums[] = {3, 22, 12, 6, 10, 34, 65, 29, 9, 30, 81, 4, 5, 19, 20, 57, 44, 99};
    queue less10, less20, less30, greater29; 
    for(int i=0; i<sizeof(nums)/sizeof(nums[0]);i++) {
        if(nums[i]<10) {
            enqueue(less10,nums[i]);
        }
        else if(nums[i]<20) {
            enqueue(less20,nums[i]);
        }
        else if(nums[i]<30) {
            enqueue(less30,nums[i]);
        }
        else {
            enqueue(greater29,nums[i]);
        }
    }

    cout << "So nho hon 10: "; printQueue(less10);
    cout << "So nho hon 20: "; printQueue(less20);
    cout << "So nho hon 30: "; printQueue(less30);
    cout << "So bang hoac lon hon 30: "; printQueue(greater29);
}