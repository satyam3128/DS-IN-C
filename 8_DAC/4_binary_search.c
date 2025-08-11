#include<stdio.h>
int DAC_Bsearch(int a[], int start , int end , int x){
    int mid;
    if(start == end){
        if(a[start] == x){
            return start;
        }
        else return -1;
    }
    else {
        mid = (start + end)/2;
        if(a[mid] == x){
            return mid;
        }
        else if(x<a[mid]){
            return DAC_Bsearch(a,start,mid,x);
        }
        else{
            return DAC_Bsearch(a,mid+1,end ,x);
        }
    
    }
    return -1;
}
int main(){

    int arr[] = {1,2,311,4,5};
    printf("%d",DAC_Bsearch(arr,0,4,311));

    return 0;
}