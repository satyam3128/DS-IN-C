#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct stack{
    int top;
    char *arr;
    int size;

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
        printf("Stack Overflow , Can't be Push");
        return;
    }
    ptr->top++;
    ptr->arr[ptr->top] = value;
}
char pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow , Can't be pop");
        return -1;
    }
    char value  = ptr->arr[ptr->top];
    ptr->top--;
    return value;

}
int pranthesisCheck(char *exp){
    struct stack *sp = (struct stack*)malloc(sizeof(struct stack));
    sp->top = -1;
    sp->size = strlen(exp);
    sp->arr = (char*)malloc(sp->size * sizeof(char));
    
    for(int i = 0;exp[i] != '\0';i++){
        if(exp[i] == '('){
            push(sp,exp[i]);
            
        }
        else if(exp[i] == ')'){
            
            if(isEmpty(sp)){
                free(sp->arr);
                free(sp);
                return 0;
            }
                pop(sp);
            
        }
        
    }
    int result = isEmpty(sp);
        free(sp->arr);
        free(sp);
        return result;
}

int main(){
    char exp[100];
    printf("Enter the Experssion:");
    scanf("%s",exp);
    if(pranthesisCheck(exp)){
        printf("Pranthesis Matched");

    }
    else{
        printf("pranthesis Not matched");
    }



    return 0;

}