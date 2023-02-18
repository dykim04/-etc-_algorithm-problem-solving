#include <stdio.h>
#include <stdlib.h>

struct node
{
        struct node *next;
        int data;
}			         *start = NULL;

void create(int arr[], int len)
{
        struct node *head;
        struct node *linker;
        start = (struct node *)malloc(sizeof(struct node) * (1));
        start->data = arr[0];
        start->next = NULL;
        linker = start;

        int rotation = 1;
        while (rotation < len)
        {
                head = (struct node *)malloc(sizeof(struct node) * (1));
                head->data = arr[rotation];
                head->next = NULL;
                linker->next = head;
                linker = head;
                rotation++;
        }
}

void display(struct node *start)
{
        while (start)
        {
                printf("%d", start->data);
                if (start->next)
                        printf(" -> ");
                start = start->next;
        }
}

void display_address(struct node *start)
{
        while (start)
        {
                printf("%p\n", start);
                start = start->next;
        }
        printf("\n");
}

struct node *search(struct node *start, int key)
{
        while (start)
        {
                if (key == start->data)
                        return (start);
                start = start->next;
        }
        return (NULL);
}

struct node *advanced_search(struct node *current, int key)
{
        struct node *previous;

        previous = current;
        while (current)
        {
                if (current->data == key)
                {
                        previous->next = current->next;
                        current->next = start;
                        start = current;
                }
                previous = current;
                current = current->next;
        }
        return (previous); 
}

void insert(struct node *current, int index, int len, int x)
{
        struct node *res;
        int rotation = 0;

        if (index < 0 || index > len)
                return;
        res = (struct node *)malloc(sizeof(struct node));
        res->data = x;
        if (index == 0)
        {
                res->next = start;
                start = res;
        }
        else
        {
                while (rotation < index - 1)
                {
                        current = current->next;
                        rotation++;
                }
                res->next = current->next;
                current->next = res;
        }
}

int main(void)
{
        int arr[] = {3, 4, 5, 1, 2, 0, 6, 8, 9};
        int len = sizeof(arr) / sizeof(arr[0]);

        create(arr, len);
        display(start); printf("\n\n");
        printf("node addr = [%p]\n\n", search(start, 19));
        display(start); printf("\n\n");
        advanced_search(start, 0);
        display(start); printf("\n\n");
        display_address(start);
        display(start); printf("\n\n");
        insert(start, 7, len, 90000);
        display(start); printf("\n");
        return (0);
}
