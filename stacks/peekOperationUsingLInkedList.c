#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
}

int peek(struct Node *top, int index)
{
    for (int i = 0; i < index - 1 && top != NULL; i++)
    {
        top = top->next;
    }
    if (top != NULL)
    {
        return top->data;
    }
    else
    {
        return -1;
    }
}
int main()
{
    struct Node *head;
    struct Node *seccond;
    struct Node *third;
    struct Node *fourth;
    // allocating memory dynamically
    head = (struct Node *)malloc(sizeof(struct Node));
    seccond = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // linking first and second data
    head->data = 7;
    head->next = seccond;

    // linking second and third
    seccond->data = 11;
    seccond->next = third;

    // linking third and fourth
    third->data = 41;
    third->next = fourth;

    // linking fourth and null
    fourth->data = 66;
    fourth->next = NULL;

    linkedListTraversal(head);
    printf("\n");
    int peakValue = peek(head, 2);
    printf("The peak value is %d", peakValue);
}