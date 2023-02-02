#include <stdio.h>
#include <stdlib.h>
struct list{
    int data;
    int *prev;
    int *next;
};
void isEmpty(struct list *ptr){
    if(ptr->next == NULL){
        return 1;
    }
    return 0;
}

struct list *insertAtFirst(struct list *head, int data){
    
}