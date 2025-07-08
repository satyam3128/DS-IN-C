#include <stdio.h>
#include <stdlib.h>

// Doubly linked list node
struct node {
    int data;
    struct node *prev;
    struct node *next;
};

// Global head and tail pointers
struct node *head = NULL;
struct node *tail = NULL;

// Create a new node
struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertAtBeginning(int value) {
    struct node *newNode = createNode(value);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Insert at end
void insertAtEnd(int value) {
    struct node *newNode = createNode(value);
    if (tail == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Insert at specific index (0-based)
void insertAtIndex(int value, int index) {
    if (index == 0) {
        insertAtBeginning(value);
        return;
    }

    struct node *newNode = createNode(value);
    struct node *temp = head;
    int i = 0;

    while (temp != NULL && i < index - 1) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Index out of bounds!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;
    else
        tail = newNode; // insert at last

    temp->next = newNode;
}

// Delete from beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;
    else
        tail = NULL; // list became empty

    free(temp);
}

// Delete from end
void deleteFromEnd() {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = tail;
    tail = tail->prev;

    if (tail != NULL)
        tail->next = NULL;
    else
        head = NULL;

    free(temp);
}

// Delete at specific index (0-based)
void deleteAtIndex(int index) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (index == 0) {
        deleteFromBeginning();
        return;
    }

    struct node *temp = head;
    int i = 0;

    while (temp != NULL && i < index) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Index out of bounds!\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    else
        tail = temp->prev; // deleting last node

    free(temp);
}

// Traverse forward
void traverseForward() {
    struct node *temp = head;
    printf("Forward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Traverse backward
void traverseBackward() {
    struct node *temp = tail;
    printf("Backward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    // Initial insertions
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);
    insertAtEnd(50);

    printf("Initial List:\n");
    traverseForward();
    traverseBackward();

    insertAtBeginning(5);
    insertAtIndex(25, 3); // index 3 (after 20)

    printf("\nAfter Insertions:\n");
    traverseForward();
    traverseBackward();

    deleteFromBeginning();
    deleteFromEnd();
    deleteAtIndex(2); // delete node at index 2

    printf("\nAfter Deletions:\n");
    traverseForward();
    traverseBackward();

    return 0;
}
