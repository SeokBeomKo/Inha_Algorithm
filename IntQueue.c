#include <stdio.h>
#include <stdlib.h>
#include "IntQueue.h"

int Initialize(IntQueue* q, int max)
{
	q->front = q->num = q->rear = 0;
	q->que = calloc(max, sizeof(int));
	if (q->que == NULL)
	{
		q->max = 0;
		return -1;
	}
	q->max = max;
	return 0;
}

int Enque(IntQueue* q, int x)
{
	if (q->num >= q->max)
		return -1;
	q->que[q->rear] = x;
	q->rear++;
	q->num++;
	if (q->rear == q->max)
		q->rear = 0;
	return 0;
}

int Deque(IntQueue* q, int* x)
{
	if (q->num <= 0)
		return -1;
	*x = q->que[q->front++];
	q->num--;
	if (q->front == q->max)
		q->front = 0;
	return 0;
}

int Peek(const IntQueue* q, int* x)
{
	if (q->num == 0)
		return -1;
	*x = q->que[q->front];
	return 0;
}

void Clear(IntQueue* q)
{
	Initialize(q, q->max);
}

int Capacity(const IntQueue* q)
{
	return q->max;
}

int Size(IntQueue* q)
{
	return q->num;
}

int IsEmpty(const IntQueue* q)
{
	return q->num == 0;
}

int IsFull(const IntQueue* q)
{
	return q->num == q->max;
}

int Search(const IntQueue* q, int x)
{
	for (int i = 0; i < q->num; i++)
	{
		if (q->que[i] == x)
			return i;
	}
	return 0;
}

void Print(const IntQueue* q)
{
	if (q->num == 0)
	{
		printf("데이터 없음\n");
		return;
	}
	for (int i = 0; i < q->num; i++)
	{
		printf("%d", q->que[i + q->front % q->max]);
	}
	printf("\n");
}

void Terminate(IntQueue* q)
{
	if (q->que != NULL)
	{
		free(q->que);
	}
	q->max = q->front = q->num = q->rear = 0;
}
