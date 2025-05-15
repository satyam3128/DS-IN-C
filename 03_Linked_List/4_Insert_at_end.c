#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *HEAD;

void traverse(struct node *temp){
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
struct node *Insert_at_end(struct node *temp,int newdata){
    struct node *ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = newdata;
    struct node *p = temp;
   
    while(p->next!=NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;

    return temp; 
}
int main(){


    struct node *first ,*second ,*third;

    

    first = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    HEAD = first;

    first->data =89;
    first->next = second;

    second->data =90;
    second->next = third;

    third->data = 91;
    third->next = NULL;

    traverse(HEAD);

    printf("\n\n\n\n");

  HEAD = Insert_at_end(HEAD,100);

    traverse(HEAD);
    


}
