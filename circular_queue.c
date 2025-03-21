
#include<stdio.h>
#define size 5


int arr[size],front = -1, rear = -1;


void enqueue(int val){

    if((rear + 1) % size == front){
        printf("Queue is full..");
        return;
    }

    if(front == -1){
        front = 0;
    }
    rear = (rear + 1) % size;

    arr[rear] = val;

    return;
}

int dequeue(){
    int removed_element;

    if(front == rear && front != 0){
        printf("IndexError: queue is empty");
        return -1;
    }

    removed_element = arr[front];
    front = (front + 1) % size;

    if(front == rear){
        front = 0;
        rear = 0;
    }

    if(front > rear){
        front = -1;
        rear = -1;
    }

    return removed_element;
}


void display(){

    int i = front;

    if(front == rear && front != 0){
        printf("IndexError: queue is empty");
        return;
    }

    for(i; i != rear; i = (i + 1)%size){
        printf("%d",arr[i]);
    }
    return;
}


int main(){

    int option, value, dequeue_val;

    while(1){

        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nChoice: ");
        scanf(" %d",&option);

        switch(option){

            case 1:
                printf("\nEnter value to enqueue: ");
                scanf(" %d",&value);

                enqueue(value);
                break;

            case 2:

                dequeue_val = dequeue();
                if(dequeue_val != -1) printf("\n%d is removed", dequeue_val);
                break;
            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("\nEnter a valid option");

        }
    }

    return 0;

}
