#include<iostream>
#include<vector>
using namespace std;

vector<char> plaintext_table;
vector<char> ciphertext_table;

int getValuePlaintext(char p) {
    for(int i = 0; i<26;i++) {
        if(plaintext_table[i] == p) {
            return i;
        }
    }
    return -1;
}

int getValueCiphertext(char c){
    for(int i = 0; i < 26;i++) {
        if(ciphertext_table[i] == c) {
            return i;
        }
    }
    return -1;
}

string encryption(string plaintext, int key){
    string ciphertext;
    for(int i=0; i< plaintext.length(); i++) {
        int value = getValuePlaintext(plaintext[i]);
        if(value == -1) continue; // skip invalid char
        int id = (value + key) % 26;
        ciphertext += ciphertext_table[id];
    }
    return ciphertext;
}

string decryption(string ciphertext, int key){
    string plaintext;
    for(int i=0; i < ciphertext.length(); i++) {
        int value = getValueCiphertext(ciphertext[i]);
        if(value == -1) continue; // skip invalid char
        int id = ((value - key) % 26 + 26)%26;
        plaintext += plaintext_table[id];
    }
    return plaintext;
}
int main(){
    // plaintext table
    for(char c = 'a'; c <='z'; c++) {
     plaintext_table.push_back(c);
    }
    // ciphertext table
    for(char c = 'A'; c<='Z';c++){
        ciphertext_table.push_back(c);
    }
    
    string plaintext = "hello";
    int key = 15;
    string ciphertext = encryption("hello", 15);
    string plaintext_decrypt = decryption(ciphertext, key);
    cout << "Encryption string '" << plaintext << "' with key = " << key << ": " << ciphertext << endl;
    cout << "Decryption string '" << ciphertext << "' with key = " << key << ": " << plaintext_decrypt;
    return 0;
}