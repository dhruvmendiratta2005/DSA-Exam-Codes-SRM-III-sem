#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node * next;
};
struct Node * top=NULL;

void push(int data){
    struct Node * newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data=data;
    if(top==NULL){
        newNode->next=NULL;
        top=newNode;
    }
    else{
        newNode->next=top;
        top=newNode;
    }
}

void pop(){
    if(top==NULL){
        printf("\nStack is empty");
    }
    int element=top->data;
    struct Node * temp=top;
    top=top->next;
    free(temp);
    printf("\nThe popped element is: %d",element);
}

void display(){
    if(top==NULL){
        printf("\nStack is empty");
    }
    struct Node * temp= top;
    while(temp!=NULL){
        printf("\n%d ",temp->data);
        temp=temp->next;
    }
}
void peek(){
    if(top==NULL){
        printf("\nStack is empty");
    }
    int element = top->data;
    printf("The top element is: %d",element);
}
int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    peek();
    pop();
    display();
}