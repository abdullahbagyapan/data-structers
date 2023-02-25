#include <stdio.h>
#include <stdlib.h>


struct node {
    int value;
    struct node * next;
    struct node * previous;
};


struct node* head;
struct node* tail;

void insertNode(int value) {
    if (head == NULL) {
        struct node *newNode = malloc(sizeof(struct node));

        newNode->value = value;
        newNode->next = NULL;
        newNode->previous = NULL;

        head = tail = newNode;
    }
    else {
        struct node *newNode = malloc(sizeof(struct node));

        newNode->value = value;
        newNode->previous = tail;
        newNode->next = NULL;

        tail->next = newNode;
        tail = newNode;
    }
}

void deleteNode() {  // this func could be handled with less memory, but make it harder to read
    if (head == NULL) {
        return;
    }
    struct node* tmp = tail->previous;

    tmp->next = NULL;
    free(tail);
    tail = tmp;

}


void printLinkedList() {
    struct node *iterator = head;

    while (iterator != NULL) {
        printf("%d\n",iterator->value);
        iterator = iterator->next;
    }
}



int main(void){

    insertNode(1);
    insertNode(2);
    insertNode(3);
    insertNode(4);
    deleteNode();
    printLinkedList();

}