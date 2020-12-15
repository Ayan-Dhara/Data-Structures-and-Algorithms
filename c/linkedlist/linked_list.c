/*
 * Implementing list using Linked-list
 */

#include<stdio.h>
#include<malloc.h>

int count = 0;

struct node{
    int value;
    struct node *next;
};

struct node *headNode = NULL;

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
        printf("Cannot allocate memory block...");
        return;
    }
    newNode->next = NULL;
    printf("Enter the element:");
    scanf("%d", &newNode->value);
    count++;
}

void pushAt(){
    int i = 0;
    int position;
    struct node *newNode, *temp = NULL;

    printf("Enter the position to push:");
    scanf("%d", &position);

    if(headNode == NULL){
        if(position == 0)
            headNode = newNode = (struct node*)malloc(sizeof(struct node));
        else
            printf("Cannot push at %d. List is empty.", position);
    }
    else{
        newNode = headNode;
        for(i = 0; i < position-1; i++){
            if(newNode->next)
                newNode = newNode->next;
            else{
                printf("Cannot push at %d. Length of list is %d.", position, i+2);
                return;
            }
        }
        temp = newNode->next;
        newNode->next = (struct node*)malloc(sizeof(struct node));
        newNode = newNode->next;
    }
    newNode->next = temp;
    printf("Enter the element:");
    scanf("%d", &newNode->value);
    count++;
}

void getAt(){
    int i = 0;
    int position;
    struct node *currentNode;

    if(headNode == NULL)
        printf("List is empty.");
    else{
        printf("Enter the position:");
        scanf("%d", &position);
        currentNode = headNode;
        for(i = 0; i < position; i++){
            if(currentNode->next)
                currentNode = currentNode->next;
            else{
                printf("Nothing at %d. Length of list is %d.", position, i+2);
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
        printf("List is empty.");
    else{
        printf("Enter the element:");
        scanf("%d", &element);

        currentNode = headNode;
        while(currentNode){
            if(currentNode->value == element){
                if(found++ == 0)
                    printf("%d is found at %d", element, i);
                else
                    printf(", %d", i);
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
    struct node *currentNode, *tempNode = NULL, *prevNode = NULL;

    if(headNode == NULL)
        printf("List is empty.");
    else{
        printf("Enter the element:");
        scanf("%d", &element);
        currentNode = headNode;
        while(currentNode){
            if(currentNode->value == element){
                printf("Deleting: ");
                if(prevNode == NULL){
                    printf("prevNode is NULL\n");
                    headNode = currentNode->next;
                    free(currentNode);
                    currentNode = headNode;
                }
                else{
                    printf("prevValue is %d. headValue is %d\n", prevNode->value, headNode->value);
                    prevNode->next = currentNode->next;
                    free(currentNode);
                    currentNode = prevNode->next;
                }
                if(found++ == 0)
                    printf("%d is deleted from position %d", element, i);
                else
                    printf(", %d", i);
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
    int position;
    struct node *currentNode, *prevNode=NULL;

    if(headNode == NULL)
        printf("List is empty.");
    else{
        printf("Enter the position:");
        scanf("%d", &position);
        currentNode = headNode;
        for(i = 0; i < position; i++){
            if(currentNode->next){
                prevNode = currentNode;
                currentNode = currentNode->next;
            }
            else{
                printf("Nothing at %d. Length of list is %d.", position, i+2);
                return;
            }
        }
        if(prevNode){
            prevNode->next = currentNode->next;
            free(currentNode);
        }
        else{
            headNode = headNode->next;
            free(currentNode);
        }
    }
}

void viewList(){
    struct node *currentNode;
    if(headNode == NULL)
        printf("The list is empty.");
    else{
        printf("The elements in the list:");
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
        printf("The list is already empty.");
    else{
        currentNode = headNode;
        while(currentNode){
            tempNode = currentNode;
            currentNode = currentNode->next;
            if(currentNode)
                printf(",");
            free(tempNode);
        }
    }
    headNode = NULL;
    printf("The list is deleted.");
}

int main(){
    int i, option;
    struct node* newNode;
    printf(" Implementation of list using Linked-list\n");
    printf(" ****************************************\n\n");
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
                return 1;
            }
            newNode->next = NULL;
            scanf("%d", &newNode->value);
        }
    }

    viewList();

    while(1){
        printf("\n\nChoose an option:\n");
        printf("  1. Push element                2. Push element at position\n");
        printf("  3. Get element from position   4. Search element from list\n");
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
                getAt();
                break;
            case 4:
                search();
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
    printf("Exiting program...\n\n");
    return 0;
}
