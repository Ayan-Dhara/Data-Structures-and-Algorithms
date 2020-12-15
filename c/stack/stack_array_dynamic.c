/*
 * Program for implementing
 * stack operations
 * using array with
 * dynamic memory allocation
 */

#include<stdio.h>
#include<malloc.h>

int *stack;
int count = 0; //number of elements in stack

void pop(){
    if(count == 0)
        printf("\nThe stack is empty!");
    else
        printf("\n %d popped from the stack.", stack[--count]);
}

void push(){
    stack = realloc(stack, sizeof(int)*(count+1));
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
    printf(" Stack using dynamic memory allocation\n");
    printf(" *************************************\n\n");
    printf("Enter the no of elements in the stack:");
    scanf("%d", &count);
    stack = (int*)malloc(sizeof(int)*count);
    if(stack == NULL){
        printf("Cannot allocate memory block...");
        return 1;
    }
    if(count>0)
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
    free(stack);
    printf("Exiting program...\n\n");
    return 0;
}
