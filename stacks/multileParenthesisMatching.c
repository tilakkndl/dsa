#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Stack
{
    int size;
    int top;
    char *arr;
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

int push(struct Stack *p, char value)
{
    if (isFull)
    {
        p->top++;
        p->arr[p->top] = value;
        // printf("the pushed value is %c\n", p->arr[p->top]);
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
    if (isEmpty)
    {
        char val = p->arr[p->top];
        p->top--;
        // printf("The poped value is %c\n", val);
        return val;
    }
    printf("Empty stack\n");
    return 0;
}

int match(char a, char b)
{
    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    return 0;
}

int checkParenthesisi(char *exp)
{
    struct Stack *p;
    p->size = 100;
    p->top = -1;
    p->arr = (char *)malloc(p->size * sizeof(char));
    char poped_ch;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(p, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(p))
            {
                return 0;
            }
            poped_ch = pop(p);
            if (!match(poped_ch, exp[i]))
            {
                return 0;
            }
        }
    }
    if (isEmpty(p))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char *exp = "[({8*6()[]})]";
    if (checkParenthesisi(exp))
    {
        printf("The parenthesis is matching");
    }
    else
    {
        printf("The parenthesis is not mathcing");
    }
}