//sorting elements in a queue with the help of a stack
#include <stdio.h>
#include <stdlib.h>
#define MAXSTACK 25
#define maxqueue 25
typedef enum{FALSE,TRUE} Boolean;
typedef struct queue{
    int front;
    int rear;
    int count;
    int data[maxqueue];
}queue;
typedef struct stack{
    int top;
    int entry[MAXSTACK];
}stack;
void CreateQueue(queue *q)
{
    q->count=0;
    q->front= 0;
    q->rear= -1;
}
Boolean IsQueueEmpty(queue *q)
{
    return(q->count==0);
}
Boolean IsQueueFull(queue *q)
{
    return(q->rear==maxqueue-1);
}
void Remove(int *x,queue *q)
{
    if(IsQueueEmpty(q))
    {
        printf("Queue is empty\n ");
    }
    else
    {
        //printf("Removed element is:%d\n",*x=q->entry[q->front]);
        *x = q->data[q->front];
        q->front++;
        q->count--;
    }

}
void Insert(int x,queue *q)
{
    if(IsQueueFull(q))
    {
        printf("Queue is full\n");
    }
    else
    {
        q->rear++;
        q->data[q->rear]=x;
        q->count++;
    }
}
int Queuesize(queue *q)
{
    return (q->count);
}
void DisplayQueue(queue *q){
    int i;
    for(i=q->front;i<=q->rear;i++){
        printf("%d ",q->data[i]);
    }
    printf("\n\n");
}
void CreateStack(stack *s){
    s->top=-1;
}
Boolean IsStackEmpty(const stack *s){
    return (s->top==-1);
}
Boolean IsStackFull(const stack *s){
    return (s->top==MAXSTACK -1);
}
void Push(int data,stack *s){
    if(IsStackFull(s)){
        printf("stack is full \n");
    }
    else{
        s->entry[++s->top] = data;
    }
}
void Pop(int *data,stack *s){
    if(IsStackEmpty(s)){
        printf("stack is Empty \n");
    }
    else{
        *data = s->entry[s->top--];
    }
}
int top(stack *s){
    return s->entry[s->top];
}

void PrintStack(stack *s){
    for(int i=s->top; i>=0; i--){
        printf("%d ",s->entry[i]);
    }
    printf("\n");
}
void SortQueue(queue *q){
    stack s;
    CreateStack(&s);
    int temp,data;
    while(!IsQueueEmpty(q)){
        Remove(&temp,q);
        while(!IsStackEmpty(&s) && top(&s)<temp){
            Insert(top(&s),q);
            Pop(&data,&s);
        }
        Push(temp,&s);
    }
    while(!IsStackEmpty(&s)){
        Pop(&data,&s);
        Insert(data,q);
    }
}
void main()
{
    queue q;
    CreateQueue(&q);
    Insert(23,&q);
    Insert(45,&q);
    Insert(2,&q);
    Insert(3,&q);
    Insert(15,&q);
    printf("Original Queue:\n");
    DisplayQueue(&q);
    printf("\nSorted Queue: \n");
    SortQueue(&q);
    DisplayQueue(&q);
}
