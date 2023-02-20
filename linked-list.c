#include <stdio.h>
#include <stdlib.h>


struct node{
    int value;
    struct node* next;
};

void addNode(int value);
void printList();
void deleteNode(int data);

int main() {

    struct node list;


    addNode(5);
    addNode(2);
    addNode(3);
    addNode(6);
    addNode(4);
    addNode(7);
    addNode(1);
    printList();


    return 0;
}


struct node *head = NULL;
struct node *tail = NULL;



void addNode(int value) {
    if (head == NULL) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->value = value;
        newNode->next = NULL;

        head = tail = newNode;
    }
    else {
        struct node *index = head;
        struct node *prev;
        struct node *newNode = (struct node *) malloc(sizeof(struct node));

        if (index->value > value) {
            newNode->value = value;
            newNode->next = index;
            head = newNode;
        }
        else if (tail->value < value) {
            newNode->value = value;
            newNode->next = NULL;
            tail->next = newNode;
            tail = newNode;
        }
        else {
            while (index != NULL) {
                if (index->value > value) {
                    newNode->value = value;
                    newNode->next = index;
                    prev->next = newNode;
                    break;
                }
                else{
                    prev = index;
                    index = index->next;
                }
            }
        }
    }
}


void deleteNode(int data) {

    if (head == NULL) {
        printf("List is empty");
    }
    if (head->value == data) {
        struct node *t = head;
        head = head->next;
        free(t);
    }
    struct node* prev;
    struct node* index = head;

    while (index != NULL) {

        if (index->value == data) {
            struct node *t = index->next;

            prev->next = t;
            free(index);
            break;
        }else {
            prev = index;
            index = index->next;
        }



    }


}



void printList() {
    struct node* index = head;

    while (index!=NULL) {
        printf("%d\n" , index->value);
        index = index->next;
    }
}