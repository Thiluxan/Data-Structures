#include<stdio.h>
int main(){
    int num, arr[100],data,start,end,middle;
    printf("Enter the size of the sorted array: ");
    scanf("%d",&num);
    printf("Enter the elements of the sorted array: \n");
    for(int i=0; i<num; i++){
        scanf("%d",&arr[i]);
    }
    printf("\nEnter the data value to be searched: ");
    scanf("%d",&data);
    start = 0;
    end = num - 1;
    middle = (start + end) / 2;
    while(data !=arr[middle] && start<=end){
        if(data > arr[middle])
            start = middle + 1;
        else
            end = middle - 1;
        middle = (start + end) / 2;
    }
    if(data == arr[middle])
        printf("Data found at position: %d\n",middle+1);
    else
        printf("Data not found in the given sorted array\n");
}
