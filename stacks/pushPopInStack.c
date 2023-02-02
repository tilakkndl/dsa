#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int size;
    int top;
    int *arr;
};
int isEmpty(struct Stack *p)
{
    if (p->top == -1)
    {
        return 1;
    }
    return 0;
}
int isFull(struct Stack *p)
{
    if (p->top == p->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int push(struct Stack *p, int value)
{
    if (!isFull(p))
    {
        p->top++;
        p->arr[p->top] = value;
        printf("the pushed value is %d\n", p->arr[p->top]);
        return 1;
    }
    else
    {
        printf("The stack is full\n");
        return 0;
    }
}

int pop(struct Stack *p)
{
    if (!isEmpty(p))
    {
        int val = p->arr[p->top];
        p->top--;
        printf("The poped value is %d\n", val);
        return val;
    }
    printf("Empty stack\n");
    return 0;
}

void showData(struct Stack *p)
{
    if (!isEmpty(p))
    {
        for (int i = 0; i <= p->top; i++)
        {
            printf("%d\t", p->arr[i]);
        }
    }
    else
    {
        printf("The array is empty.\n");
    }
}

int main()
{
    struct Stack *p;
    p = (struct Stack *)malloc(sizeof(struct Stack));
    p->top = -1;
    p->size = 5;
    p->arr = (int *)malloc(p->size * sizeof(int));
    push(p, 5);
    pop(p);
    showData(p);
    push(p, 2);
    push(p, 3);
    showData(p);
}