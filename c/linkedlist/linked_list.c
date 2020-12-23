/*
 * Implementing list using Linked-list
 */

#include<stdio.h>
#include<malloc.h>

struct node{
    int value;
    struct node *next;
}*headNode = NULL;

void push(){
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

void pushAt(){
    int i = 0;
    int position;
    struct node *newNode, *tempNode = NULL;

    printf("\nEnter the position to push:");
    scanf("%d", &position);

    if(headNode == NULL){
        if(position == 0)
            headNode = newNode = (struct node*)malloc(sizeof(struct node));
        else{
            printf("Cannot push at %d. List is empty.", position);
            return;
        }
    }
    else if(position == 0){
        newNode = (struct node*)malloc(sizeof(struct node));
        tempNode = headNode;
        headNode = newNode;
    }
    else{
        newNode = headNode;
        for(i = 0; i < position-1; i++){
            if(newNode->next)
                newNode = newNode->next;
            else{
                printf("Cannot push at %d. Length of list is %d.", position, i+1);
                return;
            }
        }
        tempNode = newNode->next;
        newNode->next = (struct node*)malloc(sizeof(struct node));
        newNode = newNode->next;
    }
    if(newNode == NULL){
        printf("Cannot allocate memory block...");
        return;
    }
    newNode->next = tempNode;
    printf("Enter the element:");
    scanf("%d", &newNode->value);
    printf(" %d is pushed at %d.", newNode->value, position);
}

void getAt(){
    int i = 0;
    int position;
    struct node *currentNode;

    if(headNode == NULL)
        printf("\nList is empty.");
    else{
        printf("\nEnter the position:");
        scanf("%d", &position);
        currentNode = headNode;
        for(i = 0; i < position; i++){
            if(currentNode->next)
                currentNode = currentNode->next;
            else{
                printf("Nothing at %d. Length of list is %d.", position, i+1);
                return;
            }
        }
        printf("Element at %d is %d.", position, currentNode->value);
    }
}

void search(){
    int i = 0, found = 0;
    int element;
    struct node *currentNode;

    if(headNode == NULL)
        printf("\nList is empty.");
    else{
        printf("\nEnter the element:");
        scanf("%d", &element);

        currentNode = headNode;
        while(currentNode){
            if(currentNode->value == element){
                if(found++)
                    printf(", %d", i);
                else
                    printf(" %d is found at %d", element, i);
            }
            currentNode = currentNode->next;
            i++;
        }
        if(!found)
            printf(" %d is not found in the list.", element);
    }
}

void deleteValue(){
    int i = 0, found = 0;
    int element;
    struct node *currentNode, *prevNode = NULL;

    if(headNode == NULL)
        printf("\nList is empty.");
    else{
        printf("\nEnter the element:");
        scanf("%d", &element);
        currentNode = headNode;
        while(currentNode){
            if(currentNode->value == element){
                if(prevNode == NULL){
                    headNode = currentNode->next;
                    free(currentNode);
                    currentNode = headNode;
                }
                else{
                    prevNode->next = currentNode->next;
                    free(currentNode);
                    currentNode = prevNode->next;
                }
                if(found++)
                    printf(", %d", i);
                else
                    printf(" %d is deleted from position %d", element, i);
            }
            else{
                prevNode = currentNode;
                currentNode = currentNode->next;
            }
            i++;
        }
        if(!found)
            printf("Nothing deleted.");
    }
}

void deleteAt(){
    int i = 0;
    int position,value;
    struct node *currentNode, *prevNode=NULL;

    if(headNode == NULL)
        printf("\nList is empty.");
    else{
        printf("\nEnter the position:");
        scanf("%d", &position);
        currentNode = headNode;
        for(i = 0; i < position; i++){
            if(currentNode->next){
                prevNode = currentNode;
                currentNode = currentNode->next;
            }
            else{
                printf("Nothing at %d. Length of list is %d.", position, i+1);
                return;
            }
        }
        if(prevNode){
            prevNode->next = currentNode->next;
            value = currentNode->value;
            free(currentNode);
        }
        else{
            value = headNode->value;
            headNode = headNode->next;
            free(currentNode);
        }
        printf(" %d is deleted from position %d.", value, position);
    }
}

void viewList(){
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
    printf(" Implementation of list using Linked-list\n");
    printf(" ****************************************\n\n");

    init();
    viewList();

    while(1){
        printf("\n\nChoose an option:\n");
        printf("  1. Push element                2. Push element at position\n");
        printf("  3. Search element from list    4. Get element from position\n");
        printf("  5. Delete element              6. Delete element from position\n");
        printf("  7. Show all elements in list   8. Delete all elements in list\n");
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
                pushAt();
                break;
            case 3:
                search();
                break;
            case 4:
                getAt();
                break;
            case 5:
                deleteValue();
                break;
            case 6:
                deleteAt();
                break;
            case 7:
                viewList();
                break;
            case 8:
                deleteList();
                break;
            default:
                printf("Wrong choice...\n");
        }
    }
    deleteList();
    printf("\nExiting program...\n\n");
    return 0;
}
