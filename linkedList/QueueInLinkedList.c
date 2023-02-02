#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *enque(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

int isEmpty(struct Node *head)
{
    if (head == NULL)
    {
        return 1;
    }
    return 0;
}

struct Node *deque(struct Node *head)
{
    if (!isEmpty(head))
    {
        head = head->next;
        return head;
    }
}

void traverse(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d\t", head->data);
        head = head->next;
    }
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 111;
    third->next = fourth;

    fourth->data = 1111;
    fourth->next = NULL;

    head = enque(head, 2);
    head = enque(head, 22);
    head = enque(head, 222);
    head = enque(head, 2222);
    head = deque(head);
    head = deque(head);
    traverse(head);
}
