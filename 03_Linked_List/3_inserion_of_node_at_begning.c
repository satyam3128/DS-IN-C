#include<stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};



void traverse(struct node *traverse){
    while(traverse != NULL){
        printf("ELEMENT: %d \n",traverse->data);
        traverse = traverse->next;
    }
}
struct node *insert_at_begning(struct node *head , int newdata){
    struct node *ptr;
    ptr = (struct node*)malloc(sizeof(struct node));

    ptr->data = newdata;
    ptr->next = head;

    return ptr;
}
// free the each node
void free_list(struct node *head) {
    struct node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(){
    
    struct node *head,*second ,*third;

   

    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    // linking of node

   

    head->data = 55;
    head->next = second;

    second->data = 9;
    second->next = third;

    third ->data = 89;
    third ->next =NULL;

    traverse(head);

    head = insert_at_begning(head,69);
    printf("\n");

    traverse(head);

    free_list(head);



}