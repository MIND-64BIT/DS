
#include<stdio.h>
#define size 10

int arr[size],top = -1;

void push(int val){

    if(isFull()){
        printf("\nIndexError: inserting in full stack");
        return;
    }

    arr[top+1] = val;
    top++;

return;
}


int* pop(){

    int *lastEle;

    if(isEmpty()){
        printf("\nIndexError: poping from empty stack");
        return NULL;
    }

    lastEle = &arr[top];
    top--;

    return lastEle;
}


int isEmpty(){

    if(top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(){

    if(top == size-1){
        return 1;
    }
    else{
        return 0;
    }
}


void display(){

    for(int i = top; i != -1; i--){
        printf("%d\t", arr[i]);
    }

    return;
}

void ptop(){

    if(isEmpty()){
        printf("\nEmptyError: stack is empty");
    }
    else{
        printf("TOP: %d",arr[top]);
    }

    return;
}



int main(){

int choice;

while(1){

    int value;
    int* popedEle;

    printf("\n\n1-> Push\n2-> Pop\n3-> IsEmpty\n4-> IsFull\n5-> Display\n6-> TOP\nChoice: ");
    scanf(" %d",&choice);

    switch(choice){

        case 1:

            printf("\nEnter value to push: ");
            scanf("%d",&value);
            push(value);
            printf("\n%d is pushed in the stack",value);

            break;

        case 2:

            popedEle = pop();
            printf("\n%d is poped from the stack ", *popedEle);

            break;

        case 3:

            if(isEmpty()){
                printf("\nTrue");
            }
            else{
                printf("\nFalse");
            }

            break;


        case 4:

            if(isFull()){
                printf("\nTrue");
            }
            else{
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

            printf("\nEnter valid choice");


    }

}


return 0;

}
