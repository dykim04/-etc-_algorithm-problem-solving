#include <stdio.h>
#include <stdlib.h>

struct node
{
    int     data;
    struct  node *next;
}           *first = NULL;

void create(int num[], int n)
{
    int i = 0;
    struct node *t, *connect;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = num[0];
    first->next = NULL;
    connect = first;

    for (i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        // connect = (struct node *)malloc(sizeof(struct node));
        t->data = num[i];
        t->next = NULL;
        connect->next = t;
        connect = t;
        // first->next = t;
        // first = t;
    }
}

void display(struct node *first)
{
    while (first != NULL)
    {
        printf("%d ", first->data);
        first = first->next;
    }
}
int main()
{
    int num[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    create(num, 9);
    display(first);
    return (0);
}