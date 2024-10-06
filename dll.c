#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node * next;
    struct Node * prev;
};

struct Node * createnode(int data){
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}

void insertatstart(struct Node ** head, int data){
    struct Node * newNode = createnode(data);
    if(*head==NULL){
        *head=newNode;
    }
    else{
        newNode->next=(*head);
        (*head)->prev=newNode;
        *head=newNode;
    }
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

void insertatpos(struct Node ** head, int data, int pos){
    if(pos<1){
        printf("Invalid position");
        return;
    }
    if(pos==1){
        insertatstart(head, data);
        return;
    }
    struct Node * newNode = createnode(data);
    struct Node * temp = *head;
    for(int i=2;i<pos;i++){
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next->prev=newNode;
    temp->next=newNode;
    newNode->prev=temp;
}

void traverse(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void deleteatstart(struct Node ** head){
    if(*head==NULL){
        printf("List is empty");
        return;
    }
    struct Node * temp=*head;
    *head=(*head)->next;
    (*head)->prev=NULL;
    free(temp);
}

void deleteatend(struct Node** head){
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

void deleteatpos(struct Node ** head, int pos){
    if(pos<1){
        printf("Invalid position");
        return;
    }
    if(pos==1){
        deleteatstart(head);
        return;
    }
    struct Node * temp = *head;
    for(int i=2;i<pos;i++){
        temp=temp->next;
    }
    struct Node * temp1 = temp->next;
    temp->next=temp1->next;
    temp1->next->prev=temp;
    free(temp1);
}

int main(){
    struct Node * head = NULL;
    insertatstart(&head, 10);
    insertatstart(&head, 20);
    insertatstart(&head, 30);
    insertatend(&head, 40);
    insertatend(&head, 50);
    insertatpos(&head, 35, 4);
    traverse(head);
    deleteatstart(&head);
    deleteatend(&head);
    deleteatpos(&head, 3);
    traverse(head);
    return 0;
}