#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int n;

// DFS ile cluster içindeki düğümleri yazdır
void DFS(int v) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

int main() {
    int clusterCount = 0;

    printf("Node sayisini gir: ");
    scanf("%d", &n);

    printf("Adjacency Matrix gir (0-1):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
        visited[i] = 0; // başlangıçta hiçbiri ziyaret edilmedi
    }

    printf("\nClusterlar:\n");

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            clusterCount++;
            printf("Cluster %d: ", clusterCount);
            DFS(i);
            printf("\n");
        }
    }

    printf("\nToplam cluster sayisi: %d\n", clusterCount);

    return 0;
}
