#include<stdio.h>
#include <stdlib.h>
// In this code stdlib is used for the memory allocation proccess

// Declaration of Node
struct Node {
    int data;
    struct Node* next;
};

// Insert at the beginning of a Linkedlist

/*If we use a single pointer in the function then we return 
the head of the fucntion and assign explicitly to the head of the Linked List

 Else if we use a double pointer then we use a void function as we can
 directly change the value of the head in the function*/
 
void insertBeginning(struct Node** head,int ndata){
    struct Node* temp= (struct Node*)malloc (sizeof(struct Node));
    temp->data=ndata;
    temp->next=*head;
    *head=temp;
}
// Insertion at Beginning Ends

// Insertino at End Begins
void insertEnd(struct Node** head,int ndata){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=ndata;
    temp->next=NULL;
    
    // Check if the Linked List is already empty
    if (*head==NULL){
        *head=temp;return;
    }
    struct Node* curr=*head;
    while (curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=temp;
}
// Insertion at End ends

// Print the LinkedList
void Printlist(struct Node* head){
    struct Node* curr=head;
    while (curr!=NULL){
        printf("%d ",curr->data);
        curr=curr->next;
    }
}

int main() {
  struct Node* head=NULL;
  
  insertBeginning(&head,10);
  insertEnd(&head,20);
  
  
  Printlist(head);
}
