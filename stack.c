#include <stdio.h>
#include <stdlib.h>


struct stack{
    int value;
    struct stack* next;
};

struct stack *head = NULL;
struct stack *tail = NULL;

void push(int value);
void pop();
void print();

int main(void) {
    push(10);
    push(20);
    push(30);
    pop();
    print();


}




void push(int value) {
    if (head == NULL) {
        struct stack *node = malloc(sizeof(struct stack));

        node->value = value;
        node->next = NULL;

        head = tail = node;
    }
    else {
        struct stack *node = malloc(sizeof(struct stack));
        node->value = value;
        node->next = tail;

        tail = node;
    }
}


void pop() {
    if (head == NULL){
        return;
    }

    struct stack *tmp = tail->next;

    free(tail);
    tail = tmp;
}


void print() {
    struct stack *iterator = tail;
    while (iterator != NULL) {
        printf("%d\n",iterator->value);
        iterator = iterator->next;
    }
    free(iterator);
}