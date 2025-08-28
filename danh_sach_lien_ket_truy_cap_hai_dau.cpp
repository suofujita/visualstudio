#include <iostream>
using namespace std;
// cau truc 1 nut
struct Node {
	int data;
	Node *next;
	Node(int data) {
		this->data = data;
		this->next = nullptr;
	}
};
// cau truc danh sach don
struct singleList {
	Node *head, *tail;
	int size;
	singleList() {
		head = tail = nullptr;
		size = 0;
	}
};
// kiem tra rong
bool isEmpty(singleList & sList) {
	return (sList.head == nullptr);
}
// kich thuoc danh sach
int getSize(singleList &sList) {
	return sList.size;
}
// chen vao dau danh sach
void insertBegin(singleList &sList, int data) {
	Node *curr = new Node(data);
	if(isEmpty(sList)) {
		sList.head = sList.tail = curr;
	}
	else {
		curr->next = sList.head;
		sList.head = curr;
	}
	sList.size++;
}
// chen vao sau danh sach
void insertTail(singleList &sList, int data) {
	Node *curr = new Node(data);
	if(isEmpty(sList)) {
		sList.head = sList.tail = curr;
	}
	else {
		sList.tail->next = curr;
		sList.tail = curr;
	}
	sList.size++;
}
// chen vao sau 1 nut cho truoc
void insertAfter(singleList &sList, int key, int data) {
    // tim vi tri nut cho truoc
    Node *tmp = sList.head;
    while(tmp != nullptr && tmp->data != key) {
        tmp = tmp->next;
    }
    if (tmp == nullptr) {
        cout << "Vi tri khong hop le" << endl;
        return;
    }
    Node *curr = new Node(data);
    curr->next = tmp->next;
    tmp->next = curr;
    if(curr->next == nullptr) {
        sList.tail = curr;
    }
    sList.size++;
}

// chen vao truoc 1 nut cho truoc
void insertBefore(singleList &sList, int key,int data) {
    // tim vi tri nut cho truoc
    Node *tmp = sList.head;
    Node *preCurr = nullptr;
    while(tmp != nullptr && tmp->data != key) {
        preCurr = tmp;
        tmp = tmp->next;
    }
    if (tmp == nullptr) {
        cout << "Vi tri khong hop le" << endl;
        return;
    }
   
    if(preCurr == nullptr) {
        insertBegin(sList, data);
    }
    else {
        int key_ = preCurr->data;
        insertAfter(sList, key_, data);
    }
}

