//2. Modify the Above Program to include a menu-driven Program and 
//add options for the depath-first traversal and breadth-first traversal 
//and Write code for those traversals. 


#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100

struct Graph {
    int numVertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
};

void initializeGraph(struct Graph *graph, int numVertices) {
    graph->numVertices = numVertices;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
}

void addEdge(struct Graph *graph, int source, int destination) {
    graph->adjacencyMatrix[source][destination] = 1;
    graph->adjacencyMatrix[destination][source] = 1;
}

void depthFirstTraversal(struct Graph *graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjacencyMatrix[vertex][i] == 1 && visited[i] == 0) {
            depthFirstTraversal(graph, i, visited);
        }
    }
}

void breadthFirstTraversal(struct Graph *graph, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;
    visited[startVertex] = 1;
    printf("%d ", startVertex);
    queue[rear++] = startVertex;
    while (front < rear) {
        int currentVertex = queue[front++];
        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjacencyMatrix[currentVertex][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                printf("%d ", i);
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    struct Graph graph;
    int numVertices, choice, source, destination;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);
    initializeGraph(&graph, numVertices);
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add an edge\n");
        printf("2. Perform depth-first traversal\n");
        printf("3. Perform breadth-first traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter the source and destination vertices: ");
            scanf("%d %d", &source, &destination);
            addEdge(&graph, source, destination);
            break;
        case 2:
            printf("Depth-first traversal: ");
            int visited[MAX_VERTICES] = {0};
            for (int i = 0; i < graph.numVertices; i++) {
                if (visited[i] == 0) {
                    depthFirstTraversal(&graph, i, visited);
                }
            }
            printf("\n");
            break;
        case 3:
            printf("Breadth-first traversal: ");
            breadthFirstTraversal(&graph, 0);
            printf("\n");
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}


