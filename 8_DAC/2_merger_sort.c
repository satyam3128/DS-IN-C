#include<stdio.h>
void merge(int a[], int p ,  int q , int r){
    int l1 = q-p+1;
    int l2 = r-q;

    int left[l1] , right[l2];
    int i , j ;
    for(i = 0 ;i<l1 ;i++){
        left[i] = a[p+i];
    }

    for(int j = 0;j<l2 ;j++){
        right[j] = a[q+1+j];
    }
    i = j = 0;
    int k = p;
    while(i <l1 && j <l2 ){
        if(left[i] < right[j]){
            a[k] = left[i];
            i++;
        }
        else{
            a[k] = right[j];
            j++;
        }
        k++;
    }
    while(i<l1){
        a[k++] = left[i++];
    }
    while(j<l2){
        a[k++] = right[j++];
    }
}
void megersort(int a[] , int  p ,int r){
    if(p<r){
       int  q = (p+r)/2;
       megersort(a,p,q);
       megersort(a,q+1,r);
       merge(a,p,q,r);
    }
}
int main(){
    int arr[] = {10,200,3,90,9,122};
    megersort(arr,0,5);

    for(int i = 0;i<6 ;i++){
        printf("%d ",arr[i]);
    }

}