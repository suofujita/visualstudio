/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

struct Node {
    Node *prev;
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};


void Init(Node* &first) {
    first = nullptr;
}

void printList(Node *&first) {
    if(first == nullptr) {
        cout << "empty" << endl;
        return ;
    }
    Node *curr = first;
    while(curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

void insertBegin(Node *&first, int data) {
    Node *curr = new Node(data);
    if(first==nullptr) {
        first = curr;
        return;
    }
    curr->next = first;
    first->prev = curr;
    first = curr;
}

void insertAtEnd(Node *&first, int data) {
    Node *curr = new Node(data);
    if(first==nullptr) {
        first = curr;
        return;
    }
    Node *tmp = first;
    while(tmp->next != nullptr) {
        tmp = tmp->next;
    }
    tmp->next = curr;
    curr->prev = tmp;
}
int getSize(Node *&first) {
    int n = 0;
    if(first == nullptr) return n;
    Node *tmp = first;
    while(tmp != nullptr) {
        n++;
        tmp = tmp->next;
    }
    return n;
}
void insertAfter(Node *&first, int key, int data) {
   Node *tmp = first;
   while(tmp != nullptr && tmp->data != key) {
       tmp = tmp->next; 
   }
   
   if(tmp == nullptr) {
       cout << "Vi tri khong hop le" << endl;
       return;
   }
 
   Node *curr = new Node(data);
   // tmp->next = nullptr khi la phan tu cuoi cung nen tmp->next->prev co the gay loi
   curr->prev = tmp;
   curr->next = tmp->next;  
   tmp->next = curr;
    if(curr->next != nullptr)
        curr->next->prev = curr;
   cout << "Day sau khi chen sau " << endl;
            printList(first);
}

void insertBefore(Node *&first, int key, int data) {
    Node *tmp = first;
    while(tmp != nullptr && tmp->data != key) {
        tmp = tmp->next;
    }
    
    if(tmp==nullptr) {
        cout << "Vi tri khong hop le" << endl;
        return;
    }
    Node *curr = new Node(data); 
    curr->prev = tmp->prev;
    curr->next = tmp;
    tmp->prev = curr;
    
    if(curr->prev != nullptr) {
        curr->prev->next = curr;
    } 
    else {
        first = curr;
    }
    cout << "Day sau khi chen truoc " <<  endl;
            printList(first);
}



void printInverse(Node *&first){
    if(first == nullptr) {
        cout << "empty" << endl;
        return ;
    }
    Node *tmp = first;
    while (tmp->next != nullptr) {
       tmp = tmp->next;
    }
    while(tmp != nullptr) {
        cout << tmp->data << " ";
        tmp = tmp->prev;
    }
    cout << endl;
}

void deleteBegin(Node *&first) {
    // danh sach rong
    if(first==nullptr) {
        return;
    }
    // danh sach co 1 phan tro len 
    if(first->next == nullptr) {
        delete first;
        first = nullptr;
        return;
    }
    // danh sach co hai phan tu tro len
    Node *tmp = first;
    first = first->next;
    first->prev = nullptr;
    delete tmp;
}

void deleteAtEnd(Node* &first) {
    // danh sach rong
    if(first==nullptr) {
        return;
    }
    // danh sach co 1 phan tro len 
    if(first->next == nullptr) {
        delete first;
        first = nullptr;
        return;
    }
    // danh sach co hai phan tu tro len
    Node *tmp = first;
    while(tmp->next != nullptr) {
        tmp = tmp->next;
    }
    tmp->prev->next = nullptr;
    delete tmp;
}

void deleteNode(Node* &first, int key){
    Node *tmp = first;
    while(tmp != nullptr && tmp->data != key) {
        tmp = tmp->next;
    }
    if(tmp == nullptr) {
        cout << "Khong ton tai nut" << endl;
        return;
    }
    if (tmp->prev != nullptr)
        tmp->prev->next = tmp->next;
    else {
        first = tmp->next;
    }
    if (tmp->next != nullptr)
        tmp->next->prev = tmp->prev;
    delete tmp;
}




void deleteAfter(Node* &first, int key) {
    Node *curr = first;
    while(curr != nullptr && curr->data != key) {
        curr = curr->next;
    }
    // neu khong co nut can tim hoac la nut cuoi cung trong danh sach
    if(curr == nullptr || curr->next == nullptr ) {
        cout << "Khong ton tai nut" << endl;
        return;
    }
    Node *tmp = curr->next;
    curr->next = tmp->next;
    if(curr->next != nullptr) {
        curr->next->prev = curr;
    }
    delete tmp;
}

void deleteBefore(Node* &first, int key) {
    // xac dinh vi tri nut cho truoc
    Node *curr = first;
    while(curr != nullptr && curr->data != key) {
        curr = curr->next;
    }
    // neu nut khong ton tai hoac do la nut dau tien
    if(curr==nullptr || curr->prev == nullptr) {
        cout << "Khong ton tai nut" << endl;
        return;
    }
    Node *tmp = curr->prev;
    curr->prev = tmp->prev;
    if(curr->prev != nullptr) {
        curr->prev->next = curr;
    }
    else {
        first = curr;
    }
    delete tmp;
}
void deleteList(Node *&first) {
    while(first != nullptr)
        deleteBegin(first);
}

int main()
{
    Node *doublyList;
    Init(doublyList);
    insertBegin(doublyList, 5);
    insertBegin(doublyList, 6);
   // insertBegin(doublyList, 7);
    //insertBegin(doublyList, 8);
    //insertBegin(doublyList, 9);
   // insertBegin(doublyList, 10);
    //cout << getSize(doublyList)<<endl;
    //printList(doublyList);
    
    //insertAtEnd(doublyList, 10);
   // cout << getSize(doublyList)<<endl;
   // printInverse(doublyList);
   
    insertAfter(doublyList, 20, 11);
     insertAfter(doublyList, 11, 8);
      insertAfter(doublyList, 5, 20);
      insertAfter(doublyList, 20, 11);
   insertBefore(doublyList,6,21);
//   deleteAtEnd(doublyList);
  // printList(doublyList);
   //deleteNode(doublyList, 5);
   printList(doublyList);
   deleteAfter(doublyList, 21);
  deleteBefore(doublyList,5);
    printList(doublyList);
    
  deleteList(doublyList);
  printList(doublyList);
    return 0;
}