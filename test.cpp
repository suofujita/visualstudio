/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

void Init(Node* &head, int val) {
    head = new Node;
    head->data = val;
    head->next = nullptr;
}
bool isEmpty(Node* head) {
	return head==nullptr;
}

Node* InsertAfter(Node* head,Node* p, int val) {
	if(head==nullptr) {
		return nullptr;
	}
	Node* tmp = new Node;
	tmp->data = val;
	tmp->next = p->next;
	p->next = tmp;
	return head;
}

Node* Remove(Node* head,int pos) {
	if(head==nullptr) {
		return nullptr;
	}
	Node* tmp = head;
	if(pos==1) {
		if(head->next==nullptr) {
			delete head;
			return nullptr;
		}
		head = head->next;
		delete tmp;
		return head;
	}
	int res=1;
	while(res!=pos-1) {
	    tmp = tmp->next;
	    res++;
	}
	Node* current = tmp->next;
	tmp->next = tmp->next->next;
	delete current;
	return head;
}

void display(Node* head) {
    if(head==nullptr) {
        cout << "Empty";
    }
    Node* tmp = head;
    while(tmp != nullptr) {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main()
{
    Node* head, *node1, *node2, *node3;
    Init(head,10); Init(node1,20); Init(node2,30); Init(node3,40);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    display(head);
    InsertAfter(head,node2,50);
    display(head);
    head = Remove(head,2);
    display(head);
    
	return 0;
}