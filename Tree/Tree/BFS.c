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
    if (p->rear == p->size - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct Stack *p)
{
    if (p->rear == -1)
    {
        return 1;
    }
    return 0;
}

void enque(struct Stack *p, int value)
{
    if (!isFull(p))
    {
        if (p->front == -1)
        {
            p->front = 0;
        }
        p->rear++;
        p->arr[p->rear] = value;
    }
}

int deque(struct Stack *p)
{
    if (!isEmpty(p))
    {
        for (int i = p->front; i <= p->rear; i++)
        {
            p->arr[i] = p->arr[i + 1];
        }
        p->rear--;
    }
}

void traverse(struct Stack *p)
{
    for (int i = p->front; i <= p->rear; i++)
    {
        printf("%d\t", p->arr[i]);
    }
}

int main()
{
    struct Stack *p;

    p = (struct Stack *)malloc(sizeof(struct Stack));
    p->arr = (int *)malloc(p->size * sizeof(int));
    p->size = 4000;
    p->front = -1;
    p->rear = -1;
    // enque(p, 1);
    // enque(p, 2);
    // enque(p, 3);
    // deque(p);
    // traverse(p);

    // BFS implementation
    int node;
    int i = 0;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int a[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};
    printf("%d", i);
    visited[i] = 1;
    enque(p, i); // enque i for exploration
    while (!isEmpty(p))
    {
        node = deque(p);
        for (int j = 0; j < 7; j++)
        {
            if (a[node][j] == 1 && visited[j] == 0)
            {
                printf("%d", j);
                visited[j] = 1;
                enque(p, j);
            }
        }
    }
}