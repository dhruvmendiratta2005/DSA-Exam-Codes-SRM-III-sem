#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
    struct Node * prev;
};

struct Node * createnode(int data){
    struct Node * newNode = (struct node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}

void insertatstart(struct Node ** head, int data){
    struct Node * newNode = createnode(data);
    newNode->next=(*head);
    (*head)->prev=newNode;
    *head=newNode;
}

void insertatend(struct Node ** head, int data){
    struct Node * newNode = createnode(data);
    struct Node * temp = *head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
}

void insertatpos( struct Node ** head, int data, int pos){
    if(pos<1){
        printf("Invalid position");
        return;
    }
    if(pos==1){
        insertatstart(&head, data);
    }
    struct Node * newNode = createnode(data);
    struct Node * temp = *head;
    for ( int i=2; i<pos ; i++){
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next->prev=newNode;
    temp->next=newNode;
    newNode->prev=temp;
}

//delete at start
void deleteatstart(struct Node ** head){
    if((*head)==NULL){
        printf("List is empty");
    }
    struct Node * temp=*head;
    *head=(*head)->next;
    (*head)->prev=NULL;
    free(temp);
}

// dtlete at end
void deleteatend(struct Node **head){
    if((*head)==NULL){
        printf("List is empty");
    }
    struct Node * temp= *head;
    while(temp->next->next !=NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
}

// delete at position
void deleteatmid(struct Node ** head, int pos){
    if(pos<1){
        printf("Invalid position");
        return;
    }
    if(pos==1){
        deleteatstart(&head);
        return;
    }
    struct Node * temp1=*head;
    struct Node * temp2=(*head)->next;
    for ( int i =2; i<pos ;i++){
        temp1=temp1->next;
        temp2=temp2->next;
    }
    temp1->next=temp2->next;
    temp2->next->prev=temp1;
    free(temp2);
}