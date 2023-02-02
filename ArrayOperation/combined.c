#include <stdio.h>
struct arrayUpdate
{
    int size;
    int capacity;
    int array[10];
};
int insert(struct arrayUpdate *a, int index, int element)
{
    if (a->size > a->capacity)
    {
        return -1;
    }
    for (int i = a->size - 1; i >= index; i--)
    {
        a->array[i + 1] = a->array[i];
    }
    a->array[index] = element;
    a->size += 1;
    return 1;
}

void display(struct arrayUpdate *a)
{
    for (int i = 0; i < (a->size); i++)
    {
        printf("%d\t", a->array[i]);
    }
}
int delete(struct arrayUpdate *a, int index)
{
    for (int i = index; i < a->size; i++)
    {
        a->array[i] = a->array[i + 1];
    }
    a->size -= 1;
}
int main()
{
    struct arrayUpdate a;
    a.size = 4;
    for (int i = 0; i < a.size; i++)
    {
        scanf("%d", &a.array[i]);
    }
    a.capacity = 10;
    int index = 2;
    int element = 55;
    insert(&a, index, element);
    display(&a);
    printf("\n");
    delete (&a, index);
    display(&a);
}