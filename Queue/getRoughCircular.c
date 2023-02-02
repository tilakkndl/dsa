#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(struct Stack *p)
{
    if (p->front = (p->rear + 1) % p->size)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct Stack *p)
{
    if (p->front == -1 && p->rear == -1)
    {
        return 1;
    }
    return 0;
}

void enque(struct Stack *p, int value)
{
    if (!isFull(p))
    {
        printf("Insie enque");
        if (p->front == -1)
        {
            p->front = 0;
        }
        p->rear = (p->rear + 1) % p->size;
        p->arr[p->rear] = value;
        printf("The enqued data is %d", value);
        printf("\n%d\n%d", p->front, p->rear);
    }
}

int deque(struct Stack *p)
{
    if (!isEmpty(p))
    {
        int value = p->arr[p->front];
        if (p->front == p->rear)
        {
            p->front = -1;
            p->rear = -1;
        }
        else
        {
            p->front = (p->front + 1) % p->size;
        }
        return value;
    }
    return -1;
}

void traverse(struct Stack *p)
{
    for (int i = p->front; i <= p->rear; i++)
    {
        printf("The\n");
        printf("%d\t", p->arr[i]);
    }
}

int main()
{
    printf("tilak");
    struct Stack *p;
    p = (struct Stack *)malloc(sizeof(struct Stack));

    p->size = 5;
    p->front = -1;
    p->rear = -1;
    p->arr = (int *)malloc(p->size * sizeof(int));

    enque(p, 1);
    enque(p, 2);
    enque(p, 3);
    deque(p);
    traverse(p);
}