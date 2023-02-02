#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int size;
    int top;
    int *arr;
};
int isFull(struct Stack *p)
{
    if (p->size - 1 == p->top)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct Stack *p)
{
    if (p->top == -1)
    {
        return 1;
    }
    return 0;
}

void popOperation(struct Stack *p)
{
    if (!isEmpty(p))
    {
        printf("The poped value is %d\n", p->arr[p->top]);
        p->top--;
    }
}

void pushOperation(struct Stack *p, int value)
{
    if (!isFull(p))
    {
        p->top++;
        p->arr[p->top] = value;
    }
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

int checkingParanthesis(struct Stack *p, char *exp)
{
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            pushOperation(p, 1);
        }
        if (exp[i] == ')')

        {
            if (isEmpty(p))
            {
                return 0;
            }
            popOperation(p);
        }
    }
    if (isEmpty(p))
    {
        return 1;
    }
    return 0;
}

int main()
{
    struct Stack *p;
    p = (struct Stack *)malloc(sizeof(struct Stack));
    p->size = 10;
    p->top = -1;
    p->arr = (int *)malloc(p->size * sizeof(int));
    // pushOperation(p, 1);
    // showData(p);
    // popOperation(p);
    // showData(p);
    char *exp = "()98*(()88)";

    if (checkingParanthesis(p, exp))
    {
        printf("The balance one.\n");
    }
    else
    {
        printf("Not balanced yrr");
    }
}