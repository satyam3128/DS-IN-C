#include<stdio.h>
#include <stdlib.h>
struct node{
    struct node *left;
    int data;
    struct node *right;


};
struct node *Root = NULL;

struct node *createnode(int value){
    struct node *create_node;

    create_node = (struct node*)malloc(sizeof(struct node)) ;
    create_node->left = NULL;
    create_node->data = value;
    create_node->right = NULL;

    return create_node;
}
void Inorder(struct node *ptr){
    if(ptr == NULL) return ;
    Inorder(ptr->left);
    printf("%d ",ptr->data);
    Inorder(ptr->right);
}
int main(){
    struct node *first ,*second,*third , *forth , *fifth;
    first = createnode(5);
    second =createnode(3);
    third = createnode(6);
    forth = createnode(1);
    fifth = createnode(4);

    // node link

    Root = first;
    first ->left = second;
    first ->right = third;
    second->left = forth;
    second->right = fifth;

    Inorder(Root);



    return 0;
}