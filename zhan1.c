#include<stdio.h>
#include<stdlib.h>
#define error 0;
#define ok 1;
#define SIZE_max 100
typedef int Eelmtype;
typedef struct Stack{
    int stacksize;
    Eelmtype* base;
    Eelmtype* top;
}Stack;
int Init(Stack *s)
{
    s->base=(Stack*)malloc(sizeof(Stack)*SIZE_max);
    if(!s->base)
        return error;
    s->top=s->base;
    int stacksize=SIZE_max;
    return ok;
}
int lengthstack(Stack *s)
{
    return s->top-s->base;
}
int Isempty(Stack* s)
{
    if(s->top==s->base)
        return ok;  
    return error;
}
int Isfull(Stack* s)
{
    if(s->top-s->base==SIZE_max)
        return ok;
    return error;
}
int Clear(Stack* s)
{
    if(s->base)
        s->top=s->base;
    return ok;
}
int Destroy(Stack* s)
{
    if(s->base)
        free(s->base);
        s->stacksize=0;
        s->base=s->top=NULL;
    return ok;
}
int Push(Stack* s,Eelmtype e)
{
    if(s->top-s->base==SIZE_max)
        return error;
    *(s->top)=e;
    s->top++;
    return ok;
}
int Pop(Stack* s,Eelmtype *e)
{
    if(s->top-s->base==0)
        return error;
    s->top--;
    (*e)=*(s->top);
    return ok;
}
Eelmtype Getop(Stack* s)
{
    if(!Isempty(s))
        return *(s->top-1);
}

int main()
{
    Stack s;
    Init(&s);
    int n;
    printf("请输入数字(十进制):");
    scanf("%d",&n);
    while(n)
    {
        Push(&s,n%8);
        n=n/8;
    }
    printf("转化后的八进制为:");
    while(!Isempty(&s))
    {
        Eelmtype e;
        Pop(&s,&e);
        printf("%d",e);
    }
    printf("\n");
    return 0;
}