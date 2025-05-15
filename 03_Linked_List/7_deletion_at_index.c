#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};

struct node *START;

struct node *deleteAtINDEX(struct node *head , int index){
    struct node *p = head;
    struct node *q = head->next;
    for(int i = 0 ;i<index-1;i++){
        p= p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}


void traverse(struct node *ptr){
    while(ptr != NULL){
        printf("Element: %d\n",ptr->data);
        ptr = ptr->next;
    }
}
int main(){
   struct node *first , *second , *third;
   first = (struct node*)malloc(sizeof(struct node));
   second = (struct node*)malloc(sizeof(struct node));
   third = (struct node*)malloc(sizeof(struct node));


   START = first;

   first->data = 10;
   first->next = second;

   second->data = 20;
   second->next = third;

   third->data = 30;
   third->next = NULL;
    
   traverse(START);
   printf("\n\n");
   START = deleteAtINDEX(START,1);
   traverse(START);
   
   
}