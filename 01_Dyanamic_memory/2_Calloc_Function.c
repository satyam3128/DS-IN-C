#include <stdio.h>
#include <stdlib.h>
int main(){
    int *ptr;
    int n ; 
    printf("Enter Size of Memory:");
    scanf("%d",&n);
    // use of calloc
    ptr = (int*)calloc(n,sizeof(int));
    for(int i = 0 ;i <n ;i++){
        printf("Enter %d element of Array:",i+1);
        scanf("%d",&ptr[i]);
    }
    for(int j = 0 ; j <n ;j++){
        printf("%d ",ptr[j]);
    }

}