#include <stdio.h>
#include <stdlib.h>

struct node
{
    int     data;
    struct  node *next;
}           *head = NULL;

void create(int *A, int n)
{
    int     i;
    struct  node *t;
    struct  node *link;
    
    head = (struct node *)malloc(sizeof(struct node));
    head->data = A[0];
    head->next = NULL;
    link = head;
    for (i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = A[i];
        t->next = NULL;
        link->next = t;
        link = t;
    }
}

struct node* search_improved(struct node *current, int key)
{
    struct node *previous = NULL;
    while (current)
    {
        if (key == current->data)
        {
            previous->next = current->next;
            current->next = head;
            head = current;
        }
        previous = current;
        current = current->next;
    }
    return (previous);
}

int main()
{
    int A[] = {0, 1, 2, 3, 4, 5, 6, 7};
    create(A, 8);
    printf("%p\n", search_improved(head, 7));
    while (head)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    return (0);
}
