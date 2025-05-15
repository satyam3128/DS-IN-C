#include <stdio.h>
#include <stdlib.h>
struct stack{
    int size;
    int *arr;
    int top;
};
int isEmpty(struct stack *ptr){
    if(ptr->top == -1){
        return 1;
    }
    return 0;
}
int isFull(struct stack *ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    return 0;

}
void push(struct stack *ptr , int value){
    if(isFull(ptr)){
        printf("Stack Overflow");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}
int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        return -1;
    }
    int value = ptr->arr[ptr->top];
    ptr->top--;
    return value;
}
void display(struct stack *ptr){
    for(int i = 0;i<=ptr->top ;i++){
        printf("%d ",ptr->arr[i]);
    }
}
int main(){
    struct stack *s;
    s = (struct stack*)malloc(sizeof(struct stack));
    s->top = -1;
    int n ;
    printf("Enter the size of Stack:");
    scanf("%d",&n);
    s->arr = (int*)malloc(n*sizeof(int));
    push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);
    push(s,5);
    push(s,6);
    push(s,7);
    pop(s);
    pop(s);
    pop(s);

    display(s);


}