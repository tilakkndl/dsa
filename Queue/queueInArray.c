#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct queue
{
    int front;
    int rear;
    int size;
    int *arr;
};
int isEmpty(struct queue *ptr)
{
    if (ptr->rear == -1)
    {
        return 1;
    }
    else
    {

        return 0;
    }
}
int isFull(struct queue *ptr)
{
    if (ptr->rear == ptr->size - 1)
    {
        return 1;
    }
    else
    {

        return 0;
    }
}
void traversal(struct queue *ptr)
{
    if (!isEmpty(ptr))
    {
        for (int i = ptr->front; i <= ptr->rear; i++)
        {
            printf("%d\t", ptr->arr[i]);
        }
    }
}
void enque(struct queue *ptr, int n)
{
    if (!isFull(ptr))
    {
        ptr->rear++;
        ptr->arr[ptr->rear] = n;
    }
}
void dequeue(struct queue *ptr)
{
    if (!isEmpty(ptr))
    {
        ptr->rear--;
        for (int i = 0; i <= ptr->rear; i++)
        {
            ptr->arr[i] = ptr->arr[i + 1];
        }
    }
}
int main()
{
    struct queue *ptr;
    ptr = (struct queue *)malloc(sizeof(struct queue));
    ptr->size = 5;
    ptr->front = 0;
    ptr->rear = -1;
    ptr->arr = (int *)malloc(sizeof(ptr->size));
    enque(ptr, 1);
    enque(ptr, 2);
    // enque(ptr, 3);
    // enque(ptr, 4);
    // enque(ptr, 5);
    dequeue(ptr);
    dequeue(ptr);
    enque(ptr, 4);
    traversal(ptr);

    return 0;
}