// in danh sach
void printList(singleList &sList) {
	if(isEmpty(sList)) {
		cout << "empty" << endl;
		return;
	}
	Node *tmp = sList.head;
	while(tmp != nullptr) {
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << endl;
}
// xoa nut dau
void deleteBegin(singleList &sList) {
	// case 1: danh sach rong
	if(isEmpty(sList)) {
		return;
	}
	// case 2: 1 phan tu
	if(sList.head == sList.tail) {
		delete sList.head;
		sList.head = sList.tail = nullptr;
	}
	else {
		Node *tmp = sList.head;
		sList.head = sList.head->next;
		delete tmp;
	}
	sList.size--;
}
// xoa nut cuoi
void deleteTail(singleList &sList) {
    // case 1: danh sach rong
	if(isEmpty(sList)) {
		return;
	}
	// case 2: 1 phan tu
	if(sList.head == sList.tail) {
		delete sList.head;
		sList.head = sList.tail = nullptr;
	}
	else {
	    Node *curr = sList.head;
	    Node *preCurr = nullptr;
	    while(curr->next != nullptr) {
	        preCurr = curr;
	        curr = curr->next;
	    } 
	    preCurr->next = nullptr;
	    sList.tail = preCurr;
		delete curr;
	}
	sList.size--;
}
// xoa nut hien tai
void deleteNode(singleList &sList, int key) {
    // tim vi tri nut
    Node *curr = sList.head;
    Node *preCurr = nullptr;
    while(curr != nullptr && curr->data != key) {
        preCurr = curr;
        curr = curr->next;
    }
    if (curr == nullptr) {
        cout << "Vi tri khong hop le" << endl;
        return;
    }
    if (curr == sList.head) {
        deleteBegin(sList);
        return;
    }
    else if (curr == sList.tail) {
        deleteTail(sList);
        return;
    }
    else {
        preCurr->next = curr->next;
        delete curr;
        sList.size--;
    }
}

// xoa nut sau 1 nut
void deleteAfter(singleList &sList, int key) {
     // tim vi tri nut cho truoc
    Node *curr = sList.head;
    while(curr != nullptr && curr->data != key) {
        curr = curr->next;
    }
    // case 1: neu khong ton tai nut 
    // case 2: xoa sau nut cuoi cung
    if (curr == nullptr || curr->next == nullptr) {
        cout << "Vi tri khong hop le" << endl;
        return;
    }
     Node *tmp = curr->next;
    if(tmp == sList.tail) {
        deleteTail(sList);
        return;
    }
    
    curr->next = tmp->next;
    delete tmp;
    sList.size--;
}
// xoa nut truoc 1 nut
void deleteBefore(singleList &sList, int key) {
     // tim vi tri nut cho truoc
    Node *curr = sList.head;
    Node *preCurr = nullptr;
    while(curr != nullptr && curr->data != key) {
        preCurr = curr;
        curr = curr->next;
    }
    // case 1: neu khong ton tai nut 
    // case 2: xoa truoc nut dau
    if (curr == nullptr || curr == sList.head) {
        cout << "Vi tri khong hop le" << endl;
        return;
    }
    if(preCurr == sList.head) {
        deleteBegin(sList);
        return;
    }
    int mid;
    mid = curr->data;
    curr->data = preCurr->data;
    preCurr->data = mid;
    deleteAfter(sList, mid);
}
// xoa toan bo danh sach
void deleteList(singleList &sList) {
	while(sList.head != nullptr)
		deleteBegin(sList);
}
int main()
{
	singleList ptr;
	insertBegin(ptr, 10);
	insertBegin(ptr, 20);
	insertBegin(ptr, 50);
	insertBegin(ptr, 100);
	insertBegin(ptr, 200);
	insertBegin(ptr, 5000);
	printList(ptr);
	cout << "Size of List: " << getSize(ptr) << endl;

    insertTail(ptr, 105);
    insertTail(ptr, 2045);
    insertTail(ptr, 5074);
    insertTail(ptr, 1010);
    insertTail(ptr, 2010);
    insertTail(ptr, 500);
    printList(ptr);
    cout << "Size of List: " << getSize(ptr) << endl;
    
    // kiem tra xem co backup tail khong
    insertAfter(ptr, 500, 2);
    insertAfter(ptr, 2, 3);
    // chen vao sau nut dau
    insertAfter(ptr, 5000, 58);
    // chen vao sau nut bat ki
    insertAfter(ptr, 105, 311);
    printList(ptr);
    cout << "Size of List: " << getSize(ptr) << endl;
    
     // kiem tra xem co backup head khong
    insertBefore(ptr, 5000, 21);
    insertBefore(ptr, 21, 35);
    // chen vao truoc nut sau
    insertBefore(ptr, 3, 54);
    // chen vao sau nut bat ki
    insertBefore(ptr, 105, 311);
    printList(ptr);
    cout << "Size of List: " << getSize(ptr) << endl;
    
    // xoa nut cuoi
    deleteNode(ptr, 3);
    //xoa nut dau 
    deleteNode(ptr, 35);
    // xoa nut bat ki
    deleteNode(ptr, 105);
    printList(ptr);
    cout << "Size of List: " << getSize(ptr) << endl;
    
    
    // xoa nut cuoi
    deleteAfter(ptr, 2);
    deleteAfter(ptr,500);
    deleteAfter(ptr,20);
    printList(ptr);
    cout << "Size of List: " << getSize(ptr) << endl;
    
    // xoa nut dau
    deleteBefore(ptr, 5000);
    deleteBefore(ptr, 58);
    deleteBefore(ptr, 2045);
    printList(ptr);
    cout << "Size of List: " << getSize(ptr) << endl;
    
    deleteList(ptr);
    printList(ptr);
    cout << "Size of List: " << getSize(ptr) << endl;
	return 0;
}