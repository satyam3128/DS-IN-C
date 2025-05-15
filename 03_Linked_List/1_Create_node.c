#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;

};
int main(){
    // creating of node in the heap
    struct Node *first,*second , *third;
    first = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // linking of nodes;
    first->data = 7;
    first->next = second;

    second->data = 13;
    second ->next = third;

    third ->data = 55;
    third->next =NULL;
    

    
}