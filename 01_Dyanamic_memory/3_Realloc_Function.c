#include <stdio.h>
#include <stdlib.h>
int main(){
    // use of Malloc
    int *ptr;
    int n ; 
    printf("Enter size of Array:");
    scanf("%d",&n);
    ptr = (int*)malloc(n*(sizeof(int)));

    //input array element

    for(int i= 0 ;i<n ;i++){
        printf("Enter %d element :",i+1);
        scanf("%d",&ptr[i]);
    }
    // output array element 
    for(int j = 0 ;j<n ;j++){
        printf("%d ",ptr[j]);
    }
}