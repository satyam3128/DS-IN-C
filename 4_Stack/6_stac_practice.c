#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
struct stack{
    int size ;
    int top;
    int *arr;
};
// Check Stack Empty or not 
int isEmpty(struct stack *ptr){
    if(ptr->top == -1){
        return 1;
    }
    return 0;
}
// Check Stack is Full or not 
int isFull(struct stack *ptr){
    if(ptr->top == ptr->size -1){
        return 1;
    }
    return 0;
}
// Push
void push(struct stack *ptr,int value){
    if(!isFull(ptr)){
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
    else{
        printf("Can Not Push");
    }

}
// Pop 
int pop(struct stack *ptr){
    if(!isEmpty(ptr)){
        int temp = ptr->arr[ptr->top];
        ptr->top--;
        printf("\nPopped Element is %d\n",temp);
        return temp;
    }
    printf("\nStack is Empty , Can't POP\n");
    return -1;
} 
// peek 
int peek(struct stack * ptr){
    if(isEmpty(ptr)){
        printf("\nStack is Empty, not any element Found\n");
        return -1;
    }
    return ptr->arr[ptr->top];
}
// Display
void display(struct stack *ptr){
    for(int i = 0;i<=ptr->top ;i++){
        printf("%d ",ptr->arr[i]);
    }
}

int main(){
    struct stack *s;
    s = (struct stack*)malloc(sizeof(struct stack));
    int siz ;
    printf("Enter the Size of Stack:");
    scanf("%d",&siz);
    s->size = siz;
    s->top = -1;
    s->arr =(int *)malloc(s->size * sizeof(int));
    printf("Stack is Created\n");
    push(s,10);
    push(s,20);
    push(s,30);
    display(s);
    pop(s);
    printf("\nPeek :%d",peek(s));
    free(s->arr);
    free(s);
    return 0;
}