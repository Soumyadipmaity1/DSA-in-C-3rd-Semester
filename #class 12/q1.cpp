//1.WAP to create an un-directed Graph using Adjacency Matrix. 


#include <stdio.h> 
#define MAX_VERTICES 100 
int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES]; 
int numVertices; 
void createGraph() { 
int i, j; 
printf("Enter the numberof vertices: "); 
scanf("%d", &numVertices); 
for (i = 0; i < numVertices; i++) { 
for (j = 0; j < numVertices; j++) { 
adjacencyMatrix[i][j] = 0; 
} 
} 
for (i = 0; i < numVertices; i++) { 
for (j = i + 1; j < numVertices; j++) { 
int edge; 
printf("Is there an edge betweenvertex %d andvertex %d? (1 for Yes, 0 for No): ", i, j); 
scanf("%d", &edge); 
adjacencyMatrix[i][j] = edge; 
adjacencyMatrix[j][i] = edge; 
} 
} 
} 
void displayGraph() { 
int i, j; 
printf("Adjacency Matrix:\n"); 
for (i = 0; i < numVertices; i++) { 
for (j = 0; j < numVertices; j++) { 
printf("%d", adjacencyMatrix[i][j]); 
} 
printf("\n"); 
} 
} 
int main() { 
createGraph(); 
displayGraph(); 
return 0; 
}