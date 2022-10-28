#include <stdio.h>
#include <stdlib.h>

#define OK               1
#define ERROR            0
#define STACK_INIT_SIZE  10
#define INCREMENT        5
#define OVERFLOW         -1
#define MAXSIZE          5
#define N                20
typedef int Status;

//循环队列

typedef struct
{
    int data[N];
    int front;
    int rear;
}RQueue,*Pqueue;

typedef struct extQueue
{
    int front;
    int rear;
    int flag;
    int data[MAXSIZE];
}ExtQueue;

//入队函数(低级版
Status EnQueue(Pqueue Q)
{
    int number;
    if((Q->rear+1)%N==Q->front)
    {
        printf("The queue is full\n");
        return ERROR;
    }
    scanf("%d",&number);
    Q->data[Q->rear]=number;
    Q->rear=(Q->rear+1)%N;
    return OK;
}
//入队函数(高级版
Status EnQueue_1(Pqueue Q,int num)
{
    if((Q->rear+1)%N==Q->front)
    {
        printf("The Queue is full\n");
        return ERROR;
    }
    Q->data[Q->rear]=num;
    Q->rear=(Q->rear+1)%N;
    return OK;
}
//出队函数
Status DeQueue(Pqueue Q)
{
    if(Q->front==Q->rear)return ERROR;
    Q->front=(Q->front+1)%N;
    return OK;
}
void bb(Pqueue Q)
{
    int cnt=0;
    int arr[20];
    while(Q->front!=Q->rear)
    {
        if(Q->data[Q->front]>=0)
        {
            arr[cnt]=Q->data[Q->front];
            cnt++;
        }
        if(Q->front==Q->rear)break;
        Q->front=(Q->front+1)%N;
    }
    int cnt_2=0;
    while(cnt_2!=cnt)
    {
        Q->data[Q->rear]=arr[cnt_2];
        cnt_2++;
        Q->rear=(Q->rear+1)%N;
    }
}

void aa(Pqueue Q)
{
    int cnt=0;
    int arr[20];
    while(Q->front!=Q->rear)
    {
        arr[cnt]=Q->data[Q->front];
        cnt++;
        DeQueue(Q);
    }
    int cnt_2=0;
    while(cnt_2!=cnt)
    {
        if(arr[cnt_2]>=0)
        {
            EnQueue_1(Q,arr[cnt_2]);
        }
        cnt_2++;
    }
}
//打印输出队列中从队头开始的所有元素
Status Print_Queue(RQueue Q)
{
    while(Q.front!=Q.rear)
    {
        printf("%d ",Q.data[Q.front]);
        Q.front=(Q.front+1)%N;
    }
}

//新入队函数
Status EnExtQueue(ExtQueue *Q,int number)
{
    if((Q->rear+1)%MAXSIZE==Q->front)
    {
        Q->data[Q->rear]=number;
        Q->rear=(Q->rear+1)%MAXSIZE;
        Q->flag=1;
        return OK;
    }
    if(Q->flag==1 && Q->front==Q->rear)
    {
        printf("队列已满，没法再排入数据啦！\n");
        return ERROR;
    }
    Q->data[Q->rear]=number;
    Q->rear=(Q->rear+1)%MAXSIZE;
    return OK;
}
//新出队函数
Status DeExtQueue(ExtQueue *Q)
{
    if(Q->flag==0  &&  Q->front==Q->rear)
    {
        printf("队列已空，没法再弹出数据啦！\n");
        return ERROR;
    }
    if((Q->front+1)%MAXSIZE  ==  Q->rear)
    {
        Q->front=(Q->front+1)%MAXSIZE;
        Q->flag=0;
        return OK;
    }
    Q->front=(Q->front+1)%MAXSIZE;
    Q->flag=2;
    return OK;
}
//新打印函数
Status Print_ExtQueue(ExtQueue Q)
{
    int start=0;
    if(Q.front==Q.rear&&Q.flag==0)//空
    {
        printf("There is nothing to print\n");
        return ERROR;
    }
    if(Q.front==Q.rear&&Q.flag==1)//满
    {
        printf("这是你的队列中的所有元素：\n");
        int p=Q.front;
        for(int i=0;i<MAXSIZE;i++)
        {
            printf("%d  ",Q.data[p]);
            p=(p+1)%MAXSIZE;
        }
        printf("\n");
        return OK;
    }
    printf("这是你的队列中的所有元素：\n");
    while(Q.front!=Q.rear)
    {
        printf("%d  ",Q.data[Q.front]);
        Q.front=(Q.front+1)%MAXSIZE;
    }
    printf("\n");
    return OK;
}

int main(void)
{
    ExtQueue EQ;
    EQ.flag=0;
    EQ.front=0;
    EQ.rear=0;
    int mode;
    printf("请选择你的模式：\n“1”代表插入，“2”代表弹出，其他键退出\n");
    scanf("%d",&mode);
    while(mode==1||mode==2)
    {
        if(mode==1)
        {
            printf("请输入你要输入元素的个数：\n");
            int m;
            scanf("%d",&m);
            printf("请输入队列中的元素：\n");
            for(int i=0;i<m;i++)
            {
                int n;
                scanf("%d",&n);
                EnExtQueue(&EQ,n);
            }
            Print_ExtQueue(EQ);
            printf("请选择你的模式：\n“1”代表插入，“2”代表弹出，其他键退出\n");
            scanf("%d",&mode);
        }
        if(mode==2)
        {
            printf("请输入你要弹出队列的元素个数:\n");
            int x;
            scanf("%d",&x);
            for(int i=0;i<x;i++)
            {
                DeExtQueue(&EQ);
            }
            Print_ExtQueue(EQ);
            printf("请选择你的模式：\n“1”代表插入，“2”代表弹出，其他键退出\n");
            scanf("%d",&mode);
        }
    }
    printf("感谢你的测试，我们下次见！\n");
    return 0;
}

/*
    RQueue Qu;
    Qu.front=0;Qu.rear=0;
    printf("Please enter your data:\n(enter 9999 to stop)\n");
    int num;
    do
    {
        scanf("%d",&num);
        if(num==9999)break;
        EnQueue_1(&Qu,num);
    }while(num!=9999);
    printf("Here is your Queue:\n");
    Print_Queue(Qu);
    printf("\n");
    aa(&Qu);
    printf("Here is your Queue after selection:\n");
    Print_Queue(Qu);
*/
