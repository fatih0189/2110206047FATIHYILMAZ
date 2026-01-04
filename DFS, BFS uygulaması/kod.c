#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int n;

// DFS (Depth First Search)
void DFS(int v) {
    printf("%d ", v);
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

// BFS (Breadth First Search)
void BFS(int start) {
    int queue[MAX], front = 0, rear = 0;
    
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        for (int i = 0; i < n; i++) {
            if (graph[v][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int start;

    printf("Node sayisini gir: ");
    scanf("%d", &n);

    printf("Adjacency Matrix gir (0-1):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Baslangic dugumunu gir: ");
    scanf("%d", &start);

    // DFS
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nDFS traversal: ");
    DFS(start);

    // BFS
    printf("\nBFS traversal: ");
    BFS(start);

    return 0;
}
