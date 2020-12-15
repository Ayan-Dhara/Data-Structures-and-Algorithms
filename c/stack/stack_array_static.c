/*
 * Program for implementing
 * stack operations
 * using array with
 * static memory allocation
 */

#include<stdio.h>

int stack[100];
int count = 0; //number of elements in stack

void pop(){
    if(count == 0)
        printf("\nThe stack is empty!");
    else
        printf("\n %d popped from the stack.", stack[--count]);
}

void push(){
    if(count == 100){
        printf("\nMaximum number of element in the stack reached");
        return;
    }
    printf("\nEnter the element:");
    scanf("%d", &stack[count]);
    printf(" %d pushed to the stack.", stack[count]);
    count++;
}

void show(){
    int i;
    if(count > 0)
        printf("\nThe elements are:");
    else
        printf("\nThere are no element in the stack.");
    for(i = 0; i < count; i++){
        if(i > 0)printf(",");
        printf(" %d", stack[i]);
    }
}

int main(){
    int i, option;
    printf(" Stack using static memory allocation\n");
    printf(" ************************************\n\n");
    printf("Enter the no of elements in the stack (max 100):");
    scanf("%d", &count);
    if(count > 100){
        printf("You can add only 100 elements\n");
        count = 100;
    }
    if(count > 0)
        printf("Enter the elements:");
    for(i = 0; i < count; i++)
        scanf("%d", &stack[i]);
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
