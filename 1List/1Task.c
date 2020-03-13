#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node* next;
    int value;
} Node;

typedef struct{
    Node* first;
    int size;
} FifoQueue;

void printQueue(FifoQueue *queue);
void enqueueNode(FifoQueue *queue, Node *node);
void enqueueValue(FifoQueue *queue, int value);
Node* dequeue(FifoQueue *queue);


int main(int argc, char** argv){
    FifoQueue *queue = malloc(sizeof(FifoQueue));
    
    for(int i=0; i<15; i++){
        enqueueValue(queue, i);
        printQueue(queue);
    }
    for(int i=0; i<10; i++){
        dequeue(queue);
        printQueue(queue);
    }
    for(int i=15; i<20; i++){
        enqueueValue(queue, i);
        printQueue(queue);
    }
    for(int i=0; i<10; i++){
        dequeue(queue);
        printQueue(queue);
    }
}

void enqueue(FifoQueue *queue, Node *newNode){
    if(queue->size == 0)
        queue->first = newNode;
    else{
        Node *first = queue->first;
        while(first->next != NULL){
            first = first->next;
        }
        first->next = newNode;
    }
    queue->size++;
}

void enqueueValue(FifoQueue *queue, int value){
    Node *newNode = malloc(sizeof(newNode));
    newNode->next = NULL;
    newNode->value = value;
    if(queue->size == 0)
        queue->first = newNode;
    else{
        Node *first = queue->first;
        while(first->next != NULL){
            first = first->next;
        }
        first->next = newNode;
    }
    queue->size++;
}

Node* dequeue(FifoQueue *queue){
    if(queue->size == 0)
        return NULL;
    Node* node = queue->first;
    queue->first = node->next;
    queue->size--;
    return node;
}

void printQueue(FifoQueue *queue){
    printf("Size: %d\n", queue->size);
    Node *first = queue->first;
    while(first != NULL){
        printf("%d -> ", first->value);
        first = first->next;
    }
    printf("NULL\n");
}
