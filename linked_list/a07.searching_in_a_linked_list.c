#include <stdio.h>
#include <stdlib.h>

struct node
{
    int     data;
    struct  node *next;
}           *start = NULL;

void create(int A[],int n)
{
    int     i;
    struct  node *t;
    struct  node *link;
    
    start = (struct node *)malloc(sizeof(struct node));
    start->data = A[0];
    start->next = NULL;
    link = start;
    for (i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = A[i];
        t->next = NULL;
        link->next = t;
        link = t;
    }
}

struct node* search(struct node *p, int key)
{
    while (p)
    {
        if (key == p->data)
            return (p);
        p = p->next;
    }
    return (NULL);
}

int main()
{
    int A[] = {0, 1, 2, 3, 4, 5, 6, 7};
    create(A, 8);
    printf("%p\n", search(start, 1));
    return (0);
}