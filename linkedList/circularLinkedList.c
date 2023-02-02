#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void circularLinkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    return ptr;
}

struct Node *deletionAtFirst(struct Node *head)
{
    struct Node *p = head->next;
    struct Node *q = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = q;
    return q;
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
    fourth->next = head;

    circularLinkedListTraversal(head);
    printf("\n");
    head = insertAtFirst(head, 999);
    circularLinkedListTraversal(head);
    printf("\n");
    head = deletionAtFirst(head);
    circularLinkedListTraversal(head);
}