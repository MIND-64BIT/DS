
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int val){

    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    if(new_node == NULL){
        printf("\nMemory allocation failed..");
        return;
    }

    new_node->data = val;
    new_node->next = top;
    top = new_node;
    return;
}

struct Node* pop(){

    if(top == NULL){
        printf("\nstack is empty");
        return NULL;
    }

    struct Node *temp = top;
    top = top->next;
    return temp;
}


void display(){
    if(top == NULL){
        printf("\nstack is empty");
        return;
    }
    struct Node *curr = top;
    while(curr != NULL){
        printf(" %d -->",curr->data);
        curr = curr->next;
    }
    printf("END");
    return;
}


int main(){
    int choice, val;
    struct Node *deleted_node;
    do{
    printf("\n1. PUSH\n2. POP\n3. Display\nChoice: ");
    scanf("%d",&choice);

    switch (choice){

        case 1:
            printf("enter value: ");
            scanf("%d", &val);
            push(val);
            break;

        case 2:
            deleted_node = pop();
            if(deleted_node != NULL)
            printf("%d is deleted from the stack",deleted_node->data);
            free(deleted_node);
            break;

        case 3:
            display();
            break;
    }

    }while(0 < choice < 4);


    return 0;
}

