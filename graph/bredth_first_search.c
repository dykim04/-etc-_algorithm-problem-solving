#include <stdio.h>
int queue[8] = { 0, };
int visited[8] = { 0, };
int graph[8][8] = { {0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 1, 1, 1, 0, 0, 0},
					{0, 1, 0, 1, 0, 0, 0, 0},
					{0, 1, 1, 0, 1, 1, 0, 0},
					{0, 1, 0, 1, 0, 1, 0, 0},
					{0, 0, 0, 1, 1, 0, 1, 1},
					{0, 0, 0, 0, 0, 1, 0, 0},
					{0, 0, 0, 0, 0, 1, 0, 0} };
int main(void)
{
	// BFS(1, graph);
	int previous;
	int next;
	int column;
	int vertex;
	int vertices;
	int pop;
    
	column = 0;
	vertex = 1;
	vertices = 7;
	previous = 0;
	next = 1;
    pop = 0;
	printf("%d", vertex);
    visited[1] = 1;
	while (previous < next)
	{
		previous++;
        pop = queue[previous] + 1;
        column = 1;
		while (column <= vertices)
		{
			if (graph[pop][column] == 1 && !visited[column])
			{
				printf("%d", column);
				queue[next] = column;
                next++;
				visited[column] = 1;
			}
            column++;
		}
	}
	return (0);
}