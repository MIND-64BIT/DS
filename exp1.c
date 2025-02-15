#include <stdio.h>
#define SIZE 10

int array[SIZE];
int last = -1;

void insert(int index, int element) {
    if (index < 0 || index > last + 1 || index >= SIZE) {
        printf("IndexError: Invalid index.\n");
        return;
    }

    if (index == last + 1) {
        last++;
    }

    array[index] = element;
    printf("Element inserted at index %d.\n", index);
}

void delete(int index) {
    if (index < 0 || index > last || index >= SIZE) {
        printf("IndexError: Invalid index.\n");
        return;
    }

    array[index] = 0;

    if (index == last) {
        while (last >= 0 && array[last] == 0) {
            last--;
        }
    }

    printf("Element at index %d deleted.\n", index);
}

void display() {
    if (last == -1) {
        printf("ArrayError: The array is empty.\n");
        return;
    }

    for (int i = 0; i <= last; i++) {
        printf("%d\t", array[i]);
    }
    printf("\n");
}

int main() {
    int choice, index, element;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter index to insert at: ");
                scanf("%d", &index);
                printf("Enter element to insert: ");
                scanf("%d", &element);
                insert(index, element);
                break;
            case 2:
                printf("Enter index to delete from: ");
                scanf("%d", &index);
                delete(index);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("ChoiceError: Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}
