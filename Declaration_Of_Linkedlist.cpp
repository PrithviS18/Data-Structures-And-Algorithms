#include<stdio.h>
#include <stdlib.h>
// In this code stdlib is used for the memory allocation proccess

// Declaration of Node
struct Node {
    int data;
    struct Node* next;
};


int main() {
    // Linkedlist Declaration Starts
    struct Node* head= NULL;
    
    struct Node* node1=(struct Node*)malloc(sizeof(struct Node));
    struct Node* node2=(struct Node*)malloc (sizeof(struct Node));
    struct Node* node3=(struct Node*)malloc (sizeof(struct Node));
    
    node1->data=10;
    node2->data=20;
    node3->data=30;
    
    node1->next=node2;
    node2->next=node3;
    node3->next=NULL;
    
    head=node1;
    // Linked List Declaration Ends
    
    // Traversal of Linked List
    struct Node* current= head;
    while (current!=NULL){
        printf("%d ",current->data);
        current=current->next;
    }
    
    // Making the memory allocated free again
    free(node1);
    free(node2);
    free(node3);
    
}
