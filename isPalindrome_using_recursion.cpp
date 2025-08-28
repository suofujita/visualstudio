#include <iostream>
#include <math.h>
using namespace std;

void isPalindrome(unsigned number, unsigned numDigits, bool& ispalindrome ) {
    if(numDigits<=1) {
        ispalindrome = true;
    }
    int first = number/(pow(10,numDigits - 1));
    int last = number%10;
    if(first!=last) {
        ispalindrome = false;
        return;
    } 
    else {
        number = (number - first*pow(10, numDigits))/10;
        numDigits = numDigits - 2;
        isPalindrome(number,numDigits,ispalindrome);
    }
}

int main() {
    unsigned a=123, b=1221, c=1, d=22, e = 12;
    bool ispalindrome;
    isPalindrome(c,1,ispalindrome);
    if(ispalindrome == true) {
        cout << "true";
    }
    else cout << "false";
}