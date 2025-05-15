#include<stdlib.h>
#include <stdio.h>
struct node{
    struct node *left;
    int data;
    struct node *right;
};
struct node *Root = NULL;
struct node *creatnode(int value){
    struct node *node_creat;
    node_creat = (struct node*)malloc(sizeof(struct node));
    node_creat->data = value;
    node_creat->left = NULL;
    node_creat->right = NULL;

    return node_creat;
}
void Inorder(struct node *ptr){
    if(ptr == NULL){
        return;

    }
    
    Inorder(ptr->left);
    printf("%d ",ptr->data);
    Inorder(ptr->right);
}
int main(){
    struct node *first , *second ,*third , *forth , *fifth , *sixth , *seventh;
    first = creatnode(10);
    second = creatnode(20);
    third = creatnode(30);
    forth = creatnode(40);
    fifth = creatnode(50);
    sixth = creatnode(89);
    seventh = creatnode(99);
    Root = first;

    first->left = second;
    second->left = sixth;
    second ->right = seventh;
    first->right = third;
    third->right = forth;
    forth->left = fifth;

    Inorder(Root);



    

}