#include<stdio.h>
#include <stdlib.h>
int main(){
    int *ptr;
    int n ; 
    printf("Enter Size of Array:");
    scanf("%d",&n);
    // Dynamically memory is Created fo0r array:
    ptr = (int*)malloc(n*sizeof(int));
    for(int i = 0 ;i<n ;i++){
        printf("Enter %d Element of Array:",i+1);
        scanf("%d",&ptr[i]);
    }
    // Array printed 
    for(int j = 0 ;j<n ;j++){
        printf("%d ",ptr[j]);
    }

}