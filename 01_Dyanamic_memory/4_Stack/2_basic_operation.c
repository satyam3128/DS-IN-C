#include <stdio.h>
#include <stdlib.h>
struct stack {
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr) {
    return (ptr->top == -1);
}

int isFull(struct stack *ptr) {
    return (ptr->top == ptr->size - 1);
}

void display(struct stack *ptr) {
    for (int i = 0; i <= ptr->top; i++) { 
        printf("%d ", ptr->arr[i]);
    }
}

int main() {
    struct stack *s = (struct stack *)malloc(sizeof(struct stack)); // Allocate memory for the stack structure
    printf("Enter the size: ");
    scanf("%d", &s->size);

    s->top = -1; // Initialize top
    s->arr = (int *)malloc(s->size * sizeof(int)); // Allocate memory for stack array

    int n;
    for (int i = 0; i < s->size; i++) {
        if (!isFull(s)) {
            printf("Enter the Element: ");
            scanf("%d", &n);
            s->arr[++(s->top)] = n; // Push element and increment top
        } else {
            printf("Stack is Full. Cannot push more elements.\n");
            break;
        }
    }

    if (isEmpty(s)) {
        printf("\nStack is Empty\n");
    } else {
        printf("\nStack is not empty\n");
    }

    if (isFull(s)) {
        printf("\nStack is Full\n");
    } else {
        printf("\nStack is not Full\n");
    }

    display(s);

    free(s->arr); // Free allocated memory
    free(s);      // Free the stack structure

    return 0;
}