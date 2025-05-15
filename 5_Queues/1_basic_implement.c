#include <stdio.h>
#include<stdlib.h>
struct queue {
    int size;
    int front ;
    int rear;
    int *arr;
};
int IsEmpty(struct queue *ptr){
    if(ptr->front ==-1){
        return 1;
    }
    return 0;
}
int IsFull(struct queue *ptr){
    if(ptr->rear == ptr->size -1){
        return 1;
    }
    return 0;
}
void enqueue(struct queue *ptr , int value){
    if(IsFull(ptr)){
        printf("Queue is Overflow");
        return;
    }
    if(IsEmpty(ptr)){
        ptr->front = ptr->rear = 0;
    }
    else{
    ptr->rear++;
    }
    ptr->arr[ptr->rear] = value;
}
int dequeue(struct queue *ptr){
    if(IsEmpty(ptr)){
        printf("Queue is Underflow");
        return -1;
    }
    if(ptr->front == ptr->rear){
        int value = ptr->arr[ptr->front];
        ptr->front = -1;
        ptr->rear = -1;
        return value;
    }
    int value = ptr->arr[ptr->front];
    ptr->front++;
    return value;

}
void display(struct queue *ptr){
    if(IsEmpty(ptr)){
        printf("Stack Empty");
        return;
    }
    for(int i  = ptr->front ; i<= ptr->rear ;i++){
        printf("%d ",ptr->arr[i]);
    }
    printf("\n");
}
int main(){
    struct queue *qu;
    qu = (struct queue*)malloc(sizeof(struct queue));
    int n ;
    printf("Enter the Size of Queue :");
    scanf("%d",&n);
    qu->size = n;
    qu->front =-1;
    qu ->rear = -1;

    qu->arr = (int *)malloc(qu->size * sizeof(int) );

    for(int i  = 0;i< qu->size ;i++){
        int num;
        printf("Enter the %d Element:",i+1);
        scanf("%d" ,&num);
        enqueue(qu , num);
    }
    display(qu);
    dequeue(qu);
    display(qu);
    
    return 0;
}