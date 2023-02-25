#include <stdio.h>
#include <stdlib.h>





int *arraylist = NULL;

int sizeOfList = 2;
int numberOfValues = 0;
int firstValueIndex = 0;
int lastValueIndex = 0;



void enqueue(int value);
void dequeue();
void expandList();
void resizeList();
void arrangeList( int * tmp);
void printArrayList();





void enqueue(int value) {
    if (arraylist == NULL) {
        arraylist = malloc(sizeof(int)*sizeOfList);
    }

    if (lastValueIndex == sizeOfList) {
        expandList();
        arraylist[lastValueIndex++] = value;
    }else {
        arraylist[lastValueIndex++] = value;
    }
    numberOfValues++;
}

void dequeue() {
    if (arraylist == NULL) {
        return;
    }
    else {
        firstValueIndex++;
    }
    if (sizeOfList/4 > numberOfValues) {""
        resizeList();
    }
    numberOfValues--;
}


void resizeList() {
    int * tmp = malloc(sizeof(sizeOfList/2));
    arrangeList(tmp);
    free(arraylist);
    arraylist = tmp;
    sizeOfList /= 2;
    firstValueIndex = 0;
}

void arrangeList( int * tmp) {
    int i = 0;
    for (int iterator = firstValueIndex ; iterator != lastValueIndex ; iterator++,i++) { // transfer values to new list
        tmp[i] = arraylist[iterator];
    }
    firstValueIndex = 0;
    lastValueIndex = i;
}


void expandList() {
    int * tmp = malloc(sizeof(sizeOfList*2));

    arrangeList(tmp);

    free(arraylist);
    arraylist = tmp;

    sizeOfList *= 2;
}


void printArrayList() {
    int iterator = firstValueIndex;
    while (iterator != lastValueIndex) {
        printf("%d\n",arraylist[iterator]);
        iterator++;
    }
}



int main(void) {
    enqueue(1);
    enqueue(2);
    enqueue(2);
    enqueue(2);
    enqueue(5);
    dequeue();
    resizeList();
    printArrayList();


}