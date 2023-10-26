#include<stdio.h>
#include<stdlib.h>
#define ok 1
#define error 0
//单链表

typedef int Status;
typedef int Elemtype;
typedef struct Lnode{
    Elemtype data;
    struct Lnode *next;
}Lnode,*Linklist;
//初始化
Status Initlist(Linklist* L)
{
    (*L)=(Linklist)malloc(sizeof(Lnode));
    (*L)->next=NULL;
    return ok;
}
//创建链表
void Creat_list_by_head(Linklist L,int n)
{
    printf("please input %d numbers:",n);
    for(int i=0;i<n;i++)
    {
        Lnode* p=(Lnode*)malloc(sizeof(Lnode));
        int data;
        scanf("%d",&data);
        p->data=data;
        p->next=L->next;
        L->next=p;
    }
}
void Creat_list_by_last(Linklist p,int n)
{
    printf("please input %d numbers:",n);
    Lnode* p_last=p;
    for(int i=0;i<n;i++)
    {
        Lnode* p=(Lnode*)malloc(sizeof(Lnode));
        int data;
        scanf("%d",&data);
        p->data=data;
        p_last->next=p;
        p->next=NULL;
        p_last=p;
    }
}
//获取元素
Status Getelem(Linklist L,int position,Elemtype *e)
{
    Linklist p=L->next;
    int i=1;
    while(p&&i<position)
    {
        p=p->next;
        i++;
    }
    if(!p||i>position)
        return error;
    (*e)=p->data;
    return ok;
}
//查找元素 
Linklist LocateElem(Linklist L,Elemtype e)
{
    Linklist p=L->next;
    while(p&&p->data!=e)
    {
        p=p->next;
    }
    if(!p)
        return error;
    return p;
}
//插入元素
Status InsertElem(Linklist L,int position,Elemtype e)
{
    Linklist p=L;
    int i=0;
    while(p&&i<position-1)
    {
        i++;
        p=p->next;
    }
    if(!p||i>position-1)
        return error;
    Lnode* pnew=(Lnode*)malloc(sizeof(Lnode));
    pnew->data=e;
    pnew->next=p->next;
    p->next=pnew;
    return ok;
}
//删除元素
Status Delelem(Linklist L,int position,Elemtype* e)
{
    Linklist p=L;
    int i=0;
    while(p&&i<position-1)
    {
        i++;
        p=p->next;
    }
    if(!p||i>position-1||!p->next)
        return error;
    Linklist p1=p->next;
    (*e)=p1->data;
    p->next=p1->next;
    free(p1);
    return ok;
}
//销毁链表
Status Destroylist(Linklist *L)
{
    if(!(*L))
        return error;
    Linklist p1=(*L);
    Linklist p2=p1;
    while(p2)
    {
        p1=p1->next;
        free(p2);
        p2=p1;
    }
    *L=NULL;
    return ok;
}
//求表长
Status Lengthlist(Linklist L)
{
    int length=0;
    Linklist p=L->next;
    while(p)
    {
        length++;
        p=p->next;
    }
    return length;
}
//清空
void Clearlist(Linklist* L)
{
    (*L)->next=NULL;
}
//展示
void Showlist(Linklist L)
{
    Linklist p=L->next;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
void Merge(Linklist *p1,Linklist* p2,Linklist *p3)
{
    (*p3)=(*p1);
    Linklist a1=(*p1)->next;
    Linklist a2=(*p2)->next;
    Linklist a3=(*p3);
    while(a1&&a2)
    {
        if(a1->data<a2->data)
        {
            a3->next=a1;
            a3=a1;
            a1=a1->next;
        }
        else
        {
            a3->next=a2;
            a3=a2;
            a2=a2->next;
        }
    }
        a3->next= a1?a1:a2;
        free(*p2);
        *p1=*p2=NULL;
    
}
int main()
{
    Linklist p1,p2,p3;
    Initlist(&p1);
    Creat_list_by_last(p1,4);
    Initlist(&p2);
    Creat_list_by_last(p2,4);
    Initlist(&p3);
    Merge(&p1,&p2,&p3);
    Showlist(p3);
    return 0;
}





