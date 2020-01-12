#include <stdio.h>
#include <stdlib.h>
#define maxqueue 25
#define TRUE 1
#define FALSE 0
typedef int QueueEntryType;
typedef struct queue{
    int front;
    int rear;
    int count;
    QueueEntryType entry[maxqueue];
}queue;
void CreateQueue(queue *q)
{
    q->count=0;
    q->front= 0;
    q->rear= -1;
}
int IsQueueEmpty(queue *q)
{
    if(q->count==0)
    {
        return(TRUE);
    }
    else
    {
        return(FALSE);
    }
}
int IsQueueFull(queue *q)
{
    if(q->rear==maxqueue-1)
    {
        return(TRUE);
    }
    else
        {
            return(FALSE);
        }
}
void Remove(QueueEntryType *x,queue *q)
{
    if(IsQueueEmpty(q))
    {
        printf("Queue is empty\n ");
    }
    else
    {
        //printf("Removed element is:%d\n",*x=q->entry[q->front]);
        *x = q->entry[q->front];
        q->front++;
        q->count--;
    }

}
void Insert(QueueEntryType x,queue *q)
{
    if(IsQueueFull(q))
    {
        printf("Queue is full\n");
    }
    else
    {
        q->rear++;
        q->entry[q->rear]=x;
        q->count++;
    }
}
int Queuesize(queue *q)
{
    return (q->count);
}
void Display(queue *q){
    int i;
    for(i=q->front;i<=q->rear;i++){
        printf("%d ",q->entry[i]);
    }
    printf("\n\n");
}
void InsertionSort(queue *q){
    int arr[100];
    int num=0;
    for(int a=0; a<q->count; a++){
        arr[a] = q->entry[q->front+a];
        num++;
    }
    int j,key;
    for(int i=1; i<num; i++){
        key = arr[i];
        j = i - 1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
    for(int i=0; i<num; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void main()
{
    queue q;int ele;int y,count;
    CreateQueue(&q);
    printf("Queue is created\n");
    while(1){
    printf("1.Insert\n");
    printf("2.Remove\n");
    printf("3.Count\n");
    printf("4.Insertion Sort\n");
    printf("5.exit\n\n");
    printf("Enter your choice:");
    scanf("%d",&y);
    switch(y)
    {
        case 1:printf("Enter element to insert:");
               scanf("%d",&ele);
               Insert(ele,&q);
               Display(&q);
               break;
        case 2:Remove(&ele,&q);
                printf("Removed element is: %d\n",ele);
                Display(&q);
               break;
        case 3:count=Queuesize(&q);
               printf("Queue size is=%d\n",count);
               break;
        case 4:
            printf("\nSorted Queue\n");
            InsertionSort(&q);
            break;
        case 5:exit(1);
               break;
        default:printf("Enter incorrect choice\n");
    }
    }
}
