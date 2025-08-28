#include <iostream>
using namespace std;
// cau truc 1 nut
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int data) {
        this->data = data;
        this->next = this->prev = nullptr;
    }
};
// cau truc 1 hang doi dau cuoi
struct deque {
    Node* front, *rear;
    int size;
    deque() {
        front = rear =nullptr;
        size = 0;
    }
   
};
// kiem tra danh sach rong khong?
bool isEmpty(deque &de) {
    return (de.front == nullptr);
}
// ham lay size cua danh sach
int getSize(deque &de) {
    return de.size;
}
// ham tra ve con tro tro den nut dau tien
Node* getFront(deque &de) {
    return de.front;
}
// ham tra ve con tro tro den nut cuoi cung
Node* getRear(deque &de) {
    return de.rear;
}
// chen vao dau danh sach
void insertFront(deque& de, int data) {
    Node *curr = new Node(data);
    // danh sach rong
    if(de.front == nullptr) {
        de.front = curr;
        de.rear = curr;
        de.size++;
        return;
    }
    // danh sach co 1 phan tu tro len
    curr->next = de.front;
    de.front->prev = curr;
    de.front = curr;
    de.size++;
}
// chen vao cuoi su dung con tro rear, khong can dung con tro tmp de duyet
// qua tung phan tu cua danh sach
void insertRear(deque &de, int data) {
    Node *curr = new Node(data);
    if(isEmpty(de)) {
        de.front = de.rear = curr;
    }
    else {  
        curr->prev = de.rear;
        de.rear->next = curr;
        de.rear = curr;
    }
    de.size++;
}
// In cac phan tu trong hang doi 
void printDeque(deque &de) {
    if(de.front == nullptr) {
        cout << "empty" << endl;
        return;
    }
    Node *tmp = de.front;
    while(tmp != nullptr) {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
// xoa phan tu dau tien
void deleteFront(deque &de){
    // danh sach rong
    if(de.front == nullptr) {
        cout << "Danh sach rong" << endl;
        return;
    }
    // danh sach co 1 phan tu
    if(de.front->next == nullptr) {
        delete de.front;
        de.front = nullptr;
        de.size--;
        return;
    }
    // danh sach co 2 phan tu
    Node *tmp = de.front;
    de.front = de.front->next;
    de.front->prev = nullptr;
    de.size--;
    delete tmp;
}
// xoa phan tu cuoi cung su dung con tro rear
void deleteRear(deque &de) {
    // danh sach rong
    if(de.front == nullptr) {
        cout << "Danh sach rong" << endl;
        return;
    }
    // danh sach co 1 phan tu
    if(de.front == de.rear) {
        delete de.front;
        de.front = de.rear = nullptr;
        de.size--;
        return;
    }
    // danh sach co hai phan tu tro len 
    Node *tmp = de.rear;
    de.rear = de.rear->prev;
    de.rear->next = nullptr;
    de.size--;
    delete tmp;
}
// xoa toan bo phan tu
void deleteDeque(deque &de) {
    while(de.front!=nullptr) 
        deleteFront(de);
}
int main()
{
    /* sample test */
    deque ptr;
    insertFront(ptr,10);
    insertFront(ptr,80);
    insertFront(ptr,90);
    insertFront(ptr,100);
    insertRear(ptr,100);
    insertFront(ptr,760);
    insertRear(ptr,800);
    insertFront(ptr,1000);
    cout << getSize(ptr) << endl;
    printDeque(ptr);
    deleteFront(ptr);
    printDeque(ptr);
    deleteRear(ptr);
    printDeque(ptr);
    cout << getSize(ptr) << endl;
    deleteDeque(ptr);
    printDeque(ptr);
}