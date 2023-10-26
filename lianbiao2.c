#include<stdio.h>
#include<stdlib.h>
#define ok 1
#define error 0
typedef int Elemtype;
typedef struct Doublenode{
    Elemtype data;
    struct Doublenode* next;
    struct Doublenode* prior;
}DoubleNode,*Doublelist;
//初始化
void DInitlist(Doublelist* p)
{
    (*p)=(Doublelist)malloc(sizeof(DoubleNode));
    (*p)->next=NULL;
    (*p)->prior=NULL;
}
//创建
void Creatlist_h(Doublelist p,int n)
{
    Doublelist p1=p;
    for(int i=0;i<n;i++)
    {
        Doublelist p2=(Doublelist)malloc(sizeof(DoubleNode));
        Elemtype data;
        printf("(for %d)Please input the data:",i+1);
        scanf("%d",&data);
        p2->data=data;
        p2->next=p1->next;
        p1->next=p2;
        p2->prior=p1;
    }
}
void Creatlist_l(Doublelist p,int n)
{
    Doublelist p1=p;
    for(int i=0;i<n;i++)
    {
        Doublelist p2=(Doublelist)malloc(sizeof(DoubleNode));
        Elemtype data;
        printf("(for %d)Please input the data:",i+1);
        scanf("%d",&data);
        p2->data=data;
        p2->next=NULL;
        p1->next=p2;
        p2->prior=p1;
        p1=p2;
    }
}
Doublelist Findbeforepos(Doublelist p,int position)
{
    Doublelist p1=p;
    int i=0;
    while(p1&&i<position-1)
    {
        p1=p1->next;
        i++;
    }
    if(!p1||i>position-1)
        return NULL;
    return p1;
}
int DInsertelem(Doublelist p,int position,Elemtype e)
{
    Doublelist p1=Findbeforepos(p,position);
    Doublelist pnew=(Doublelist)malloc(sizeof(Doublelist));
    pnew->data=e;
    pnew->next=p1->next;
    p1->next->prior=pnew;
    pnew->prior=p1;
    p1->next=pnew;
    return ok;
}
int DDellist(Doublelist p,int position,Elemtype *e)
{
    Doublelist p1=Findbeforepos(p,position);
    Doublelist p2=p1->next;
    p1->next=p2->next;
    p2->next->prior=p1;
    free(p2);
    return ok;
}
void Showlist(Doublelist p)
{
    Doublelist p1=p->next;
    while(p1)
    {
        printf("%d ",p1->data);
        p1=p1->next;
    }
}
int Lengthlist(Doublelist L)
{
    int length=0;
    Doublelist p=L->next;
    while(p)
    {
        length++;
        p=p->next;
    }
    return length;
}
int main()
{
    Doublelist p=NULL;
    DInitlist(&p);
    Creatlist_l(p,5);
    Showlist(p);
    DInsertelem(p,3,3);
    printf("\n");
    Showlist(p);
    printf("\n%d",Lengthlist(p));
    return 0;
}
