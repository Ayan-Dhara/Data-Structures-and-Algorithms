/*
 * Program for implementing
 * queue operations
 * using array with
 * dynamic memory allocation
 */

#include<stdio.h>
#include<stdlib.h>

int *queue;
int front=0; //where to push the element
int back=0; //from where to pop the element

void pop(){
    if(front==0)
        printf("\nThe queue is empty!");
    else{
        printf("\n %d popped from the queue.",queue[back++]);
        if(front==back)
            front=back=0;
    }
}

void push(){
    queue=realloc(queue,sizeof(int)*(front+1));
    printf("\nEnter the element:");
    scanf("%d",&queue[front]);
    printf(" %d pushed to the queue.",queue[front]);
    front++;
}

void show(){
    int i;
    if(front==0)
        printf("\nThere are no element in the queue.");
    else{
        printf("\nThe elements are:");
        for(i=back;i<front;i++){
            if(i>back)
                printf(",");
            printf(" %d",queue[i]);
        }
    }
}

int main(){
    int i,o;
    printf(" Queue using dynamic memory allocation\n");
    printf(" *************************************\n\n");
    printf("Enter the no of elements in the queue :");
    scanf("%d",&front);
    queue=(int*)malloc(sizeof(int)*front);
    if(queue==NULL){
        printf("Cannot allocate memory block...");
        return 1;
    }
    if(front>0)
        printf("Enter the elements:");
    for(i=0;i<front;i++)
        scanf("%d",&queue[i]);
    show();
    while(1){
        printf("\n\nChoose an option:\n");
        printf("  1. Push element\n");
        printf("  2. Pop element\n");
        printf("  3. Show elements\n");
        printf("  0. Exit");
        printf("\n\nEnter choice:");
        scanf("%d",&o);
        if(o==0)
            break;
        else if(o==1)
            push();
        else if(o==2)
            pop();
        else if(o==3)
            show();
        else
            printf("Wrong choice...\n");
    }
    printf("Exiting program...\n\n");
    return 0;
}
