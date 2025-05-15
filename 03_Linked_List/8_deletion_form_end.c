#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *START;

struct node *deletefromEnd(struct node *head){
    struct node *p,*q;
    p =head;
    q = head->next;

    while(q->next != NULL){
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
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
   struct node *first , *second , *third , *forth;
   first = (struct node*)malloc(sizeof(struct node));
   second = (struct node*)malloc(sizeof(struct node));
   third = (struct node*)malloc(sizeof(struct node));
   forth = (struct node*)malloc(sizeof(struct node));


   START = first;

   first->data = 10;
   first->next = second;

   second->data = 20;
   second->next = third;

   third->data = 45;
   third->next = forth;

   forth->data = 87;
   forth->next =NULL;



   printf("Element before Deletion: \n");
   traverse(START);
   START = deletefromEnd(START);
   printf("\n Element After Deletion:\n");
   traverse(START);

   
}