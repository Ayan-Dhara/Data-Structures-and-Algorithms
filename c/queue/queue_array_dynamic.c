/*
 * Program for implementing
 * queue operations
 * using array with
 * dynamic memory allocation
 */

#include<stdio.h>
#include<malloc.h>

int *queue;
int front = 0; //where to push the element
int rear = 0; //from where to pop the element

void dequeue(){
    if(front == 0)
        printf("\nThe queue is empty!");
    else{
        printf("\n %d popped from the queue.", queue[rear++]);
        if(front == rear)
            front = rear = 0;
    }
}

void enqueue(){
    queue = realloc(queue, sizeof(int)*(front+1));
    printf("\nEnter the element:");
    scanf("%d", &queue[front]);
    printf(" %d pushed to the queue.", queue[front]);
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
    printf(" Queue using dynamic memory allocation\n");
    printf(" *************************************\n\n");
    printf("Enter the no of elements in the queue :");
    scanf("%d", &front);
    queue = (int*)malloc(sizeof(int)*front);
    if(queue == NULL){
        printf("Cannot allocate memory block...");
        return 1;
    }
    if(front > 0)
        printf("Enter the elements:");
    for(i = 0; i < front; i++)
        scanf("%d", &queue[i]);
    show();
    while(1){
        printf("\n\nChoose an option:\n");
        printf("  1. Push element\n");
        printf("  2. Pop element\n");
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
    free(queue);
    printf("Exiting program...\n\n");
    return 0;
}
