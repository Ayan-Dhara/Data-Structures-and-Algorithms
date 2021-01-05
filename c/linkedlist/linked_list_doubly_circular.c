/*
 * Implementing list using doubly Linked-list
 */

#include<stdio.h>
#include<malloc.h>

struct node{
    int value;
    struct node *next;
    struct node *prev;
}*headNode = NULL;

void push(){
    struct node *newNode;

    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("\nCannot allocate memory block...");
        return;
    }

    if(headNode == NULL){
        headNode = newNode;
        newNode->prev = headNode;
    }
    else{
        headNode->prev->next = newNode;
        newNode->prev = headNode->prev;
        headNode->prev = newNode;
    }
    newNode->next = headNode;
    printf("\nEnter the element:");
    scanf("%d", &newNode->value);
    printf(" %d is pushed to the list.", newNode->value);
}

void pushAt(){
    int i = 0;
    int position;
    struct node *newNode, *tempNode = NULL;

    printf("\nEnter the position to push:");
    scanf("%d", &position);

    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("\nCannot allocate memory block...");
        return;
    }

    if(position == 0){
        newNode->next = headNode;
        newNode->prev = headNode->prev;
        headNode->prev = newNode;
        newNode->prev->next = newNode;
        headNode = newNode;
    }
    else if(headNode == NULL){
        printf("Cannot push at %d. List is empty.", position);
        return;
    }
    else{
        tempNode = headNode;
        for(i = 0; i < position - 1; i++){
            if(tempNode->next != headNode)
                tempNode = tempNode->next;
            else{
                printf("Cannot push at %d. Length of list is %d.", position, i+1);
                return;
            }
        }
        newNode->next = tempNode->next;
        newNode->prev = tempNode;
        newNode->next->prev = newNode;
        tempNode->next = newNode;
    }
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
            if(currentNode->next != headNode)
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
            if(currentNode == headNode)
                break;
            i++;
        }
        if(!found)
            printf(" %d is not found in the list.", element);
    }
}

void deleteValue(){
    int i = 0, found = 0;
    int element;
    struct node *currentNode, *tempNode;

    if(headNode == NULL)
        printf("\nList is empty.");
    else{
        printf("\nEnter the element:");
        scanf("%d", &element);
        currentNode = headNode;
        while(currentNode){
            if(currentNode->value == element){
                if(headNode->next == headNode){
                    free(headNode);
                    currentNode = headNode = NULL;
                }
                else{
                    currentNode->next->prev = currentNode->prev;
                    currentNode->prev->next = currentNode->next;
                    tempNode = currentNode;
                    currentNode = currentNode->next;
                    free(tempNode);
                }
                if(found++)
                    printf(", %d", i);
                else
                    printf(" %d is deleted from position %d", element, i);
            }
            else
                currentNode = currentNode->next;
            i++;
            if(currentNode == headNode)
                break;
        }
        if(!found)
            printf("Nothing deleted.");
    }
}

void deleteAt(){
    int i = 0;
    int position,value;
    struct node *currentNode, *tempNode;

    if(headNode == NULL)
        printf("\nList is empty.");
    else{
        printf("\nEnter the position:");
        scanf("%d", &position);
        currentNode = headNode;
        for(i = 0; i < position; i++){
            if(currentNode->next != headNode)
                currentNode = currentNode->next;
            else{
                printf("Nothing at %d. Length of list is %d.", position, i+1);
                return;
            }
        }
        if(headNode->next == headNode){
            value = headNode->value;
            free(headNode);
            headNode = NULL;
        }
        else{
            currentNode->next->prev = currentNode->prev;
            currentNode->prev->next = currentNode->next;
            value = currentNode->value;
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
            if(currentNode == headNode)
                break;
            printf(",");
        }
    }
}

void viewReverse(){
    struct node *currentNode;
    if(headNode == NULL)
        printf("\nThe list is empty.");
    else{
        printf("\nThe elements in the list:");
        currentNode = headNode->prev;
        while(currentNode){
            printf(" %d", currentNode->value);
            currentNode = currentNode->prev;
            if(currentNode == headNode->prev)
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
    struct node* newNode, *prevNode = NULL;
    printf("Enter the no of elements in the list:");
    scanf("%d", &count);
    if(count > 0){
        printf("Enter the values in the list:");
        for(i=0; i < count; i++){
            newNode = (struct node*)malloc(sizeof(struct node));
            if(newNode == NULL){
                printf("\nCannot allocate memory block...");
                return;
            }
            if(headNode == NULL){
                headNode = newNode;
                newNode->next = newNode->prev = headNode;
            }
            else{
                prevNode->next = newNode;
                newNode->prev = prevNode;
                newNode->next = headNode;
                headNode->prev = newNode;
            }
            prevNode = newNode;
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
        printf("  7. Show all elements in list   8. Show all elements in reverse\n");
        printf("  9. Delete all elements in list\n");
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
                viewReverse();
                break;
            case 9:
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
