#include <stdio.h>
int a[100],b[100];

void merging(int low, int mid, int high) {
   int i,j,k;

   for(i = low, j = mid + 1, k = low; i <= mid && j <= high; k++) {
      if(a[i] <= a[j])
         b[k] = a[i++];
      else
         b[k] = a[j++];
   }

   while(i <= mid)
      b[k++] = a[i++];

   while(j <= high)
      b[k++] = a[j++];

   for(k = low; k <= high; k++)
      a[k] = b[k];
}

void sort(int low, int high) {
   int mid;

   if(low < high) {
      mid = (low + high) / 2;
      sort(low, mid);
      sort(mid+1, high);
      merging(low, mid, high);
   } else {
      return;
   }
}

int main() {
   int i,num;
    printf("Enter no.of elements in the array: \n");
    scanf("%d",&num);
    printf("Enter the data of the array: \n");
    for(i=0; i<num; i++){
        scanf("%d",&a[i]);
    }
   sort(0, num-1);

   printf("\nList after sorting\n");

   for(i = 0; i <num; i++)
      printf("%d ", a[i]);
}

