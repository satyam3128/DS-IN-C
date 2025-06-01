#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    struct node *left;
    int data;
    struct node *right;

};
struct node *creating_nodes(int value){
    struct node *ptr;
    ptr  = (struct node*)malloc(sizeof(struct node));
    ptr ->data = value ;
    ptr->left  = NULL;
    ptr->right = NULL;
    return ptr;
}

int isBst(struct node *root , struct node *min , struct node *max){
    if(root == NULL) return 1;
    if(min != NULL && root->data <= min->data) return 0;
    if(max != NULL && root ->data >= max->data ) return 0;

    int leftvalid = isBst(root->left , min , root);
    int rightvalid = isBst(root->right , root , max);
    
    
    return leftvalid  && rightvalid;
}
struct node *ROOT = NULL;
int main(){

    struct node *first ,*second ,*third ,*forth , *fifth ,*sixth;
    first = creating_nodes(5);
    second = creating_nodes(3);
    third = creating_nodes(8);
    forth = creating_nodes(1);
    fifth = creating_nodes(4);
    sixth = creating_nodes(7);

    ROOT = first;
    first ->left = second;
    first->right = third;
    second ->left = forth;
    second->right = fifth;
    third->left = sixth;

    if(isBst(ROOT,NULL , NULL)){
        printf("Valid BST");
    }
    else{
        printf("Invalid BST");
    }




    return 0;
    
}