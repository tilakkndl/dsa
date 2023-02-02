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

struct Node *deletionAtBegining(struct Node *head)
{
    struct Node *ptr = head->next;
    free(head);
    return ptr;
}

struct Node *deletionAtIndex(struct Node *head, int index)
{
    int i = 0;
    struct Node *tempHead = head;
    while (i < index - 1)
    {
        head = head->next;
        i++;
    }
    struct Node *ptr = head;
    struct Node *p = head->next;
    head = head->next;
    head = head->next;
    ptr->next = p->next;
    free(p);
    return tempHead;
}

struct Node *deletionAtEnd(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}
struct Node *deleteByValue(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->data != value)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
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

    // linking first and second data
    head->data = 7;
    head->next = second;

    // linking second and third
    second->data = 11;
    second->next = third;

    // linking third and fourth
    third->data = 41;
    third->next = fourth;

    // linking fourth and null
    fourth->data = 66;
    fourth->next = NULL;

    linkedListTraversal(head);
    printf("\n");
    head = deleteByValue(head, 41);
    linkedListTraversal(head);
    // head = deletionAtBegining(head);
    // printf("\n");
    // linkedListTraversal(head);
    // head = deletionAtIndex(head, 1);
    // printf("\n");
    // linkedListTraversal(head);
    // printf("\nDeletion at the end:\n");
    // head = deletionAtEnd(head);

    // linkedListTraversal(head);
}