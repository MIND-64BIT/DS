
#include<stdio.h>
#define size 50


int arr[size],front = -1, rear = -1;


void enqueue(int val){

    if(rear + 1 == front){
        printf("Queue is empty..");
    }
    if(front == -1){
        front = 0;
    }
    rear = (rear + 1)%size;

    arr[rear] = val;

    return;
}

int dequeue(){
    int removed_element;

    if(front + 1 > rear){
        printf("IndexError: queue is empty");
        return -1;
    }

    removed_element = arr[front];
    front = (front + 1)%size;


    return removed_element;
}


void display(){

    int i = front;

    if((front + 1 > rear) && (front != 0)){
        printf("IndexError: queue is empty");
        return;
    }


    while(i <= rear){
        printf("%d ",arr[i]);
        i = (i + 1) % size;
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
