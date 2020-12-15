/*
 * Program for implementing
 * queue operations
 * using array with
 * static memory allocation
 */

#include<stdio.h>

int queue[100];
int front = 0; //where to push the element
int back = 0; //from where to pop the element

void pop(){
    if(front == 0)
        printf("\nThe queue is empty!");
    else{
        printf("\n %d popped from the queue.", queue[back++]);
        if(front == back)
            front = back = 0;
    }
}

void push(){
    if(front == 99){
        printf("\nUpper limit of the queue reached.\nPop all elements to insert again");
        return;
    }
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
        for(i = back; i < front; i++){
            if(i > back)
                printf(",");
            printf(" %d", queue[i]);
        }
    }
}

int main(){
    int i, option;
    printf(" Queue using static memory allocation\n");
    printf(" ************************************\n\n");
    printf("Enter the no of elements in the queue (max 100):");
    scanf("%d",&front);
    if(front > 100){
        printf("You can add only 100 elements.\n");
        front = 100;
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
                push();
                break;
            case 2:
                pop();
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
