#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top=-1;

void push(int data){
    if(top>MAX-1){
        printf("Stack Overflow\n");
    }
    top++;
    stack[top] = data;
}

void pop(){
    if(top<=0){
        printf("Stack Underflow\n");
    }
    int element=stack[top];
    top--;
    printf("Popped element is %d\n",element);
}

void display(){
    if(top<=0){
        printf("Stack Underflow\n");
    }
    printf("Stack Elements:");
    for(int i = top; i>=0; i--){
        printf("\n%d",stack[i]);
    }
}

void peek(){
    if(top<=0){
        printf("Stack Underflow\n");
    }
    int element=stack[top];
    printf("Top element is %d\n",element);
}

int main(){
    push(10);
    push(20);
    push(60);
    push(100);
    pop();
    peek();
    display();
}