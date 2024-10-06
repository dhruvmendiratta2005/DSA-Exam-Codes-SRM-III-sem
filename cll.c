#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

struct Node * createnode(int data){
    struct Node * newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertatbeginning(struct Node ** head,int data){
    struct Node * newNode = createnode(data);
    if(*head=NULL){
        *head = newNode;
        newNode->next=newNode;
    } else{
        newNode->next=*head;
        struct Node * temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
        *head=newNode;
    }
}

void insertatend(struct Node ** head, int data){
    struct Node * newNode = createnode(data);
    if(*head=NULL){
        *head = newNode;
        newNode->next=newNode;
    }else{
        struct Node * temp = *head;
        while (temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next=*head;
    }
}

void insertatpos(struct Node ** head, int data,int pos){
    if(pos<1){
        printf("Invalid position");
        return;
    }
    if(pos==1){
        insertatbeginning(&head,data);
        return;
    }
    struct Node * newNode = createnode(data);
    struct Node * temp = *head;
    for(int i=2; i<pos;i++){
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}

void deleteatstart(struct Node ** head){
    if(*head==NULL){
        printf("List is empty");
        return;
    }
    else{
        struct Node * temp=*head;
        *head=temp->next;
        struct Node * last=*head;
        while(last->next!=temp){
            last=last->next;
        }
        last->next=*head;
        free(temp);
    }
}

void deleteatend(struct Node **head){
    if(*head==NULL){
        printf("List is empty");
        return;
    }
    struct Node * temp=*head;
    while(temp->next->next!=*head){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=*head;
}



