#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void traverse(struct Node *head)
{
    struct Node *p = head;
    do
    {
        printf("%d\t", p->data);
        p = p->next;
    } while (p != NULL);
}

struct Node *insertAtFirst(struct Node *head, int data)
{
    // struct Node *p = head->next;
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    head->prev = ptr;
    ptr->prev = NULL;
    return ptr;
}

struct Node *insertAtEnd(struct Node *head, int data)
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
    ptr->data = data;
    ptr->prev = p;
    return head;
}

struct Node *insertAtIndex(struct Node *head, int index, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    struct Node *q = head->next;
    int i = 0;
    while (i != index - 1)
    {
        q = q->next;
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    q->prev = ptr;
    ptr->prev = p;
    return head;
}

struct Node *deleteAtFirst(struct Node *head)
{
    head = head->next;
    head->prev = NULL;
    return head;
}

struct Node *deleteAtEnd(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    return head;
}

struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    struct Node *r = q->next;
    r->prev = p;
    return head;
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

    head->prev = NULL;
    head->data = 1;
    head->next = second;

    second->prev = head;
    second->data = 11;
    second->next = third;

    third->prev = second;
    third->data = 111;
    third->next = fourth;

    fourth->prev = third;
    fourth->data = 1111;
    fourth->next = NULL;
    head = insertAtFirst(head, 2);
    head = insertAtEnd(head, 22);
    head = insertAtIndex(head, 2, 222);
    head = deleteAtIndex(head, 2);
    head = deleteAtFirst(head);
    head = deleteAtEnd(head);
    traverse(head);
}