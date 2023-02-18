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

int max_element(struct node *p)
{
    int max = 0;
    while (p)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return (max);
}

int main()
{
    int A[] = {0, 1, 2, 3, 4, 5, 6, 7};
    create(A,8);
    printf("%d", max_element(start));
    return (0);
}