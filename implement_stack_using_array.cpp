#include <iostream>
#define CAP 10
using namespace std;

typedef struct {
    int *arr = new int[10];
    int top;
} STACK;

void Initial(STACK* stack) {
    stack->top = -1;
}
bool isFull(STACK* stack) {
    if (stack->top == CAP - 1) return true;
    else return false;
}
bool isEmpty(STACK* stack) {
    if (stack->top == -1) return true;
    else return false;
}
void pop(STACK* stack) {
    if (!isEmpty(stack)) {
        stack->top--;
    }
    else cout << "Stack empty";
}
void push(STACK* stack, int value) {
    if (!isFull(stack)) {
        stack->arr[++stack->top] = value;
    }
    else cout << "Stack Full" << endl;
}

int top(STACK* stack) {
    if (isEmpty(stack)) return -1;
    else return stack->top;
}

int main() {
    STACK *s = new STACK;
    Initial(s);
    push(s, 10); 
    push(s, 20);
    push(s, 30);
    push(s, 40);
    pop(s);
    cout << s->arr[top(s)];
    delete s;
    return 0;
}