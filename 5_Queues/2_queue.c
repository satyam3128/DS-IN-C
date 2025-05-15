#include <stdio.h>
#include<stdlib.h>
struct queue{
    int front;
    int rear;
    int *arr;
    int size ;

};
int isEmpty(struct queue *ptr){
    if(ptr->front == -1){
        return 1;
    }
    return 0;
}
int isFull(struct queue *ptr){
    if(ptr->rear == ptr->size -1){
        return 1;
    }
    return 0;
}
void enqueue(struct queue *ptr ,int value){
    if(isFull(ptr)){
        printf("Queue overFlow");
    }
    if(isEmpty(ptr)){
        ptr->front++;
        ptr->rear++;
        ptr->arr[ptr->rear] =  value;
        
    }
    else{
        ptr->rear++;
        ptr->arr[ptr->rear] = value;

    }
}
int dequeue(struct queue *ptr){
    if(isEmpty(ptr)){
        printf("queue is UnderFlow");
        return -1;
        
    }
    if(ptr->front == ptr->rear){
        int value = ptr->arr[ptr->front];
        ptr->front =-1;
        ptr->rear = -1;
        return value;

    }
    int value = ptr->arr[ptr->front];
    ptr->front++;
    return value;
}
void display(struct queue *ptr){
    
    for(int i = ptr->front;i<=ptr->rear ;i++){
        printf("%d ",ptr->arr[i]);
    }
    printf("\n");
}
int main(){
    struct queue *qu;
    qu = (struct queue*)malloc(sizeof(struct queue));
    int n;
    printf("Enter the Size of Queue:");
    scanf("%d",&n);
    qu->size =n;
    qu->rear = -1;
    qu->front = -1;
    qu->arr =(int*)malloc(qu->size * sizeof(int));
    for(int i = 0;i<qu->size ;i++){
        int num;
        printf("Enter the %d Element Of Queue:",i+1);
        scanf("%d",&num);
        enqueue(qu,num);
    }
    
    display(qu);

    dequeue(qu);
    dequeue(qu);

    display(qu);
    free(qu->arr);
    free(qu);
}