#include<stdio.h>
#include <stdlib.h>
#define size 100
int stack[size];
int top = -1;
int push(int x){
    if(top == size -1){
        printf("Stack overflow");
        return 0 ;

    }
    stack[++top] = x;
    return 0 ;
}

int main(){
    push(5);
    push(88);
    printf("%d",stack[1]);


}