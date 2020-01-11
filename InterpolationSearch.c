#include<stdio.h>
int main(){
    int num, arr[100],data,high,low,pos,position;
    printf("Enter the size of the sorted array: ");
    scanf("%d",&num);
    printf("Enter the elements of the sorted array: \n");
    for(int i=0; i<num; i++){
        scanf("%d",&arr[i]);
    }
    printf("\nEnter the data value to be searched: ");
    scanf("%d",&data);
    low = 0;
    high = num - 1;
    while(low<=high && data >= arr[low] && data <= arr[high]){
        if(low == high){
            if(arr[low] == data)
                position = low;
        }
        else{
            pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (data - arr[low]));
            if(arr[pos] == data)
                position = pos;
            if(arr[pos]<data)
                low = pos + 1;
            else
                high = pos - 1;
        }
    }
    if(position > -1)
        printf("Data value found at position: %d\n",position+1);
    else
        printf("Data value not found");
}

