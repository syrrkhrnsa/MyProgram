#include <stdio.h>
#define MAX 5 //ukuran maksimum stack

int top = -1; //inisialisasi nilai top dengan -1
int stack[MAX];

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack overflow!\n");
    } else {
        top++;
        stack[top] = value;
    }
}

int pop() {
    int value;
    if (top == -1) {
        printf("Stack underflow!\n");
        return -1;
    } else {
        value = stack[top];
        top--;
        return value;
    }
}

int peek() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return -1;
    } else {
        return stack[top];
    }
}

void display() {
    int i;
    if (top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements are:\n");
        for (i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    push(1);
    push(2);
    push(3);
    display(); //menampilkan isi stack
//    printf("Top element is %d\n", peek());
//    printf("Popped element is %d\n", pop());
//   display(); //menampilkan isi stack setelah melakukan pop
    return 0;
}

