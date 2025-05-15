#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};

// declaration of global pointer to pointing the first node

struct node *START;

// traverse of LINKED LIST
void traverse(struct node *temp){
    while(temp != NULL){
        printf("Element: %d\n",temp->data);
        temp = temp->next;
    }
}
//  insertion of node at the BEGNING
struct node *INSERT_AT_BEGNING(struct node *temp , int newdata){
    struct node *ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = newdata;
    ptr->next =temp;
    
    return ptr;

}
int main(){

    struct node *first ,*second , *third;

    first = (struct node*)malloc(sizeof(struct node));
    second  = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    START = first;
    first->data = 1;
    first->next = second;

    second ->data = 2;
    second ->next = third;

    third->data = 3;
    third->next =NULL;

    traverse(START);
    printf("\n");

   START =  INSERT_AT_BEGNING(START,787);

   traverse(START);
    
}