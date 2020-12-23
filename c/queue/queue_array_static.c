/*
 * Program for implementing
 * queue operations
 * using array with
 * static memory allocation
 */

#include<stdio.h>

int MAX = 100;
int queue[100];
int front = 0; //where to insert the element
int rear = 0; //from where to remove the element

void dequeue(){
    if(front == 0)
        printf("\nThe queue is empty!");
    else{
        printf("\n %d dequeued from the queue.", queue[rear++]);
        if(front == rear)
            front = rear = 0;
    }
}

void enqueue(){
    if(front == MAX){
        printf("\nUpper limit of the queue reached.\nPop all elements to insert again");
        return;
    }
    printf("\nEnter the element:");
    scanf("%d", &queue[front]);
    printf(" %d enqueued to the queue.", queue[front]);
    front++;
}

void show(){
    int i;
    if(front == 0)
        printf("\nThere are no element in the queue.");
    else{
        printf("\nThe elements are:");
        for(i = rear; i < front; i++){
            if(i > rear)
                printf(",");
            printf(" %d", queue[i]);
        }
    }
}

int main(){
    int i, option;
    printf(" Queue using static memory allocation\n");
    printf(" ************************************\n\n");
    printf("Enter the no of elements in the queue (max %d):",MAX);
    scanf("%d",&front);
    if(front > MAX){
        printf("You can add only %d elements.\n",MAX);
        front = MAX;
    }
    if(front > 0)
        printf("Enter the elements:");
    for(i = 0; i < front; i++)
        scanf("%d", &queue[i]);
    show();
    while(1){
        printf("\n\nChoose an option:\n");
        printf("  1. Enqueue element\n");
        printf("  2. Dequeue element\n");
        printf("  3. Show elements\n");
        printf("  0. Exit");
        printf("\n\nEnter choice:");
        scanf("%d", &option);
        if(option == 0)
            break;
        switch(option){
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                show();
                break;
            default:
                printf("Wrong choice...\n");
        }
    }
    printf("Exiting program...\n\n");
    return 0;
}
