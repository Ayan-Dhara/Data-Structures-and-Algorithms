/*
 * Program for implementing
 * circular queue operations
 * using array with
 * static memory allocation
 */

#include<stdio.h>

int MAX = 100;
int queue[100];
int rear = 0; //from where to remove the element
int count = 0; //number of elements in the queue

void dequeue(){
    if(count == 0)
        printf("\nThe queue is empty!");
    else{
        printf("\n %d dequeue from the queue.", queue[rear++]);
        rear = rear % MAX;
        count--;
    }
}

void enqueue(){
    if(count == MAX){
        printf("\nMaximum number of element in the queue reached.");
        return;
    }
    printf("\nEnter the element:");
    scanf("%d", &queue[rear + count]);
    printf(" %d enqueue to the queue.", queue[rear + count]);
    count++;
}

void show(){
    int i;
    if(count == 0)
        printf("\nThere are no element in the queue.");
    else{
        printf("\nThe elements are:");
        for(i = 0; i < count; i++){
            if(i > 0)
                printf(",");
            printf(" %d", queue[i + rear]);
        }
    }
}

int main(){
    int i, option;
    printf(" Circular Queue using static memory allocation\n");
    printf(" *********************************************\n\n");
    printf("Enter the no of elements in the queue (max %d):",MAX);
    scanf("%d",&count);
    if(count > MAX){
        printf("You can add only %d elements.\n",MAX);
        count = MAX;
    }
    if(count > 0)
        printf("Enter the elements:");
    for(i = 0; i < count; i++)
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
