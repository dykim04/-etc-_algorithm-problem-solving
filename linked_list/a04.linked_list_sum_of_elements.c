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

int sum_of_elements(struct node *p)
{
    int sum = 0;
    while (p != 0)
    {
        sum = sum + (p->data);
        p = p->next;
    }
    return (sum);
}

int main()
{
    int A[] = {0, 1, 2, 3, 4, 5, 6, 7};
    create(A,8);
    printf("%d", sum_of_elements(start));
    return (0);
}