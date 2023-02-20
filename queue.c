#include <stdio.h>
#include <stdlib.h>

struct queue{
    int value;
    struct queue* previous;
};

struct queue *head =NULL;
struct queue *tail =NULL;


void Enque(int value);
void printQueue();
void Deque();

int main() {

    Enque(1);
    Enque(13);
    Enque(23);
    Enque(33);
    Deque();
    printQueue();



    return 0;
}



void Enque(int value) {
    if (head == NULL) {
        struct queue* newQueue = (struct node*)malloc(sizeof(struct queue));
        newQueue->value = value;
        newQueue->previous = NULL;

        head = newQueue;
        tail = newQueue;
    }
    else {
        struct queue* newQueue = (struct node*)malloc(sizeof(struct queue));
        newQueue->value = value;
        newQueue->previous = NULL;

        tail->previous = newQueue;
        tail = newQueue;
    }
}

void Deque() { // First in First Out
    if (head == NULL) {
        printf("The queue is empty");
    }
    else {
        struct queue *prev = head->previous;
        free(head);
        head = prev;
    }

}

void printQueue() {
    struct queue *index = head;
    while (index != NULL) {
        printf("%d\n",index->value);
        index = index->previous;
    }
}