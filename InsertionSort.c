#include<stdio.h>
int main(){
    int arr[100];
    printf("Enter the size of the array: ");
    int num,key,j;
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
    for(int i=1; i<num; i++){
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
    printf("Sorted Array: \n");
    for(int i=0; i<num; i++){
        printf("%d ",arr[i]);
    }
}

