#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};


struct Node* head = NULL;

void insertInStart(int val){

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = head;
    head = newNode;
    return;
}

void insertInLast(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    struct Node* curr = head;
    while(curr != NULL){
        curr = curr->next;
    }
    curr->next = newNode;
    return;
}

void displayLinkedList(){

    struct Node* curr = head;
    if (curr == NULL){
        printf("\nLinkedList is empty!!\n");
        return;
    }
    while(curr != NULL){
        printf(" %d --> ",curr->data);
        curr = curr->next;
    }
    printf("NULL");
    return;
}

int main(){


    displayLinkedList();
    insertInStart(9);
    insertInStart(9);
    displayLinkedList();

    return 0;

}



















