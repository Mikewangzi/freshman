#include <stdio.h>
#define MAXSIZE 20
typedef struct String{
    char S[MAXSIZE+1];
    int length;
}String;
int Getlength(String* s)
{
    int j=0;
    int i=1;
    while(s->S[i]!='#')
    {
        i++;
        j++;
    }
    return j;
}
void Init(String * s)
{
    scanf("%s",&s->S[1]);
    s->length=Getlength(s);
}
//BF算法
int BF(String* a,String *b,int position)
{
    int j=position;
    int i=1;
    while(i<=b->length&&j<=a->length)
    {
        if(a->S[j]==b->S[i])
        {
            j++;
            i++;
        }
        else{
            j=j-i+2;
            i=1;
        }
    }
    if(i>b->length)
        return j-b->length;
    else 
        return 0;
}
//KMP算法
int KMP(String* a,String *b,int position,int next[])
{
    int j=position;
    int i=1;
    while(i<=b->length&&j<=a->length)
    {
        if(j==0||a->S[j]==b->S[i])
        {
            j++;
            i++;
        }
        else{
            j=next[j];
        }
    }
    if(i>b->length)
        return j-b->length;
    else 
        return 0;
}
int main()
{
    String a,b;
    Init(&a);
    Init(&b);
    int next[7+1];
    int c=BF(&a,&b,1,next);
    printf("%d",c);
    return 0;
}