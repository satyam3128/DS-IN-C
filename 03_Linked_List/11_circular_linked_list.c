#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

// Global head pointer
struct node *head = NULL;

// Create a new node
struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// traversal of the circular linked list
void traverse() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }


    

    struct node* temp = head;
    printf("Circular List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Insert at beginning
void insertAtBeginning(int value) {
    struct node* newNode = createNode(value);

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    struct node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
    head = newNode;
}

// Insert at end
void insertAtEnd(int value) {
    struct node* newNode = createNode(value);

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    struct node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

// Insert at index
void insertAtIndex(int value, int index) {
    if (index == 0) {
        insertAtBeginning(value);
        return;
    }

    struct node* newNode = createNode(value);
    struct node* temp = head;
    int i = 0;

    while (i < index - 1 && temp->next != head) {
        temp = temp->next;
        i++;
    }

    if (i != index - 1) {
        printf("Index out of bounds\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete from beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    struct node* last = head;
    while (last->next != head)
        last = last->next;

    struct node* temp = head;
    head = head->next;
    last->next = head;
    free(temp);
}

// Delete from end
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    struct node* temp = head;
    struct node* prev = NULL;

    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    free(temp);
}

// Delete at index
void deleteAtIndex(int index) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (index == 0) {
        deleteFromBeginning();
        return;
    }

    struct node* temp = head;
    struct node* prev = NULL;
    int i = 0;

    while (i < index && temp->next != head) {
        prev = temp;
        temp = temp->next;
        i++;
    }

    if (i != index) {
        printf("Index out of bounds\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

int main() {
    // ✅ Step 1: Manually create 4 nodes
    struct node* n1 = createNode(10);
    struct node* n2 = createNode(20);
    struct node* n3 = createNode(30);
    struct node* n4 = createNode(40);

    // ✅ Step 2: Manually link them circularly
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n1;

    // ✅ Step 3: Set head
    head = n1;

    // ✅ Step 4: Initial Traversal
    printf("Initial List:\n");
    traverse();

    // ✅ Insert Operations
    insertAtBeginning(5);       // 5 10 20 30 40
    insertAtEnd(50);            // 5 10 20 30 40 50
    insertAtIndex(25, 3);       // 5 10 20 25 30 40 50

    printf("\nAfter Insertions:\n");
    traverse();

    // ✅ Delete Operations
    deleteFromBeginning();      // 10 20 25 30 40 50
    deleteFromEnd();            // 10 20 25 30 40
    deleteAtIndex(2);           // 10 20 30 40

    printf("\nAfter Deletions:\n");
    traverse();

    return 0;
}
