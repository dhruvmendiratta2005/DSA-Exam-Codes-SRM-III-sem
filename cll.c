#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

struct Node * createnode(int data){
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void insertatbeginning(struct Node ** head, int data){
    struct Node * newNode=createnode(data);
    if(*head==NULL){
        *head=newNode;
        newNode->next=newNode;
    }
    else{
        newNode->next=*head;
        struct Node * temp=*head;
        while(temp->next!=*head){
            temp=temp->next;
        }
        temp->next=newNode;
        *head=newNode;
    }
}

void insertatend(struct Node ** head, int data){
    struct Node * newNode=createnode(data);
    if(*head==NULL){
        *head=newNode;
        newNode->next=newNode;
    }
    else{
        struct Node * temp=*head;
        while(temp->next!=*head){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next=*head;
    }
}

void insertatpos(struct Node** head, int data, int pos){
    if (pos<1){
        printf("Invalid position");
        return;
    }
    if(pos==1){
        insertatbeginning(head,data);
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

void deleteatstart(struct Node ** head){
    if(*head==NULL){
        printf("List is empty");
        return;
    }
    struct Node * temp=*head;
    *head=(*head)->next;
    struct Node * last=*head;
    while(last->next!=temp){
        last=last->next;
    }
    last->next=*head;
    free(temp);
}

void deleteatend(struct Node** head){
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

void deleteatpos(struct Node ** head, int pos){
    if( pos<1){
        printf("Invalid position");
        return;
    }
    if(pos==1){
        deleteatstart(head);
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

void traverse(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    printf("%d ",temp->data);
    temp = temp->next;
    while (temp != head) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main(){
    struct Node * head=NULL;
    insertatbeginning(&head,10);
    insertatbeginning(&head,20);
    insertatbeginning(&head,30);
    insertatend(&head,40);
    insertatpos(&head,50,3);
    traverse(head);
    deleteatstart(&head);
    traverse(head);
    deleteatend(&head);
    traverse(head);
    return 0;
}