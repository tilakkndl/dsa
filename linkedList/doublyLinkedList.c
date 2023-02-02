#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
void doublyLinkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    } while (ptr != NULL);
}
void doublyLinkedListTraversalReversely(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("%d\t", ptr->data);
        ptr = ptr->prev;
    } while (ptr != NULL);
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
    // linking
    head->data = 1;
    head->prev = NULL;
    head->next = second;

    second->data = 2;
    second->prev = head;
    second->next = third;

    third->data = 3;
    third->next = fourth;
    third->prev = second;

    fourth->data = 4;
    fourth->prev = third;
    fourth->next = NULL;
    doublyLinkedListTraversal(head);
    printf("\n");
    doublyLinkedListTraversalReversely(fourth);
}