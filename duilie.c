#include <stdio.h>
#include <stdlib.h>
#define SIZEMAX 6
typedef int Eelmtype;
typedef struct{
    int front;
    int rear;
    Eelmtype* e;
}Queue;
void Init(Queue *q)
{
    (*q).e=(Eelmtype*)malloc(sizeof(Eelmtype)*SIZEMAX);
    if(!(*q).e)
        return;
    (*q).front=(*q).rear=0;
}
int Length(Queue *q)
{
    return(((*q).rear-(*q).front+SIZEMAX)%SIZEMAX);
}
int Isempty(Queue* q)
{
    if((*q).front==(*q).rear)
        return 1;
    return 0;
}
void Addque(Queue* q,Eelmtype e)
{
    if(((*q).rear+1)%SIZEMAX==(*q).front)
        return;
    (*q).e[(*q).rear]=e;
    (*q).rear=((*q).rear+1)%SIZEMAX;
}
void Delque(Queue* q,Eelmtype* e)
{
    if((*q).front==(*q).rear)
        return;
    (*e)=(*q).e[(*q).front];
    (*q).front=((*q).front+1)%SIZEMAX;
}
Eelmtype Getque(Queue* q)
{
    if((*q).front==(*q).rear)
        return 0;
    return (*q).e[(*q).front];
}
void print(Queue* q)
{
    while((*q).front!=(*q).rear)
    {
        printf("%d ",(*q).e[(*q).front]);
        (*q).front=((*q).front+1)%SIZEMAX;
    }
}
int main()
{
    Queue q;
    Init(&q);
    Addque(&q,1);
    Addque(&q,1);
    Addque(&q,2);
    int i= Length(&q);
    printf("%d\n",i);
    print(&q);
}
	//int arr[] = { 1,2,3,4,5,6,7,8,9,10 };

	//int k = 7;
	//int left = 0;
	//int sz = sizeof(arr) / sizeof(arr[0]);
	//int right = sz - 1;
	//while (left <= right)
	//{
	//	int mid = (left + right) / 2;//left+ (right - left)/2
	//	if (arr[mid] < k)
	//	{
	//		left = mid + 1;
	//	}
	//	else if (arr[mid] > k)
	//	{
	//		right = mid - 1;
	//	}
	//	else
	//	{
	//		printf("找到了，下标为:%d\n", mid);
	//		break;
	//	}
	//}
	//if (left > right)
	//{
	//	printf("没找到");
	//}