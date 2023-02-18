#include <stdio.h>
#include <stdlib.h>

struct node
{
   struct  node *next;
    int     data;
}           *first = NULL;

void create(int num[], int n)
{
    int i = 0;
    struct node *t; 
    struct node *connect;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = num[0];
    first->next = NULL;
    connect = first;

    for (i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = num[i];
        t->next = NULL;
        //first->next = t;
        //first = t;
        connect->next = t;
        connect = t;
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
    int num[] = {1, 10, 3, 4, 5, 3, 7, 8, 9};
    create(num, 9);
    display(first);
    return (0);
}
