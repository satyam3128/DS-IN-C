#include<stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;

};
struct node *HEAD;
void traverse(struct node *head){
    struct node *ptr = head;
    do{
        printf("Element: %d\n",ptr->data);
        ptr = ptr->next;
    }
    while( ptr != head);

}
int main(){
    struct node *first , *second ,*third ,*forth;
    first =(struct node*)malloc(sizeof(struct node));
    second =(struct node*)malloc(sizeof(struct node));
    third =(struct node*)malloc(sizeof(struct node));
    forth =(struct node*)malloc(sizeof(struct node));
    
    HEAD = first;

    // linking of node

    first->data = 1;
    first->next  = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next =  forth;

    forth->data = 4;
    forth->next = first;
    traverse(HEAD);



}