#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void check_map(int ** graph, int node, int line);
void check(int **graph, int node, int n);
int visit[1001];
int main (void)
{
    int node, line;
    int x, y;
    int **graph;
    int i = 0;
    int k = 0;
    scanf("%d %d", &node, &line);
    graph = (int **)malloc(sizeof(int *) * node);
    while (i < node)
    {
        graph[i] = (int *)malloc(sizeof(int) * node);
        i++;
    }
    while (k < line)
    {
        scanf("%d %d", &x, &y);
        graph[x-1][y-1] = 1;
        graph[y-1][x-1] = 1;
        k++;
    }
    check_map(graph, node, line);    
}
void check_map(int **graph, int node, int line)
{
    int count = 0;   
    for (int i = 0; i < node; i++)
    {
        if (visit[i] != 1)
        {
            count++;
            visit[i] = 1;
            check(graph, node, i);
        }
    }
    printf("%d\n", count);
}
void check(int **graph, int node, int n)
{
    for (int i = 0; i < node; i++)
    {
        if (visit[i]!= 1 && graph[n][i] == 1)
        {
            visit[i] = 1;
            check(graph, node, i);
        }
    }
}