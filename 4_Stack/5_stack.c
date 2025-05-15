#include <stdio.h>
#include <stdlib.h>

// Stack structure
struct stack {
    int size;
    int top;
    int *arr;
};

// Check if stack is empty
int isEmpty(struct stack *ptr) {
    return ptr->top == -1;
}

// Check if stack is full
int isFull(struct stack *ptr) {
    return ptr->top == ptr->size - 1;
}

// Push operation
int push(struct stack *ptr, int value) {
    if (!isFull(ptr)) {
        ptr->top++;
        ptr->arr[ptr->top] = value;
        return 0;
    }
    printf("Stack Overflow! Cannot push %d into the stack.\n", value);
    return 1;
}
int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Can't be pop");
        return 0;
    }
    int temp = ptr->arr[ptr->top];
    ptr->top--;
    return temp;
}

int main() {
    struct stack *sp;
    sp = (struct stack*)malloc(sizeof(struct stack));
    sp->top = -1;

    int n;
    printf("Enter the Size of Stack: ");
    scanf("%d", &n);
    sp->size = n;
    sp->arr = (int*)malloc(sp->size * sizeof(int));
    // Check stack status
    

    for(int i = 0;i<n ;i++){
        int num;
        printf("Enter the Element of Stack:");
        scanf("%d",&num);
        push(sp,num);
    }

    pop(sp);
    pop(sp);

    free(sp->arr);
    free(sp);

    return 0;
}
