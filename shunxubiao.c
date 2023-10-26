#include <stdio.h>
#include <stdlib.h>
#define error 0
#define ok 1
#define SIZEMAX 100
typedef int Elemtype;
typedef struct Sqlist{
    int length;
    Elemtype* base;
}Sqlist;
int Insert(Sqlist* L,int position,Elemtype e);
int Init(Sqlist *L,int length)
{
    L->base=(Elemtype*)malloc((sizeof(Elemtype))*SIZEMAX);
    if(!L->base)
        return error;
    L->length=0;
    for(int i=1;i<length+1;i++)
    {
        Elemtype e;
        scanf("%d",&e);
        Insert(L,i,e);
    }
    return ok;
}
int Insert(Sqlist* L,int position,Elemtype e)
{
    if(position<1||position>L->length+1)
        return error;
    if(L->length==SIZEMAX)
        return error;
    for(int i=L->length-1;i>=position-1;i--)
    {
        L->base[i+1]=L->base[i];
    }
    L->base[position-1]=e;
    L->length++;
    return ok;
}
int Dele(Sqlist* L,int position)
{
    if(position<1||position>L->length)
        return error;
    for(int i=position-1;i<L->length;i++)
    {
        L->base[i]=L->base[i+1];
    }
    L->length--;
    return ok;
}
int Getelem(Sqlist* L,int position,Elemtype* e)
{
    if(position<1||position>L->length)
        return error;
    (*e)=L->base[position-1];
    return ok;
}
int LocateElem(Sqlist* L,Elemtype e)
{
    int i=0;
    while((L->base[i]!=e)&&i!=SIZEMAX)
    {
        i++;
    }
    if(i==SIZEMAX)
        return error;
    return i+1;   
}
int Destroy(Sqlist* L)
{
    if(!L->base)
        return error;
    else
        free(L->base);
    return ok;
}
void Clear(Sqlist* L)
{
    L->length=0;
}
int Isempty(Sqlist * L)
{
    if(0==L->length)
        return ok;
    else
        return error;
}
void print(Sqlist* L)
{
    for(int i=0;i<L->length;i++)
        printf("%d ",L->base[i]);
}
void MergeList(Sqlist* p1,Sqlist* p2)
{
    for(int i=1;i<=p2->length;i++)
    {
        Elemtype e;
        Getelem(p2,i,&e);
        if(!LocateElem(p1,e))
        {
            p1->base[p1->length++]=e;
        }
    }
}
void Traverse(Sqlist* L)
{
    for(int i=0;i<L->length;i++)
    {
        printf("%d ",L->base[i]);
    }
}
void Merge2(Sqlist* p1,Sqlist *p2,Sqlist* p3)
{
    p3->length=p1->length+p2->length;
    Elemtype* a1=p1->base;
    Elemtype* a1_last=&(p1->base[p1->length-1]);
    Elemtype* a2=p2->base;
    Elemtype* a2_last=&(p2->base[p2->length-1]);
    Elemtype* a3=p3->base;
    while(a1<=a1_last&&a2<=a2_last)
    {
        if(*a1<*a2)
        {
            *(a3++)=*(a1++);
        }
        else
            *(a3++)=*(a2++);
    }
    while(a1<=a1_last)
        *(a3++)=*(a1++);
    while(a2<=a2_last)
        *(a3++)=*(a2++);
}
    
//线性表合并
// int main()
// {
//     Sqlist p1,p2;
//     Init(&p1,3);
//     Init(&p2,4);
//     MergeList(&p1,&p2);
//     Traverse(&p1);
//     system("pause");
//     return 0;
// }
//有序表合并
int main()
{
    Sqlist p1,p2,p3;
    Init(&p1,3);
    Init(&p2,4);
    Init(&p3,0);
    Merge2(&p1,&p2,&p3);
    Traverse(&p3);
    return 0;
}