#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};
struct Node * createnode(int data){
    struct Node * newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
//insert at beginning
void insertatbeginning(struct Node ** head, int data){
    struct Node * newNode=createNode(data);
    newNode->next=(*head);
    *head=newNode;
}

//insert at end
void insertatend(struct Node ** head,int data){
    struct Node * newNode=createnode(data);
    if(*head==NULL){
        *head=newNode;
        return;
    }
    else{
        struct Node * temp = *head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
}
//insert at position
void insertatmiddle(struct Node ** head,int data, int pos){
    if(pos<1){
        printf("Invalid Position");
        return;
    }
    if (pos==1){
        insertatbeginning(&head,data);
        return;
    }
    struct Node * newNode=createnode(data);
    struct Node * temp=*head;
    for(int i=2;i<pos;i++){
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;    
}
//delete at beginning
void deleteatstart(struct Node **head){
    if(*head==NULL){
        printf("List is empty");
        return;
    }
    struct Node * temp=*head;
    *head=(*head)->next;
    free(temp);
}
//delete at end
void deleteatend(struct Node ** head){
    if(*head==NULL){
        printf("List is empty");
        return;
    }
    struct Node * temp=*head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
}
//delete at position
void deleteatmid(struct Node ** head, int pos){
    if(pos<1){
        printf("Invalid Position");
        return;
    }
    if(pos==1){
        deleteatstart(&head);
        return;
    }
    struct Node * temp1=*head;
    struct Node * temp2=(*head)->next;
    for(int i=2;i<pos;i++){
        temp1=temp1->next;
        temp2=temp2->next;
    }
    temp1->next=temp2->next;
    free(temp2);
}
