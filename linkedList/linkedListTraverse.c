// #include <stdio.h>
// #include <stdlib.h>
// struct Node
// {
//     int data;
//     struct Node *next;
// };
// void linkedListTraversal(struct Node *ptr)
// {
//     while (ptr != NULL)
//     {
//         printf("%d\n", ptr->data);
//         ptr = ptr->next;
//     }
// }
// int main()
// {
//     struct Node *head;
//     struct Node *seccond;
//     struct Node *third;
//     struct Node *fourth;
//     // allocating memory dynamically
//     head = (struct Node *)malloc(sizeof(struct Node));
//     seccond = (struct Node *)malloc(sizeof(struct Node));
//     third = (struct Node *)malloc(sizeof(struct Node));
//     fourth = (struct Node *)malloc(sizeof(struct Node));

//     // linking first and second data
//     head->data = 7;
//     head->next = seccond;

//     // linking second and third
//     seccond->data = 11;
//     seccond->next = third;

//     // linking third and fourth
//     third->data = 41;
//     third->next = fourth;

//     // linking fourth and null
//     fourth->data = 66;
//     fourth->next = NULL;

//     linkedListTraversal(head);
// }

// INSERTION*******************************************************************************
//  #include <stdio.h>
//  #include <stdlib.h>
//  struct Node
//  {
//      int data;
//      struct Node *next;
//  };
//  void traverse(struct Node *head)
//  {
//      while (head != NULL)
//      {
//          printf("%d\t", head->data);
//          head = head->next;
//      }
//  }
//  struct Node *insertAtfirst(struct Node *head, int element)
//  {
//      struct Node *ptr;
//      ptr = (struct Node *)malloc(sizeof(struct Node));
//      ptr->data = element;
//      ptr->next = head;
//      return ptr;
//  }
//  struct Node *insertAtEnd(struct Node *head, int element)
//  {
//      struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
//      struct Node *p = head;
//      while (p->next != NULL)
//      {
//          p = p->next;
//      }
//      p->next = ptr;
//      ptr->next = NULL;
//      ptr->data = element;

//     return head;
// }

// struct Node *insertAtIndex(struct Node *head, int data, int index)
// {
//     struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
//     struct Node *p = head;
//     int i = 0;
//     while (index - 1 != i)
//     {
//         i++;
//         p = p->next;
//     }
//     ptr->data = data;
//     ptr->next = p->next;
//     p->next = ptr;
//     return head;
// }

// struct Node *insertAfterNode(struct Node *head, struct Node *second, int data)
// {
//     struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
//     struct Node *p = head;
//     while (p != second)
//     {
//         p = p->next;
//     }
//     ptr->data = data;
//     ptr->next = p->next;
//     p->next = ptr;
//     return head;
// }
// int main()
// {
//     struct Node *head;
//     struct Node *second;
//     struct Node *third;
//     struct Node *fourth;
//     head = (struct Node *)malloc(sizeof(struct Node));
//     second = (struct Node *)malloc(sizeof(struct Node));
//     third = (struct Node *)malloc(sizeof(struct Node));
//     fourth = (struct Node *)malloc(sizeof(struct Node));
//     // first and second
//     head->data = 1;
//     head->next = second;
//     // second and thirdd
//     second->next = third;
//     second->data = 2;
//     // third and fourth
//     third->data = 3;
//     third->next = fourth;
//     // fourth and null
//     fourth->data = 4;
//     fourth->next = NULL;
//     traverse(head);
//     printf("\n");
//     head = insertAtfirst(head, 11);
//     // printf("%d", head->data);
//     traverse(head);
//     printf("\n");
//     head = insertAtEnd(head, 55);
//     traverse(head);
//     printf("\n");
//     head = insertAtIndex(head, 222, 2);
//     traverse(head);
//     printf("\n");
//     head = insertAfterNode(head, second, 555);
//     traverse(head);
// }

// *****************DELETION*******************************************
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void traverse(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d\t", head->data);
        head = head->next;
    }
}

struct Node *deleteFirst(struct Node *head)
{
    head = head->next;
    return head;
}

struct Node *deleteLast(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    return head;
}
struct Node *deleteIndex(struct Node *head, int index)
{
    int i = 0;
    struct Node *p = head;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    struct Node *ptr = p->next;
    p->next = ptr->next;
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
    // first and second
    head->data = 1;
    head->next = second;
    // second and thirdd
    second->next = third;
    second->data = 2;
    // third and fourth
    third->data = 3;
    third->next = fourth;
    // fourth and null
    fourth->data = 4;
    fourth->next = NULL;
    traverse(head);
    // printf("\n");
    // head = deleteFirst(head);
    // traverse(head);
    // printf("\n");
    // head = deleteLast(head);
    // traverse(head);
    printf("\n");
    head = deleteIndex(head, 2);
    traverse(head);
}