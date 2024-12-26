// Q. 7
// check kra ki dfs bfs hyach method ne solve kraych he ka other methods pn aahet 
// same programs aapn bsc cs la kele het link : https://github.com/ganarm/DSA/blob/main/DFS.c and https://github.com/ganarm/DSA/blob/main/BFS.c
/*
Write a program to create graph, use the map of your city as the graph. Represent graph using adjacency 
list/adjacency matrix and perform Depth First Search and Breadth First Search.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void BFS(int startVertex, int n, int G[MAX][MAX]);
void DFS(int startVertex, int n, int G[MAX][MAX]);
void add(int v);
int delt();
void DFSUtil(int v, int n, int G[MAX][MAX], int vis[]);

int front = -1, rear = -1;
int q[MAX];

int main() {
    int n, i, j, v1, v2, max_edge;
    int G[MAX][MAX] = {0};
    char choice;

    printf("\nHOW MANY VERTICES IN A GRAPH: ");
    scanf("%d", &n);
    max_edge = n * (n - 1);

    for (i = 0; i < max_edge; i++) {
        printf("\nENTER AN EDGE FROM VERTEX V1 TO VERTEX V2, ENTER (0,0) FOR EXIT: ");
        scanf("%d%d", &v1, &v2);
        if (v1 < 0 || v2 < 0 || v1 > n || v2 > n) {
            printf("\nPLEASE ENTER A VALID EDGE: ");
            i--;
        }
        if (v1 == 0 && v2 == 0)
            break;
        else {
            G[v1-1][v2-1] = 1;
            G[v2-1][v1-1] = 1;
        }
    }

    printf("\nADJACENCY MATRIX OF GRAPH:\n ");
    for (i = 0; i < n; i++)
        printf("%4d", i + 1);
    for (i = 0; i < n; i++) {
        printf("\n%d", i + 1);
        for (j = 0; j < n; j++)
            printf("%4d", G[i][j]);
        printf("\n");
    }

    printf("\nDo you want to perform BFS or DFS? Enter B for BFS and D for DFS: ");
    scanf(" %c", &choice);
    printf("\nEnter start vertex for traversal: ");
    int startVertex;
    scanf("%d", &startVertex);

    if (choice == 'B' || choice == 'b') {
        BFS(startVertex, n, G);
    } else if (choice == 'D' || choice == 'd') {
        printf("\nThe DFS Traversal: ");
        DFS(startVertex, n, G);
    } else {
        printf("Invalid choice. Please enter B for BFS or D for DFS.\n");
    }

    return 0;
}

void BFS(int startVertex, int n, int G[MAX][MAX]) {
    int vis[MAX] = {0};
    printf("\nThe BFS Traversal: ");
    vis[startVertex - 1] = 1;
    add(startVertex);
    while (front != rear) {
        int v = delt();
        printf(" %d", v);
        for (int i = 0; i < n; i++)
            if (G[v - 1][i] != 0 && vis[i] == 0) {
                add(i + 1);
                vis[i] = 1;
            }
    }
    printf("\n");
}

void DFS(int startVertex, int n, int G[MAX][MAX]) {
    int vis[MAX] = {0};
    DFSUtil(startVertex - 1, n, G, vis);
    printf("\n");
}

void DFSUtil(int v, int n, int G[MAX][MAX], int vis[]) {
    vis[v] = 1;
    printf(" %d", v + 1);
    for (int i = 0; i < n; i++)
        if (G[v][i] == 1 && vis[i] == 0)
            DFSUtil(i, n, G, vis);
}

void add(int v) {
    if (rear == MAX - 1)
        printf("\nQueue Overflow\n");
    else {
        if (front == -1)
            front = 0;
        rear++;
        q[rear] = v;
    }
}

int delt() {
    int del;
    if (front == -1 || front > rear) {
        printf("\nQueue Underflow\n");
        exit(1);
    } else {
        del = q[front];
        front++;
        return del;
    }
}
