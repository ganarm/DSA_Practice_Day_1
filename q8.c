// Q.8
/*
check whether we can use simple vertices here or not. first try to refer following code then jump to following code 
Dijiktras Algorithm : https://github.com/ganarm/DSA/blob/main/Dijiktras_Algo.c

Write a program to represent a graph of your city using adjacency matrix Vadjacency list. Nodes should represent the various areas 
in the city and links should represent the distance between them. Find the shortest path of your college from your home using Dijkstra's algorithm

*/

#include<stdio.h>
#include<string.h>
#define MAX 10
#define INF 99999

int vis[MAX] = {0}, pred[MAX] = {0}, distance[MAX] = {0}, visited[MAX], count, mindistance, nextnode;
int n, i, j, G[MAX][MAX] = {0}, cost[MAX][MAX], s;
char areas[MAX][20];
char start[20], end[20];

void dis();

int get_index(char* area) {
    for (i = 0; i < n; i++) {
        if (strcmp(areas[i], area) == 0) {
            return i;
        }
    }
    return -1;
}

void main() {
    printf("\nHOW MANY AREAS IN THE CITY: ");
    scanf("%d", &n);

    // Input areas
    printf("Enter names of the areas:\n");
    for (i = 0; i < n; i++) {
        printf("Area %d: ", i + 1);
        scanf("%s", areas[i]);
    }

    while (1) {
        printf("\nENTER AN EDGE FROM AREA (e.g., A_Nagar B_Nagar), ENTER (0 0) TO EXIT: ");
        scanf("%s %s", start, end);
        
        if (strcmp(start, "0") == 0 && strcmp(end, "0") == 0) {
            break;
        }
        
        int v1 = get_index(start);
        int v2 = get_index(end);
        
        if (v1 == -1 || v2 == -1) {
            printf("\nPLEASE ENTER VALID AREAS.\n");
            continue;
        }
        
        int wt;
        printf("ENTER WEIGHT BETWEEN %s and %s: ", start, end);
        scanf("%d", &wt);

        if (wt == 0) {
            printf("\nWEIGHT CANNOT BE ZERO (no direct path).\n");
            continue;
        }

        G[v1][v2] = wt;
        G[v2][v1] = wt;  // For undirected graph, add this line
    }

    printf("\nADJACENCY MATRIX OF THE GRAPH:\n\n");
    printf("   ");
    for (i = 0; i < n; i++) {
        printf("%10s", areas[i]);
    }
    printf("\n");

    for (i = 0; i < n; i++) {
        printf("%10s", areas[i]);
        for (j = 0; j < n; j++) {
            printf("%10d", G[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter start area: ");
    scanf("%s", start);
    s = get_index(start);
    
    if (s == -1) {
        printf("\nINVALID START AREA.\n");
        return;
    }

    dis();
}

void dis() {
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (G[i][j] == 0) {
                cost[i][j] = INF;
            } else {
                cost[i][j] = G[i][j];
            }
        }
    }

    for (i = 0; i < n; i++) {
        distance[i] = cost[s][i];
        pred[i] = s;
        visited[i] = 0;
    }

    distance[s] = 0;
    visited[s] = 1;
    count = 1;

    while (count < n - 1) {
        mindistance = INF;
        for (i = 0; i < n; i++) {
            if (distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i];
                nextnode = i;
            }
        }

        visited[nextnode] = 1;
        for (i = 0; i < n; i++) {
            if (!visited[i]) {
                if (mindistance + cost[nextnode][i] < distance[i]) {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
            }
        }
        count++;
    }

    for (i = 0; i < n; i++) {
        if (i != s) {
            printf("\nShortest Path from %s to %s: %d", areas[s], areas[i], distance[i]);
            printf("\nPath: %s", areas[i]);
            j = i;
            do {
                j = pred[j];
                printf(" <- %s", areas[j]);
            } while (j != s);
            printf("\n");
        }
    }
}
/*
// Name : Ganesh R Mali (+91-9021817579)
// Dijkstra's Algorithm : Single Source Shortest Path Algorithm 
#include<stdio.h>
#include<string.h>
#define MAX 10
#define INF 99999

int vis[MAX] = {0}, pred[MAX] = {0}, distance[MAX] = {0}, visited[MAX], count, mindistance, nextnode;
int n, i, j, G[MAX][MAX] = {0}, cost[MAX][MAX], s;
char areas[MAX][20];
char start[20], end[20];

void dis();

int get_index(char* area) {
    for (i = 0; i < n; i++) {
        if (strcmp(areas[i], area) == 0) {
            return i;
        }
    }
    return -1;
}

void main() {
    printf("\nHOW MANY AREAS IN THE CITY: ");
    scanf("%d", &n);

    // Input areas
    printf("Enter names of the areas:\n");
    for (i = 0; i < n; i++) {
        printf("Area %d: ", i + 1);
        scanf("%s", areas[i]);
    }

    while (1) {
        printf("\nENTER AN EDGE FROM AREA (e.g., A_Nagar B_Nagar), ENTER (0 0) TO EXIT: ");
        scanf("%s %s", start, end);
        
        if (strcmp(start, "0") == 0 && strcmp(end, "0") == 0) {
            break;
        }
        
        int v1 = get_index(start);
        int v2 = get_index(end);
        
        if (v1 == -1 || v2 == -1) {
            printf("\nPLEASE ENTER VALID AREAS.\n");
            continue;
        }
        
        int wt;
        printf("ENTER WEIGHT BETWEEN %s and %s: ", start, end);
        scanf("%d", &wt);
        G[v1][v2] = wt;
        G[v2][v1] = wt;  // For undirected graph, add this line
    }

    printf("\nADJACENCY MATRIX OF THE GRAPH:\n\n");
    printf("   ");
    for (i = 0; i < n; i++) {
        printf("%10s", areas[i]);
    }
    printf("\n");

    for (i = 0; i < n; i++) {
        printf("%10s", areas[i]);
        for (j = 0; j < n; j++) {
            printf("%10d", G[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter start area: ");
    scanf("%s", start);
    s = get_index(start);
    
    if (s == -1) {
        printf("\nINVALID START AREA.\n");
        return;
    }

    dis();
}

void dis() {
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (G[i][j] == 0) {
                cost[i][j] = INF;
            } else {
                cost[i][j] = G[i][j];
            }
        }
    }

    for (i = 0; i < n; i++) {
        distance[i] = cost[s][i];
        pred[i] = s;
        visited[i] = 0;
    }

    distance[s] = 0;
    visited[s] = 1;
    count = 1;

    while (count < n - 1) {
        mindistance = INF;
        for (i = 0; i < n; i++) {
            if (distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i];
                nextnode = i;
            }
        }

        visited[nextnode] = 1;
        for (i = 0; i < n; i++) {
            if (!visited[i]) {
                if (mindistance + cost[nextnode][i] < distance[i]) {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
            }
        }
        count++;
    }

    for (i = 0; i < n; i++) {
        if (i != s) {
            printf("\nShortest Path from %s to %s: %d", areas[s], areas[i], distance[i]);
            printf("\nPath: %s", areas[i]);
            j = i;
            do {
                j = pred[j];
                printf(" <- %s", areas[j]);
            } while (j != s);
            printf("\n");
        }
    }
}
*/
