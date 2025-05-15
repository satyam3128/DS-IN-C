#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>
struct myarray{
    int total_size;
    int used_size;
    int *ptr;
};
void create_array(struct myarray *a , int tsize , int usize ){
    a->total_size = tsize;
    a->used_size = usize;
    a->ptr = (int*)malloc(tsize * sizeof(int));
}
void display(struct myarray *a){
    for(int i  = 0;i< (a->used_size) ;i++){
        printf("%d ",(a->ptr)[i]);
    }

}
void push(struct myarray *a){
    int n ;
    for(int i  = 0;i<a->used_size ; i++){
        printf("Enter the %d Element:",i);
        scanf("%d",&n);
        a->ptr[i] = n;
    }
}

int main(){
    struct myarray marks;
    int totalsize , usedsized;
    printf("Enter the total size of Array:");
    scanf("%d",&totalsize);
    printf("Enter the used size of Array:");
    scanf("%d",&usedsized);

    create_array(&marks , totalsize , usedsized);
    push(&marks);
    display(&marks);

}