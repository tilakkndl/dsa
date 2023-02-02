#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
};

struct Node *create(int data)
{
    struct Node *p;
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void preorder(struct Node *p)
{
    if (p != NULL)
    {
        printf("%d\t", p->data);
        preorder(p->left);
        preorder(p->right);
    }
}

void postorder(struct Node *p)
{
    if (p != NULL)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%d\t", p->data);
    }
}

void inorder(struct Node *p)
{
    if (p != NULL)
    {
        inorder(p->left);
        printf("%d\t", p->data);
        inorder(p->right);
    }
}

int main()
{
    struct Node *p = create(4);
    struct Node *p1 = create(1);
    struct Node *p2 = create(6);
    struct Node *p3 = create(5);
    struct Node *p4 = create(2);

    // linking node
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    //      4
    //   1     6
    //   5    2
    printf("pre order:\n");
    preorder(p);
    printf("\n post Order: \n");
    postorder(p);
    printf("\ninorder: \n");
    inorder(p);
}