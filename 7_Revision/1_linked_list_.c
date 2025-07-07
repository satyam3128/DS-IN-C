#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *START = NULL;

struct node *create(int value){
    struct node *ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = value;
    ptr->next = NULL;

    return ptr;
}
void traversal(struct node *ptr){
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}
int count_nodes(struct node *ptr){
    
    int count = 0;
    while(ptr != NULL){
        count++;
        ptr = ptr->next;
    }
    return count;
}


int main(){
    struct node *first = create(10);
    struct node *second = create(20);
    struct node *third = create(30);

    START = first;
    first->next =second;
    second->next = third;
    traversal(START);
    printf("\nNO. of Nodes:%d",count_nodes(START));

    return 0;
}