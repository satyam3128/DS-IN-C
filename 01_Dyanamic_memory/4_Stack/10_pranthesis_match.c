#include <stdio.h>
#include <stdlib.h>
struct stack{
    int size;
    char *arr;
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
void push(struct stack *ptr , char value){
    if(isFull(ptr)){
        printf("Stack Overflow");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}
char pop(struct stack *ptr){
    if(isEmpty(ptr)){
        return -1;
    }
    char value = ptr->arr[ptr->top];
    ptr->top--;
    return value;
}
int parnthesismatch(char *exp){
    struct stack *sp;
    sp = (struct stack*)malloc(sizeof(struct stack));
    sp->top = -1;
    int len = 0;
    while (exp[len] != '\0') len++;
    sp->size = len;
    sp->arr = (char*)malloc(sp->size* sizeof(char));
    for(int i  = 0;exp[i] !='\0';i++){
        if(exp[i] == '('){
            push(sp,exp[i]);
        }
        else if(exp[i] ==')'){
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
    char *exp;
    printf("Enter the expression:");
    scanf("%s",exp);
    if(parnthesismatch(exp)){
        printf("Pranthesis matched");
    }
    else{
        printf("Not matched");
    }
    
    


}