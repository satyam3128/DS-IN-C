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
struct node *INSERT_AT_index(struct node *temp , int newdata , int index){
    struct node *ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = newdata;
    struct node *p;
    p = temp;

    int i = 0 ;
    while(i != index-1){
        p= p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;

    return temp;
}

int main(){

    struct node *first ,*second , *third , *forth;

    first = (struct node*)malloc(sizeof(struct node));
    second  = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));
    forth = (struct node*)malloc(sizeof(struct node));

    START = first;
    first->data = 1;
    first->next = second;

    second ->data = 2;
    second ->next = third;

    third->data = 3;
    third->next =forth;

    forth->data = 4;
    forth->next = NULL;

    traverse(START);
    printf("\n");

printf("Enter the new data:");
int n , index ;
scanf("%d",&n);
printf("Enter index :");
scanf("%d",&index);
   START = INSERT_AT_index(START , n , index);

   traverse(START);
    
}