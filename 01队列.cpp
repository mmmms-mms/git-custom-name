#include<iostream>
using namespace std;
//顺序队（判空就得用循环数组。。。）
#define MAX 100
typedef struct Queue
{
	int front,rear;
	int data[MAX];

}Queue;

//初始化
void Init(Queue*q)
{
	//r=0 r-1才是真正队尾
	q->rear = 0;
	q->front = 0;
}
//增,k加入
void push(Queue *q,int k)
{
	//满？
	if ((q->rear+1)%MAX != q->front)
	{
		q->data[q->rear] = k;
		q->rear = (q->rear + 1) % MAX;//如果本来的r越界了，通过取模运算的到的结果号是在数组里
	}
	
}
//出队
void pop(Queue* q)
{
	//空？
	if (q->front == q->rear)//因为一开始初始化就是f=r的情况
	{
		cout << "队列已空！" << endl;
		return;
	}
	q->front = (q->front + 1) % MAX;
}
void Front(Queue q)
{
	cout << q.data[q.front] << endl;
}
void Rear(Queue q)
{
	cout << q.data[(q.rear-1+MAX)%MAX] << endl;//防止rear索引是负数，所以加MAX然后取模
}
//链队
typedef struct QNode
{
	int data;
	struct QNode* next;
}QNode,*Linklist;

//初始化
void Init1(Linklist Q)
{
	Q->next == NULL;
}

//加的话就是尾插法，删除的话就是首元节点开始
int main()
{
	Queue q;
	Init(&q);
	push(&q, 1);
	Front(q);
	push(&q, 2);
	push(&q, 3);
	push(&q, 4);
	Front(q);
	Rear(q);
	pop(&q);
	Rear(q);
	return 0;
}
