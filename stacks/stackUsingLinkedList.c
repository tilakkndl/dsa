#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    int *next;
};
struct Node *top = NULL;
int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct Node *top)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
struct Node *push(struct Node *top, int element)
{
    if (isFull)
    {
        struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
        ptr->data = element;
        ptr->next = top;
        return ptr;
    }
}
void traversal(struct Node *top)
{
    while (top != NULL)
    {
        printf("%d\t", top->data);
        top = top->next;
    }
}

int pop(struct Node *top)
{
    struct Node *temp = top;
    temp = temp->next;
    printf("The poped element is %d\n", top->data);
    return top->data;
}
int main()
{
    struct Node *top = (struct Node *)malloc(sizeof(struct Node));

    top = push(top, 1);
    top = push(top, 2);
    top = push(top, 3);
    traversal(top);
    printf("\n");
    pop(top);
    traversal(top);
    printf("\n");
    top = push(top, 55);
    top = push(top, 66);
    traversal(top);
    printf("\n");
    pop(top);
    traversal(top);
}