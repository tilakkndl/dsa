#include <stdio.h>
void display(int arr[], int size)
{
    // array traverse
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", arr[i]);
    }
}
int deletionOfElement(int arr[], int size, int element, int capacity, int index)
{
    if (size >= capacity)
    {
        return -1;
    }
    for (int i = index; i <= size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    // arr[index] = element;
    return 1;
}

int main()
{
    int arr[100] = {7, 8, 12, 27, 88};
    int size = 5;
    int element = 45;
    int index = 1;
    display(arr, size);
    deletionOfElement(arr, size, element, 100, index);
    size -= 1;
    printf("\n");
    display(arr, size);
}