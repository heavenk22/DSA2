#include <stdio.h>

int graph[20][20], visited[20], n;

void BFS(int start) {
    int queue[20], front = 0, rear = 0;
    int i, v;

    for(i = 0; i < n; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");

    while(front < rear) {
        v = queue[front++];
        printf("%d ", v);

        for(i = 0; i < n; i++) {
            if(graph[v][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

void DFS(int v) {
    int i;

    visited[v] = 1;
    printf("%d ", v);

    for(i = 0; i < n; i++) {
        if(graph[v][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

int main() {
    int i, j, start;

    printf("Enter number of buildings: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting building (0 to %d): ", n-1);
    scanf("%d", &start);

    BFS(start);

    for(i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nDFS Traversal: ");
    DFS(start);

    printf("\n");

    return 0;
}