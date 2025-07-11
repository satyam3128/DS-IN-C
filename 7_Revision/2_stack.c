#include <stdio.h>
#include <limits.h>
#define SIZE 100

int STACK[SIZE];
int top = -1;

// Function to push an element to the stack
void push(int x) {
    if (top == SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    STACK[top] = x;
}

// Function to pop the top element from the stack
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return INT_MIN;
    }
    int temp = STACK[top];
    top--;
    return temp;  // ✅ Corrected this line to return the popped element, not "top"
}

int main() {
    int n;
    printf("Enter size of stack for Push operation: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        printf("Enter number to push: ");
        scanf("%d", &x);
        push(x);
    }

    // Pop one element
    int poppedElement = pop();
    if (poppedElement != INT_MIN) {
        printf("Popped element: %d\n", poppedElement);
    }

    // Print stack after pop
    printf("Stack after pop:\n");
    for (int i = 0; i <= top; i++) {
        printf("%d ", STACK[i]);
    }

    return 0;
}
