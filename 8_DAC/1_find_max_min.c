#include <stdio.h>
struct max_min{
    int max ;
    int min;
};
struct max_min find_max_min(int a[], int i, int j) {
    struct max_min result; 
    
    if (i == j) {
        result.max = result.min = a[i];
        return result; 
    }
    else if(i==j-1){
        if(a[i] >a[j]){
            result.max = a[i];
            result.min = a[j];
        }
        else{
            result.max = a[j];
            result.min = a[i];
        }
        return result;
    }
    else{
        int mid = (i+j)/2;
        struct max_min result1 , result2;
        
        result1 = find_max_min(a,i,mid);
        result2 = find_max_min(a,mid+1,j);

        if(result1.max > result2.max){
            result.max = result1.max;
        }
        else{
            result.max = result2.max;
        }
        if(result1.min < result2.min){
            result.min = result1.min;
        }
        else{
            result.min = result2.min;
        }

    }

    return result;
    
    
}
int main(){

    struct max_min ans;
    int arr[10] ={2,4,6,11,89,90,122,-55,90,8};
    ans = find_max_min(arr,0,9);
    printf("%d",ans.max);
    printf("\n");
    printf("%d",ans.min);

    return 0;
}