#include<stdio.h>
#include<string.h>
#include <stdlib.h>
struct stack{
    int size;
    int top;
    char *arr;
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
        printf("Stack Overfloaw");
    }
    ptr->top++;
    ptr->arr[ptr->top] = value;
}
char pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack UnderFlow");
            return -1;
        
    }
    char value = ptr->arr[ptr->top];
    ptr->top--;
    return value;
}
int match(char a, char b){
    if(a == '(' && b==')')return 1;
    if(a == '{' && b=='}') return 1;
    if( a == '[' && b==']') return 1;
    return 0;
}

int Multiparenthesis(char *exp){
    char popped_ch;
    struct stack *s;
    s = (struct stack*)malloc(sizeof(struct stack));
    s->top = -1;
    s->size = 100;
    s->arr = (char*)malloc(s->size*sizeof(char));
    for(int i = 0;exp[i] != '\0';i++){
        if(exp[i] == '(' || exp[i] =='{' || exp[i] =='['){
            push(s,exp[i]);
        }
        else if(exp[i] == ')' || exp[i] =='}' || exp[i] ==']'){
            if(isEmpty(s)){
                free(s->arr);
                free(s);
                return 0;
            }
            popped_ch = pop(s);
            if(!match(popped_ch,exp[i])){
                free(s->arr);
                free(s);
                return 0;
            }
        }

    }
    int result = isEmpty(s);
        free(s->arr);
        free(s);
        return result;


}
int main(){
    char exp[100];
    printf("Enter the Experssion:");
    scanf("%s",exp);
    if(Multiparenthesis(exp)){
        printf("Pranthesis Matched");

    }
    else{
        printf("pranthesis Not matched");
    }
    return 0;

}