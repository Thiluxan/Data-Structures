//Search an element in a stack
#include<stdio.h>
#include<stdlib.h>
#define MAXSTACK 100
typedef enum{FALSE,TRUE} Boolean;
typedef struct stack{
    int top;
    int entry[MAXSTACK];
}stack;
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
void search(stack *s, int data){
    int j=0,flag=0;
    for(int i=s->top; i>=0; i--){
        if(s->entry[i] == data){
            printf("Element %d found at position from top: %d\n",data,j+1);
            flag++;
        }
        j = j + 1;
    }
    if(flag==0)
        printf("Element not found in the stack\n");
}
void main(){
    stack s;
    CreateStack(&s);
    Push(21,&s);
    Push(45,&s);
    Push(10,&s);
    Push(34,&s);
    Push(5,&s);

    printf("Stack elements:\n");
    PrintStack(&s);
    int element;
    printf("Enter element to search: ");
    scanf("%d",&element);
    search(&s,element);

}
