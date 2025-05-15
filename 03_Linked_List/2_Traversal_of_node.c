#include<stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;

};
struct node *HEAD;

void LinkedlistTraverse(struct node *ptr){
    while(ptr!=NULL){
        printf("Element:%d \n",ptr ->data);
        ptr = ptr->next;
    }
}
int main(){
    //allocation of node in the heap;
    struct node *first, *second , *third;
    first = (struct node*)malloc(sizeof(struct node));  
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    // linking of nodes
    first ->data = 7;
    first ->next = second;

    second->data = 87;
    second ->next = third;

    third ->data = 98;
    third ->next = NULL;

    HEAD = first;

    // function call
    LinkedlistTraverse(HEAD);

    return 0;
}