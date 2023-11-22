#include<stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node* next;
};
void insertEnd (struct Node ** head, int newdata){
    struct Node* temp= (struct Node*)malloc(sizeof (struct Node));
    temp->data=newdata;
    temp->next=NULL;
    if (*head==NULL){
        *head=temp;
        return;
    }
    struct Node* curr=*head;
    while (curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=temp;
}
// Deletes the first element of the LinkedList
void deleteFirst(struct Node** head){
    if (*head==NULL){
        return;
    }
    struct Node* temp = *head;
    (*head)=(*head)->next;
    free(temp); //We need to free the memory allocated 
}

// Deletes the Last Element of the LinkedList
void deleteEnd (struct Node** head){
    if (*head==NULL)return;
    if ((*head)->next==NULL){
        struct Node* temp= (*head);
        *head=NULL;
        free(temp);
        return;
    }
    struct Node*curr = (*head)->next;
    struct Node* prev= (*head);
    while (curr->next!=NULL){
        curr=curr->next;
        prev=prev->next;
    }
    prev->next=curr->next;
    free(curr);
}

void print(struct Node * head){
    struct Node* curr=head;
    while (curr!=NULL){
        printf("%d ",curr->data);
        curr=curr->next;
    }
}

int main() {
    struct Node* head=NULL;
    insertEnd(&head,10);
    insertEnd(&head,20);
    insertEnd(&head,30);
    
    deleteFirst(&head);
    deleteEnd(&head);
    
    print(head);
}
