#include <iostream>
using namespace std;

// cấu trúc một model điện thoại
struct info {
    int mMobile, bQuantity, sQuantity;
    double bPrice, sPrice, profit;
};

struct Model {
    info* data;
    Model* next;
    // hàm tạo 
    Model(info *data) {
        this->data = data;
        this->next = nullptr;
    }
};
typedef Model pModel;
typedef Model plistModel;

// khởi tạo danh sách rỗng
void Init(plistModel *first) {
    // tạo vùng nhớ mới con trỏ first trỏ đến
     first = nullptr;
}

/*Bổ sung một model vào cuối danh sách*/
// ý tưởng
// 1. Duyệt lần lượt danh sách đến phần tử cuối cùng
// 2. Sau đó chèn phần tử mới vào vị trí sau phần tử này
// 3. Trả về con trỏ first
plistModel* InsertLastList (plistModel* first, info *data ) {
    if(first==nullptr) {
        first = new Model(data);
        return first;
    }
    pModel *curr = first;
    while(curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = new Model(data);
    return first;
}

// in danh sách 
void printList(plistModel *first) {
    if(first==nullptr) {
        cout << "Danh sach rong" << endl;
        return;
    }
    pModel *curr = first;
    while(curr != nullptr) {
        cout << curr->data->mMobile << endl;
        curr = curr->next;
    }
}

 int main() {
    info data[]= {{1,2,1,10000,20000,-1}, 
                    {2,3,2,15000,25000,-1}};
    plistModel *list;
    Init(list);
    list = new Model(&data[0]);
    pModel *model1 = new Model(&data[0]);
    pModel *model2 = new Model(&data[1]);
    list->next = model1;
    model1->next = model2;
    
    
    printList(list);

    InsertLastList(list,&data[1]);
    
    printList(list);
    delete model1;
    delete model2;
    delete list;
    return 0;
 }