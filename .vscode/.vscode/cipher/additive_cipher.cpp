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
}

int getValueCiphertext(char c){
    for(int i = 0; i < 26;i++) {
        if(ciphertext_table[i] == c) {
            return i;
        }
    }
}

string encryption(string plaintext, int key){
    string ciphertext;
    for(int i=0; i< plaintext.length(); i++) {
        int value = getValuePlaintext(plaintext[i]);
        int id = (value + key) % 26;
        ciphertext += ciphertext_table[id];
    }
    ciphertext += '\0';
    return ciphertext;
}

string decryption(string ciphertext, int key){
    string plaintext;
    for(int i=0; ciphertext[i] != '\0'; i++) {
        int value = getValueCiphertext(ciphertext[i]);
        int id = ((value - key) % 26 + 26)%26;
        plaintext += plaintext_table[id];
    }
    plaintext += '\0';
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