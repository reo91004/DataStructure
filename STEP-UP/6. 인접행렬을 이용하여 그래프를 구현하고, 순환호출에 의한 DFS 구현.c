#include <stdio.h>
#include <stdlib.h>

#define NODE 10

int adj[NODE][NODE];
int vsize;
char vdata[NODE];
int visited[NODE];

void init() {
    vsize = 0;
    for (int i = 0; i < NODE; i++)
        for (int j = 0; j < NODE; j++)
            adj[i][j] = 0;
}

int is_full() {
    if (vsize >= NODE)
        return 1;
    else
        return 0;
}

void insert_vertex(char name) {
    if (is_full()) {
        printf("Error: 정점 개수 초과\n");
    } else
        vdata[vsize++] = name;
}

void insert_edge(int u, int v, int value) {
    adj[u][v] = value;
    adj[v][u] = value;
}

void DFS_search(int n) {
    visited[n] = 1;
    printf("%c ", vdata[n]);
    for (int i = 0; i < vsize; i++)
        if ((adj[n][i] != 0) && (visited[i] == 0))
            DFS_search(i);
}

int main(void) {
    init();
    for (int i = 0; i < 8; i++)
        insert_vertex('A' + i);

    insert_edge(0, 1, 1);
    insert_edge(0, 2, 1);
    insert_edge(1, 3, 1);
    insert_edge(2, 3, 1);
    insert_edge(2, 4, 1);
    insert_edge(3, 5, 1);
    insert_edge(4, 6, 1);
    insert_edge(4, 7, 1);
    insert_edge(6, 7, 1);

    DFS_search(0);
    printf("\n");

    return 0;
}
