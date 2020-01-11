#include<stdio.h>
int main(){
    int arr[100];
    printf("Enter the size of the array: ");
    int num,temp;
    scanf("%d",&num);
    printf("Enter the elements of the array: ");
    for(int i=0; i<num;i++){
        scanf("%d",&arr[i]);
    }
    printf("Original Array: \n");
    for(int i=0; i<num; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    for(int i=0; i<num; i++){
        for(int j=0; j<num-i-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("Sorted Array: \n");
    for(int i=0; i<num; i++){
        printf("%d ",arr[i]);
    }
}

