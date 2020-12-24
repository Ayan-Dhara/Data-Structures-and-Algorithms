/*
 * Implementing Queue using Linked-list
 */

#include<stdio.h>
#include<malloc.h>

struct node{
    int value;
    struct node *next;
}*headNode = NULL;

void enqueue(){
    struct node *newNode;
    if(headNode == NULL)
        headNode = newNode = (struct node*)malloc(sizeof(struct node));
    else{
        newNode = headNode;
        while(newNode->next)
            newNode = newNode->next;
        newNode->next = (struct node*)malloc(sizeof(struct node));
        newNode = newNode->next;
    }
    if(newNode == NULL){
        printf("\nCannot allocate memory block...");
        return;
    }
    newNode->next = NULL;
    printf("\nEnter the element:");
    scanf("%d", &newNode->value);
    printf(" %d is pushed to the list.",newNode->value);
}

void dequeue(){
    int i = 0;
    int value;
    struct node *tempNode;

    if(headNode == NULL)
        printf("\nList is empty.");
    else{
        tempNode = headNode;
        value = headNode->value;
        headNode = headNode->next;
        free(tempNode);
        printf(" %d is dequeued from Queue.", value);
    }
}

void show(){
    struct node *currentNode;
    if(headNode == NULL)
        printf("\nThe list is empty.");
    else{
        printf("\nThe elements in the list:");
        currentNode = headNode;
        while(currentNode){
            printf(" %d", currentNode->value);
            currentNode = currentNode->next;
            if(currentNode)
                printf(",");
        }
    }
}

void deleteList(){
    struct node *currentNode, *tempNode;
    if(headNode == NULL)
        printf("\nThe list is already empty.");
    else{
        currentNode = headNode;
        while(currentNode){
            tempNode = currentNode;
            currentNode = currentNode->next;
            free(tempNode);
        }
        printf("\nThe list is deleted.");
    }
    headNode = NULL;
}

void init(){
    int count,i;
    struct node* newNode;
    printf("Enter the no of elements in the list:");
    scanf("%d", &count);
    if(count > 0){
        printf("Enter the values in the list:");
        for(i=0; i < count; i++){
            if(headNode == NULL)
                headNode = newNode = (struct node*)malloc(sizeof(struct node));
            else{
                newNode->next = (struct node*)malloc(sizeof(struct node));
                newNode = newNode->next;
            }
            if(newNode == NULL){
                printf("Cannot allocate memory block...");
                return;
            }
            newNode->next = NULL;
            scanf("%d", &newNode->value);
        }
    }
}

int main(){
    int option;
    printf(" Queue using Linked-list\n");
    printf(" ***********************\n\n");

    init();
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
    deleteList();
    printf("\nExiting program...\n\n");
    return 0;
}
