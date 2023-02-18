#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int     data;
    struct  Node *next;
}           *first = NULL;

void create(int A[],int n)
{
    int     i;
    struct  Node *t;
    struct  Node *link;
    
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    link = first;
    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        link->next = t;
        link = t;
    }
}

void Display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
}

void RDisplay(struct Node *p)
{
    if(p != NULL)
    {
        RDisplay(p->next);
        printf("%d ", p->data);
    }
}

int main()
{
    int A[] = {0, 1, 2, 3, 4, 5, 6, 7};
    create(A,8);
    Display(first);
    printf("\n");
    RDisplay(first);
    printf("\n");
    return (0);
}