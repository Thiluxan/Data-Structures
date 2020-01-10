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
void sortStack(stack *s){
    int data,num;
    stack temp;
    CreateStack(&temp);
    while(!IsStackEmpty(s)){
        int tmp = top(s);
        Pop(&data,s);
        while(!IsStackEmpty(&temp) && top(&temp)>tmp){
            Push(top(&temp),s);
            Pop(&num,&temp);
        }
        Push(tmp,&temp);
    }
    while(!IsStackEmpty(&temp)){
        Push(top(&temp),s);
        Pop(&data,&temp);
    }
}
void main(){
    stack s;
    CreateStack(&s);
    Push(21,&s);
    Push(45,&s);
    Push(10,&s);
    Push(34,&s);
    Push(5,&s);

    printf("Stack elements before sorting:\n");
    PrintStack(&s);

    sortStack(&s);
    printf("\n\n");

    printf("Stack elements after sorting:\n");
    PrintStack(&s);


}
