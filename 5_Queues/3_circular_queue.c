#include <stdio.h>
#include <stdlib.h>
struct circularqueue{
    int size;
    int f, r;
    int *arr;
};
int IsEmpty(struct circularqueue *ptr){
    if(ptr->f == ptr->r){
        return 1;
    }
    return 0;
}
int IsFull(struct circularqueue *ptr ){
    if((ptr->r + 1) % ptr->size == ptr->f ){
        return 1;
    }
    return 0;
}
void enqueue(struct circularqueue *ptr , int value){
    if(IsFull(ptr)){
        printf("queue overflow");
    }
    else{
        ptr->r = (ptr->r+1) % ptr->size;
        ptr->arr[ptr->r] = value;
    }
}
int dequeue(struct circularqueue *ptr){
    int value = -1;
    if(IsEmpty(ptr)){
        printf("Empty Queue");
    }
    else{
        (ptr->f) = (ptr->f+1)%ptr->size;
        value = ptr->arr[ptr->f];
    }
    return value;
}
void display(struct circularqueue *q){
    if(IsEmpty(q)){
        printf("Queue is empty\n");
    }
    else{
        printf("Queue:\n");
        int i = (q->f + 1) % q->size;
        while(i != (q->r + 1) % q->size){
            printf("%d ",q->arr[i]);
            i = (i+1)%q->size;
        }
        printf("\n");
    }
}
int main(){
    struct circularqueue *q;
    q = (struct circularqueue*)malloc(sizeof(struct circularqueue));
    q->size = 4;
    q->arr =  (int *)malloc(q->size * sizeof(int));
    q->f = q->r = 0;
    enqueue(q , 10);
    enqueue(q , 20);
    enqueue(q , 30);
    display(q);
    dequeue(q);
    display(q);
   


    free(q->arr);
    free(q);
}