#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = value;
    //printf("Element inserted: %d\n", value);
}

void dequeue() {
    if (front == -1) {
        printf("Queue underflow\n");
        return;
    }
    printf("Element deleted: %d\n", queue[front]);
    front++;
    if (front > rear) {
        front = -1;
        rear = -1;
    }
}

void display() {
	int i;
    if (rear == -1) {
        printf("Queue is empty\n");
        return;
    }
    //printf("Elements in queue are:\n");
    for (i = front; i <= rear; i++) {
        printf("%d\n", queue[i]);
    }
}

int main() {
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5);
	dequeue();
	display(); 
//    int choice, value;
//    while (1) {
//        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
//        printf("Enter your choice: ");
//        scanf("%d", &choice);
//        switch (choice) {
//            case 1:
//                printf("Enter the value to be inserted: ");
//                scanf("%d", &value);
//                enqueue(value);
//                break;
//            case 2:
//                dequeue();
//                break;
//            case 3:
//                display();
//                break;
//            case 4:
//                return 0;
//            default:
//                printf("Invalid choice\n");
//        }
//    }
    return 0;
}

