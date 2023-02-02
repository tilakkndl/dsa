#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int size;
    int front;
    int end;
    int *arr;
};
int isFull(struct queue *ptr)
{
    if (ptr->front == (ptr->end + 1) % ptr->size)
    {
        return 1;
    }
    return 0;
}
int isEmpty(struct queue *ptr)
{
    if (ptr->front == -1 && ptr->end == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue(struct queue *ptr, int data)
{
    if (!isFull(ptr))
    {
        printf("inside enqueue\n");
        if (ptr->front == -1)
        {
            ptr->front = 0;
        }
        ptr->end = (ptr->end + 1) % ptr->size;
        ptr->arr[ptr->end] = data;
        printf("The enqued data is %d", data);
    }
}

int dequeue(struct queue *ptr)
{
    if (ptr->front != -1)
    {
        printf("Inside delete\n");
        int data = ptr->arr[ptr->front];
        if (ptr->end == ptr->front)
        {
            ptr->end = -1;
            ptr->front = -1;
        }
        else
        {
            ptr->front = (ptr->front + 1) % ptr->size;
        }
        return data;
    }
    return -1;
}
void traverse(struct queue *ptr)
{
    if (!isEmpty(ptr))
    {
        for (int i = ptr->front; i <= ptr->end; i++)
        {
            printf("%d\t", ptr->arr[i]);
        }
    }
}
int main()
{
    struct queue *ptr;
    ptr = (struct queue *)malloc(sizeof(struct queue));
    ptr->end = -1;
    ptr->front = -1;
    ptr->size = 5;
    ptr->arr = (int *)malloc(ptr->size * sizeof(int));
    enqueue(ptr, 1);
    enqueue(ptr, 2);
    enqueue(ptr, 3);
    // enqueue(ptr, 4);
    // enqueue(ptr, 5);
    // enqueue(ptr, 6);
    // enqueue(ptr, 7);
    dequeue(ptr);
    // dequeue(ptr);
    // dequeue(ptr);
    // dequeue(ptr);
    traverse(ptr);

    return 0;
}