#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class linkedList {
    Node *first;
  
public:
    linkedList(){
        first = nullptr;
    }
    
    bool isEmpty(){
        return first==nullptr;
    }
    // chèn vào đầu danh sách
    void newNode(int val) {
        Node *tmp = new Node;
        tmp->data = val;
        tmp->next = first;
        first = tmp;
        return;
    }
    // chèn vào cuối danh sách
    void insertElementAtEnd(int val) {
        Node *tmp = new Node;
        if(first==nullptr) {
            cout << "Insert in first pos" << endl;
            tmp->data = val;
            tmp->next = nullptr;
            first = tmp;
            return;
        }
        tmp = first;
        // xác định tail đang ở đâu?
        while(tmp->next != nullptr) {
                tmp = tmp->next;
            }
        // chèn vào sau tail
        Node *current = new Node;
        current->data = val;
        current->next = nullptr;
        tmp->next = current;
    }
    // chèn vào vị trí giữa danh sách 
    void insertElementAtMid(int val){
        Node *tmp = new Node;
        if(first==nullptr) {
            cout << "Insert in first pos" << endl;
            tmp->data = val;
            tmp->next = nullptr;
            first = tmp;
            return;
        }
        tmp = first;
        int mid = getLength()/2;
    }
    // chèn vào vị trí xác định cho trước
    // pos nhận các giá trị {1,2,3,....}
    void insertElement(int val, int pos) {
        if(pos<=0) {
            cout << "Error pos" << endl;
            return;
        }
        Node *tmp = new Node;
        if(first==nullptr) {
            cout << "Insert in first pos" << endl;
            tmp->data = val;
            tmp->next = nullptr;
            first = tmp;
            return;
        }
        tmp = first;
        if (pos==1) {
            newNode(val);
            return;
        }
        else if(pos>getLength()) {
            cout << "Insert in tail pos" << endl;
            while(tmp->next != nullptr) {
                tmp = tmp->next;
            }
            // chen ve phia sau tail
            Node *current = new Node;
            current->data = val;
            current->next = nullptr;
            tmp->next = current;
            return;
        } 
        else  {
            cout << "Insert Element in pos " << pos << endl;
            int res = 1;
            pos = pos-1;
            while(res != pos) {
                tmp = tmp->next;
                res++;
            }
            //  chen ve phia sau mot phan tu khac tail
            Node *current = new Node;
            current->data = val;
            current->next = tmp->next;
            tmp->next = current;
        }
    }
    
    // xóa phần tử ở đầu danh sách
    // xóa phần tử ở cuối danh sách
    // xóa phần tử nằm ở vị trí bất kì



    // display list
    void traservalList(){
        if(first == nullptr) {
            cout << "List Empty" << endl;
            return;
        }
        Node *tmp = first;
        while(tmp != nullptr){
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }
    
    // length of list
    int getLength() {
        int len = 0;
        Node *tmp=first;
        while(tmp != nullptr) {
            tmp = tmp->next;
            len++;
        }
        return len;
    }
};

int main()
{
    linkedList newlist;
    newlist.newNode(70);
    newlist.insertElement(78,1);
    newlist.insertElement(50,1);
    newlist.insertElement(100,2);
    newlist.traservalList();
    cout << newlist.getLength() << endl;

    return 0;
}