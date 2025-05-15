#include <stdio.h>
#include <stdlib.h>
struct stack{
    int data;
    struct stack *next;
};

int isEmpty(struct stack *ptr){
    if(ptr==NULL){
        return 1;
    }
    return 0;
}

int isFull(struct stack *ptr){
    struct stack *n = (struct stack*)malloc(sizeof(struct stack));
    if(n == NULL){
        return 1;
    }
    return 0;
}

struct stack *push(struct stack *ptr , int value){
    if(isFull(ptr)){
        printf("Stack Overflow");

    }
    struct stack *newNode = (struct stack*)malloc(sizeof(struct stack));
    newNode->data = value;
    newNode->next = ptr;
    ptr = newNode;
    return ptr;
}

int pop(struct stack **top) {
    if (isEmpty(*top)) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct stack *temp = *top;
    int x = temp->data;
    *top = (*top)->next;
    free(temp);
    return x;
}
void traverse(struct stack *ptr){
    while(ptr!= NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main(){
    struct stack *top = NULL;
    top = push(top,10);
    top = push(top,20);
    
    top = push(top , 90);
    traverse(top);
    int element = pop(top);
    printf("pop:%d",element);
    traverse(top);
    return 0;
}
