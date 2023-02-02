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
//      5
//   3     6
// 1    4

void inorder(struct Node *p)
{
    if (p != NULL)
    {
        inorder(p->left);
        printf("%d\t", p->data);
        inorder(p->right);
    }
}
//      5
//   3     6
// 1    4
int isBST(struct Node *root)
{
    static struct Node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

struct Node *searchInBinaryTree(struct Node *root, int target)
{
    if (root == NULL)
        return NULL;
    if (root->data == target)
        return root;
    else if (target < root->data)
        return searchInBinaryTree(root->left, target);
    else
        return searchInBinaryTree(root->right, target);
    // return NULL;
}

struct Node *searchBinaryTreeIterativeApproach(struct Node *root, int target)
{
    if (root == NULL)
        return NULL;
    while (root != NULL)
    {
        if (root->data == target)
        {
            return root;
        }
        else
        {
            if (target < root->data)
            {
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }
    }
    return NULL;
}

int main()
{
    struct Node *p = create(5);
    struct Node *p1 = create(3);
    struct Node *p2 = create(6);
    struct Node *p3 = create(1);
    struct Node *p4 = create(4);

    // linking node
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    //      5
    //   3     6
    // 1    4
    // printf("pre order:\n");
    // preorder(p);
    // printf("\n post Order: \n");
    // postorder(p);
    printf("\ninorder: \n");
    inorder(p);
    printf("\n isBST:-%d\n", isBST(p));
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr = searchInBinaryTree(p, 65);
    // ptr = searchBinaryTreeIterativeApproach(p, 6);

    printf("%d", ptr->data);
    if (ptr == NULL)
    {
        printf("Not found\n");
    }
    else
    {
        printf("Found on tree\n");
    }
}