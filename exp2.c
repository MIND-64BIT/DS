#include <stdio.h>
#define size 10

int arr[size], top = -1;

void push(int val) {
    if (isFull()) {
        printf("\nIndexError: inserting in full stack");
        return;
    }
    arr[++top] = val;
}

int pop() {
    if (isEmpty()) {
        printf("\nIndexError: popping from empty stack");
        return -1;
    }
    int lastEle = arr[top--];
    return lastEle;
}

int isEmpty() {
    return (top == -1);
}

int isFull() {
    return (top == size - 1);
}

void display() {
    if (isEmpty()) {
        printf("Stack is EMPTY.\n");
        return;
    }
    for (int i = top; i >= 0; i--) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void ptop() {
    if (isEmpty()) {
        printf("\nEmptyError: stack is empty");
    } else {
        printf("TOP: %d", arr[top]);
    }
}

int main() {
    int choice;
    while (1) {
        int value;
        int poppedEle;

        printf("\n\n1-> Push\n2-> Pop\n3-> IsEmpty\n4-> IsFull\n5-> Display\n6-> TOP\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter value to push: ");
                scanf("%d", &value);
                push(value);
                printf("\n%d is pushed in the stack", value);
                break;

            case 2:
                poppedEle = pop();
                if (poppedEle != -1) {
                    printf("\n%d is popped from the stack", poppedEle);
                }
                break;

            case 3:
                if (isEmpty()) {
                    printf("\nTrue");
                } else {
                    printf("\nFalse");
                }
                break;

            case 4:
                if (isFull()) {
                    printf("\nTrue");
                } else {
                    printf("\nFalse");
                }
                break;

            case 5:
                display();
                break;

            case 6:
                ptop();
                break;

            default:
                printf("\nEnter a valid choice");
        }
    }
    return 0;
}
