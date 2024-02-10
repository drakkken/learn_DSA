#include <stdio.h>
#include <stdlib.h>

// adt for quueue
struct queue
{
    int rear;
    int front;
    int q[100];
} q;

void enq(int data)
{
    if (q.rear == -1)
    {
        q.front++;
        q.rear++;
        q.q[q.rear] = data;
    }
    else if (q.rear + 1 == 100)
    {
        printf("qFULL");
        return;
    }
    else
    {
        q.q[++q.rear] = data;
    }
}

int deq()
{
    if (q.front == -1)
    {
        printf("nothing to dequeu\n");
        return -1;
    }
    else if (q.front == q.rear)
    {
        int x = q.q[q.front++];
        q.front = q.rear = -1;
        return x;
    }
    else
    {
        int x = q.q[q.front++];
        return x;
    }
}
int graph[100][100];

void setGraph(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("Enter 1 if connection between %d--%d:", i, j);
            scanf("%d", &graph[i][j]);
        }
    }
}
void display(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("   %d  ", graph[i][j]);
        }
        printf("\n");
    }
}

int isEmpty()
{
    if (q.front == -1)
    {
        return 1;
    }
    else
        return 0;
}
void BFS(int u, int vis[], int n)
{
    printf("%d\t", u);
    vis[u] = 1;
    enq(u);
    while (!isEmpty())
    {
        int p = deq();
        for (int v = 1; v <= n; v++)
        {
            if (graph[p][v] == 1 && vis[v] == 0)
            {
                printf("%d\t", v);
                vis[v] = 1;
                enq(v);
            }
        }
    }
}
void main()

{

    q.rear = -1;
    q.front = -1;
    printf("Enter graph adjacency matrix\n:");
    printf("Enter nodes :");
    int n;
    scanf("%d", &n);
    int visited[n];
    // scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        visited[i] = 0;
    }
    // scanf("%d", &n);
    setGraph(n);
    display(n);
    BFS(1, visited, 4);
}