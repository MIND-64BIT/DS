#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node* head = NULL;

void InsertInBeginning(int val){
    struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
    if (NewNode == NULL){
        printf("Error\n");
        return;
    }
    NewNode->data = val;
    NewNode->next = head;
    head = NewNode;
}

void InsertInLast(int val){
    struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
    NewNode->data = val;
    NewNode->next = NULL;

    struct Node* curr = head;
    if(curr == NULL){
        InsertInBeginning(val);
        return;
    }
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = NewNode;
}

void InsertAt(int idx, int val){
    int counter = 0;
    struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
    NewNode->data = val;

    struct Node* curr = head;
    struct Node* prev = NULL;

    if(curr == NULL || idx == 0){
        InsertInBeginning(val);
        return;
    }

    while(counter != idx){
        prev = curr;
        curr = curr->next;
        counter++;

        if(curr == NULL){
            // Insert at the end if index is out of range
            prev->next = NewNode;
            NewNode->next = NULL;
            return;
        }
    }

    NewNode->next = curr;
    prev->next = NewNode;
}

int RemoveFromBeginning(){
    if(head == NULL){
        printf("IndexError: can't remove from empty linked list\n");
        return -1;
    }
    struct Node* first = head;
    head = first->next;
    return first->data;
}

int RemoveFromLast(){
    struct Node* curr = head;
    struct Node* prev = NULL;

    if(head == NULL){
        printf("IndexError: can't remove from empty linked list\n");
        return -1;
    }

    if(curr->next == NULL){
        int val = curr->data;
        head = NULL;
        return val;
    }

    while(curr->next != NULL){
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    return curr->data;
}

int RemoveAt(int idx){
    int counter = 0;

    if(head == NULL){
        printf("IndexError: can't remove from empty linked list\n");
        return -1;
    }

    if(idx == 0){
        return RemoveFromBeginning();
    }

    struct Node* curr = head;
    struct Node* prev = NULL;

    while(counter != idx){
        prev = curr;
        curr = curr->next;
        counter++;

        if(curr == NULL){
            printf("IndexError: index out of range\n");
            return -1;
        }
    }
    prev->next = curr->next;
    return curr->data;
}

void display(){
    struct Node* curr = head;

    if(curr == NULL){
        printf("Empty Linked List\n");
        return;
    }

    while(curr != NULL){
