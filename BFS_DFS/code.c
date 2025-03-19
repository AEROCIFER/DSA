#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct queue
{
    int items[50];
    int front, rear;

};

int graph[50][50];
int visited[50];

int isEmpty(struct queue* q){
   return q->front == -1; 
}

int initqueue(struct queue* q){
    q->front = q->rear = -1;
}

void enqueue(struct queue* q, int value){
    if (q->rear == 50 - 1)
        printf("Queue Overflow\n");
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(struct queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear)
            q->front = q->rear = -1;
        return item;
    }
}


void bfs(int start, int n) {
    struct queue q;
    initqueue(&q);

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    visited[start] = 1;
    enqueue(&q, start);

    printf("BFS Traversal starting from vertex %d: ", start);

    while (!isEmpty(&q)) {
        int node = dequeue(&q);
        printf("%d ", node);

        // Visit all adjacent nodes
        for (int i = 0; i < n; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}

// DFS function
void dfs(int node, int n) {
    visited[node] = 1;
    printf("%d ", node);

    // Visit all adjacent nodes
    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(i, n);
        }
    }
}

// Driver function
int main() {
    int n, edges, u, v;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Initialize graph and visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    printf("Enter the edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // For undirected graph
    }

    // BFS traversal
    printf("\n");
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &u);
    bfs(u, n);

    // DFS traversal
    printf("\n");
    // Reset visited array for DFS
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &u);
    printf("DFS Traversal starting from vertex %d: ", u);
    dfs(u, n);
    printf("\n");

    return 0;
}
