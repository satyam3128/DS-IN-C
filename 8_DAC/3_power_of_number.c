#include<stdio.h>
int DAC(int a , int n){
    
    if(n == 1){
        return a;
    }
    int temp = DAC(a,n/2);
    if(n%2== 0){
        
        return  temp * temp;
    }
    else{
        return temp * temp *a;
    }
    return -1;
}
int main(){
    int a,n ;
    printf("Enter Base:");
    scanf("%d",&a);
    printf("Enter the Power:");
    scanf("%d",&n);
    printf("\nANS:%d",DAC(a,n));
    
    return 0;
}