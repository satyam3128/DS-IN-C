#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};

struct node *START;

struct node *delete(struct node *head){
    struct node *ptr;
    ptr = head;
    head= head->next ;
    free(ptr);
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

   printf("\nElement before before deletion:\n");
   traverse(START);
   printf("\nElement before after deletion:\n");
   START =  delete(START);
   traverse(START);

   START = delete(START);

   printf("\nElement after 2nd deletion:\n");
   traverse(START);
}