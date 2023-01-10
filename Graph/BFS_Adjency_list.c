#include <stdio.h>
#include <stdlib.h>
struct node
{
    int vertex;
    struct node *next;
};
struct Graph
{
    int numVertices;
    struct node **adjLists;
    int *visited;
};
struct Graph *createGraph(int);
void addEdge(struct Graph *, int, int);
struct node *create(int);
void printGraph(struct Graph *);
void bfs(struct Graph *, int);
int isEmpty(struct node *);
void enqueue(struct node **, int);
int dequeue(struct node **);
void printQueue(struct node *);
int main(void)
{
    struct Graph *graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    printGraph(graph);
    bfs(graph, 0);
    return 0;
}
struct Graph *createGraph(int vertices)
{
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct node *));
    graph->visited = malloc(vertices * sizeof(int));
    int i;
    for (i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}
void addEdge(struct Graph *graph, int src, int dest)
{
    struct node *newNode = create(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    newNode = create(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}
struct node *create(int vertex)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}
void printGraph(struct Graph *graph)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        struct node *temp = graph->adjLists[i];
        printf("\n Adjacency list of vertex %d\n ", i);
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("null\n");
    }
}
void bfs(struct Graph *graph, int startVertex)
{
    struct node *queue = NULL;
    graph->visited[startVertex] = 1;
    enqueue(&queue, startVertex);
    while (!isEmpty(queue))
    {
        printQueue(queue);
        int currentVertex = dequeue(&queue);
        printf("Visited %d ", currentVertex);
        struct node *temp = graph->adjLists[currentVertex];
        while (temp)
        {
            int adjVertex = temp->vertex;
            if (graph->visited[adjVertex] == 0)
            {
                graph->visited[adjVertex] = 1;
                enqueue(&queue, adjVertex);
            }
            temp = temp->next;
        }
    }
}
int isEmpty(struct node *queue)
{
    return queue == NULL;
}
void enqueue(struct node **queue, int value)
{
    struct node *newNode = create(value);
    if (isEmpty(*queue))
    {
        *queue = newNode;
    }
    else
    {
        struct node *temp = *queue;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
int dequeue(struct node **queue)
{
    int nodeData = (*queue)->vertex;
    struct node *temp = *queue;
    *queue = (*queue)->next;
    free(temp);
    return nodeData;
}
void printQueue(struct node *queue)
{
    while (queue)
    {
        printf("%d ", queue->vertex);
        queue = queue->next;
    }
    printf("\n");
}