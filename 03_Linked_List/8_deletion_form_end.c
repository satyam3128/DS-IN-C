#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *START;

struct node *deletefromEnd(struct node *head){
    // Case 1: List is empty
    if (head == NULL) {
        printf("List is already empty.\n");
        return NULL;
    }

    // Case 2: List has only one node
    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    // Case 3: General case (2 or more nodes)
    struct node *p = head;
    struct node *q = head->next;

    while (q->next != NULL) {
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