#include <stdio.h>
#include <stdlib.h>
int source, V, E, time, visited[20], Graph[20][20];
void DFS(int i)
{
    int j;
    visited[i] = 1;
    printf(" %d->", i + 1);
    for (j = 0; j < V; j++)
    {
        if (Graph[i][j] == 1 && visited[j] == 0)
            DFS(j);
    }
}
int main()
{
    int i, j, v1, v2;
    printf("\tGraphs\n");
    E = 11;
    V = 10;
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
            Graph[i][j] = 0;
    }
    Graph[0][1] = 1;
    Graph[0][2] = 1;
    Graph[1][3] = 1;
    Graph[1][4] = 1;
    Graph[2][5] = 1;
    Graph[2][6] = 1;
    Graph[3][7] = 1;
    Graph[4][8] = 1;
    Graph[5][9] = 1;
    Graph[7][8] = 1;
    Graph[8][9] = 1;
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
            printf(" %d ", Graph[i][j]);
        printf("\n");
    }
    printf("\n");
    source = 1;
    DFS(source - 1);
    printf("NULL");
    return 0;
}
