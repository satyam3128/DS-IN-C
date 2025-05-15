#include <stdio.h>
#include <stdlib.h>
struct stack{
    int size;
    int top;
    int *arr;

};
int main(){
    struct stack *s;
    
    s =(struct stack*)malloc(sizeof(struct stack));
    s->top = -1;
    int n ;
    printf("Enter Size of Stack:");
    scanf("%d",&n);
    s->size = n;
    
    s->arr =(int*)malloc(s->size * sizeof(int));
    
    free(s);
    free(s->arr);
}