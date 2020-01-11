//implement a queue using two stacks
#include<stdio.h>
#include<stdlib.h>
#define MAXSTACK 100
typedef enum{FALSE,TRUE} Boolean;
typedef struct stack{
    int top;
    int entry[MAXSTACK];
}stack;
typedef struct queue{
    stack s1,s2;
}queue;
void CreateStack(stack *s){
    s->top=-1;
}
void CreateQueue(queue *q){
    CreateStack(&q->s1);
    CreateStack(&q->s2);
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

void Print(stack *s){
    for(int i=s->top; i>=0; i--){
        printf("%d ",s->entry[i]);
    }
    printf("\n");
}
void PrintQueue(queue *q){
    Print(&q->s1);
}
void enqueue(queue *q, int input){
    int data;
    while(!IsStackEmpty(&q->s1)){
        Pop(&data,&q->s1);
        Push(data,&q->s2);
    }
    Push(input,&q->s1);
    while(!IsStackEmpty(&q->s2)){
        Pop(&data,&q->s2);
        Push(data,&q->s1);
    }

}
void dequeue(queue *q, int *output){
    int data;
    if(IsStackEmpty(&q->s1)){
        printf("Queue is Empty\n");
    }
    else{
        *output = top(&q->s1);
        Pop(&data,&q->s1);
    }
}
int main(){
    int ele,y;
    queue q;
    CreateQueue(&q);
    while(1){
    printf("1.Insert\n");
    printf("2.Remove\n");
    printf("3.exit\n\n");
    printf("Enter your choice:");
    scanf("%d",&y);
    switch(y)
    {
        case 1:
               printf("Enter element to insert:");
               scanf("%d",&ele);
               enqueue(&q,ele);
               PrintQueue(&q);
               break;
        case 2:
                dequeue(&q,&ele);
                printf("Removed element is: %d\n",ele);
                PrintQueue(&q);
               break;
        case 3:
               exit(1);
               break;
        default:
            printf("Entered incorrect choice\n");
    }
    }
return 0;
}
