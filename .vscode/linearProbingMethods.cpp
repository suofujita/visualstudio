#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

int modPrime(int key) {
    return key % 97;  // sẽ có 97 ô nhớ không bị đụng độ
}
int midSquareHash(int key, int tableSize) {
    long long square = (long long)key * key; // Tính bình phương khóa
    string squareString = to_string(square);    // Chuyển thành chuỗi
    int len = squareString.length();

    // Lấy 2 chữ số giữa
    int midDigits = stoi(squareString.substr(len / 2, 2));

    // Tính chỉ số băm
    return midDigits % tableSize;
}
int foldingHash(int key, int tableSize) {
    string keyString = to_string(key);
    vector<int> parts;
    int partSize = 2;
    int keySize = keyString.length();
    for (size_t i = 0;i < keySize;i += partSize) {
        parts.push_back(stoi(keyString.substr(i,partSize)));
    }
    int sum = 0;
    for (int i : parts) {
        sum += i;
    }
    return sum % tableSize;
}
/* chia số bắt đầu từ chữ số cuối cùng */
int foldingHashReverse(int key, int tableSize) {
    vector<int> parts;
    int partSize = 2;
    int divisor = 1;
    /* Tìm hệ số cần chia */
    for (int i = 0;i < partSize;i++) {
        divisor *= 10;
    }
    while (key > 0) {
        parts.push_back(key % divisor);
        key /= divisor;
    }
    int sum = 0;
    for (int i : parts) {
        sum += i;
    }
    return sum % tableSize;
}
/* Định nghĩa một bảng băm */
struct hashNode {
    int key;
    int marked = -1;
};

class hashTable {
    int tableSize;
    int numElements;
    vector<hashNode> ptrHashTable;
public:
    hashTable(int n) {
        numElements = 0;
        tableSize = n;
        ptrHashTable = vector<hashNode>(n);
    }
    void linearProbing(int key) {
        if (numElements == tableSize) {
            cout << "Bang bam day" << endl;
            return;
        }
        int index = (key % tableSize);
        int i = 1;
        while (ptrHashTable[index].marked==1) {
            index = (key % tableSize + i) % tableSize;
            i++;
        }
        ptrHashTable[index].key = key;
        ptrHashTable[index].marked = 1;
        numElements++;
    }

    void quadraticProbing(int key) {
        if (numElements == tableSize) {
            cout << "Bang bam day" << endl;
            return;
        }
        int index = key % tableSize;
        int i = 0;
        while(ptrHashTable[index].marked==1 && i < tableSize){
            ++i;
            index = (key%tableSize + i*i)%tableSize;
        }
        if(i==tableSize) {
            cout << "Khong tim thay vi tri cho " << key << endl;
            return;
        }
        ptrHashTable[index].key = key;
        ptrHashTable[index].marked = 1;
        numElements++;
    }

    void doubleHashing(int key){
        if (numElements == tableSize) {
            cout << "Bang bam day" << endl;
            return;
        }
        int index = key % tableSize;
        int i=0;
        while(ptrHashTable[index].marked == 1 && i < tableSize) {
            ++i;
            index = (key % tableSize + i*(key % (tableSize - 2))) % tableSize;
        }
        if(i==tableSize) {
            cout << "Khong tim thay vi tri cho " << key << endl;
            return;
        }
        ptrHashTable[index].key = key;
        ptrHashTable[index].marked = 1;
        numElements++;
    }

    void printHashTable(){
        for(hashNode i: ptrHashTable){
            if(i.marked==1)
                cout << i.key << " ";
        }
        cout << endl;
    }
};
int main() {
    for (int i = 0;i < 97;i++) {
        cout << modPrime(i) << " ";
    }
    cout << endl;
    cout << midSquareHash(5642, 100); cout << endl;
    cout << foldingHash(34567, 100); cout << endl;
    cout << foldingHashReverse(34567, 100); cout << endl;
    hashTable newTable(10);

    /* newTable.quadraticProbing(72);
    newTable.quadraticProbing(27);
    newTable.quadraticProbing(36);
    newTable.quadraticProbing(24);
    newTable.quadraticProbing(63);
    newTable.quadraticProbing(81);
    newTable.quadraticProbing(101);
    newTable.printHashTable();*/

    newTable.doubleHashing(72);
    newTable.doubleHashing(27);
    newTable.doubleHashing(36);
    newTable.doubleHashing(24);
    newTable.doubleHashing(63);
    newTable.doubleHashing(81);
    newTable.doubleHashing(101);

    newTable.printHashTable();
}
