#include<stdio.h>
int main(){
    int row, column;
    printf("Enter Row:");
    scanf("%d",&row);
    printf("Enter Colum:");
    scanf("%d" ,&column);
    for(int i = 1 ;i<=row ;i++){
        for(int j = 1 ;j<=2*column-1 ;j++){
            if(i+j == row +1 || j-i == row -1 ){
                printf(" * ");
            }
            else{
                printf("   ");
            }
        }
        printf("\n");
    }

    for(int i =  1 ;i<=2*row-1 ; i++){
        for(int j = 1 ;j<=2*column-1 ;j++){
            if(i==1 || j==1 ||i==2*row-1 || j==2*column-1 ){
                printf(" * ");
            }
            else if(i>=row ){
                if( j == column-1/2 + 1 || j == column-1/2 -1 || (i == row && j == column )){
                    printf(" * ");
                }
                else{
                    printf("   ");
                }
            }
            
            else{
                printf("   ");
            }

        }
        printf("\n");
    }


    return 0;
}