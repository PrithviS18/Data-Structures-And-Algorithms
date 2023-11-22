#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
// This library is used for boolean in c
#define capacity 2
struct Queue{
    int front,rear,size;
    int arr[capacity];
};

void initialize(struct Queue** queue){
    (*queue)->front=0,(*queue)->rear=1,(*queue)->size=0;
}

// Checks if the Queue is full
bool isfull (struct Queue* queue){
    return (queue->size==capacity);
}

// Checks if the Queue is empty
bool isempty(struct Queue* queue){
    return (queue->size==0);
}

// Pushes a new number into the Queue
void enqueue(struct Queue* queue,int newdata){
    if (!isfull(queue)){
        // We use this line because when we dequeue the front may exceed 
        queue->rear=(queue->rear +1)%capacity;
        
        queue->arr[queue->rear]=newdata;
        queue->size++;
    }
    else {
        printf("Cannot Enqueue. Queue is full\n");
    }
}

// Removes the first element int the queue
void dequeue(struct Queue* queue){
    if (!isempty(queue)){
        queue->front=(queue->front +1)%capacity;
        
        queue->size--;
    }
    else {
        printf("Cannot Dequeue. Queue is empty\n");
    }
}

// Returns the first element of the Queue
void front(struct Queue* queue){
    if (!isempty(queue)){
        printf("%d\n",queue->arr[queue->front]);
    }
    else {
        printf("Queue is empty\n");
    }
}

// Returns the Last Element of the Queue
void rear(struct Queue* queue){
    if (!isempty(queue)){
        printf("%d\n",queue->arr[queue->rear]);
    }
    else {
        printf("Queue is empty\n");
    }
}


int main() {
    struct Queue* queue;
    initialize(&queue);
    enqueue(queue,10);
    enqueue(queue,20);
    dequeue(queue);
    front(queue);
}
