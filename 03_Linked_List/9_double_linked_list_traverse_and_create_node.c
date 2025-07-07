#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct node {
    int data;
    struct node *prev;
    struct node *next;
};

// Function to create a new node
struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Forward traversal
void traverseForward(struct node* head) {
    printf("Forward Traversal:\n");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Backward traversal
void traverseBackward(struct node* tail) {
    printf("Backward Traversal:\n");
    while (tail != NULL) {
        printf("%d ", tail->data);
        tail = tail->prev;
    }
    printf("\n");
}

int main() {
    // Create 5 nodes manually
    struct node *n1 = createNode(10);
    struct node *n2 = createNode(20);
    struct node *n3 = createNode(30);
    struct node *n4 = createNode(40);
    struct node *n5 = createNode(50);

    // Connect nodes
    n1->next = n2;

    n2->prev = n1;
    n2->next = n3;

    n3->prev = n2;
    n3->next = n4;

    n4->prev = n3;
    n4->next = n5;

    n5->prev = n4;

    // Head points to first, tail to last
    struct node* head = n1;
    struct node* tail = n5;

    // Traversals
    traverseForward(head);
    traverseBackward(tail);

    return 0;
}
