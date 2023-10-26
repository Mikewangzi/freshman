#include<stdio.h>
#include<stdlib.h>
#define error 0;
#define ok 1;
typedef biTree* Eelmtype;
typedef struct Stack{
    Eelmtype data;
    struct Stack *next;
}Stack,*Linklist;
void Init(Linklist*s)
{
    (*s)=NULL;
}
void Push(Linklist *s,Eelmtype e)
{
    Linklist p=(Linklist)malloc(sizeof(Stack));
    p->data=e;
    p->next=(*s);
    (*s)=p;
}
int Pop(Linklist *s,Eelmtype *e)
{
    if((*s)==NULL)
        return error;
    Linklist p=(*s);
    (*e)=(*s)->data;
    (*s)=(*s)->next;
    free(p);
    return ok;
}
Eelmtype Getop(Linklist s,Eelmtype *e)
{
    if(s)
        return (s->data);
    return error;
}
int Isempty(Linklist s)
{
    if(s==NULL)
        return ok;
    return error;
}
// //进制转换
// int main()
// {
//     Linklist s;
//     Init(&s);
//     int n;
//     printf("请输入数字(十进制):");
//     scanf("%d",&n);
//     while(n)
//     {
//         Push(&s,n%8);
//         n=n/8;
//     }
//     printf("转化后的八进制为:");
//     while(!Isempty(s))
//     {
//         Eelmtype e;
//         Pop(&s,&e);
//         printf("%d",e);
//     }
//     printf("\n");
//     return 0;
// }