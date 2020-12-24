/*
 * Implementing Queue using circular Linked-list
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
        while(newNode->next != headNode)
            newNode = newNode->next;
        newNode->next = (struct node*)malloc(sizeof(struct node));
        newNode = newNode->next;
    }
    if(newNode == NULL){
        printf("\nCannot allocate memory block...");
        return;
    }
    newNode->next = headNode;
    printf("\nEnter the element:");
    scanf("%d", &newNode->value);
    printf(" %d is enqueued to the queue.",newNode->value);
}

void dequeue(){
    int value;
    struct node *lastNode = NULL;

    if(headNode == NULL)
        printf("\nQueue is empty.");
    else{
        lastNode = headNode;
        while(lastNode->next != headNode)
            lastNode = lastNode->next;
        value = headNode->value;
        if(lastNode == headNode){
            free(headNode);
            headNode=NULL;
        }
        else{
            headNode = headNode->next;
            free(lastNode->next);
            lastNode->next = headNode;
        }
        printf(" %d is dequeued from queue.", value);
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
            if(currentNode == headNode)
                break;
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
            if(currentNode == headNode)
                break;
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
            newNode->next = headNode;
            scanf("%d", &newNode->value);
        }
    }
}

int main(){
    int option;
    printf(" circular queue using Linked-list\n");
    printf(" ********************************\n\n");

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
