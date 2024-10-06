#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};
struct Node * front=NULL;
struct Node * rear=NULL;

void enqueue(int data){
    struct Node * newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    if(front == NULL && rear== NULL){
        front = rear = newNode;
    }else{
        rear->next = newNode;
        rear=newNode;
    }
}

void dequeue(){
    if(front == NULL && rear == NULL){
        printf("Queue is empty");
    }
    else{
        struct Node * temp = front;
        front=front->next;
        int element= temp->data;
        free(temp);
        printf("\nThe dequeued element is %d",element);
    }
}
void display(){
    if(front==NULL && rear== NULL){
        printf("\nQueue is empty");
    }
    else{
        struct Node * temp = front;
        while(temp!=NULL){
            printf("\n%d ",temp->data);
            temp=temp->next;
        }
    }

}

void peek(){
    if(front == NULL && rear == NULL){
        printf("\nQueue is empty");
    }
    else{
        printf("\nThe front element is %d",front->data);
    }
}
int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    peek();
    dequeue();
    display();
}