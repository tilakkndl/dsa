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
struct Node *insertAtBegining(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}
struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    ptr->data = 33;
    return head;
}
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    ptr->data = data;
    return head;
}

struct Node *insertAfterNode(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    ptr->data = data;
    return head;
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
    head = insertAtBegining(head, 1);
    printf("\nLinkedlist after insertion at begining\n");
    linkedListTraversal(head);
    printf("\nAfter inserting at index\n");
    head = insertAtIndex(head, 22, 2);
    linkedListTraversal(head);
    head = insertAtEnd(head, 999);
    printf("\nAfter inserting at the end\n");
    linkedListTraversal(head);
    printf("\nInsert after the node \n");
    head = insertAfterNode(head, third, 777);
    linkedListTraversal(head);
}