//3. WAP to create a directed graph using the adjacency Matrix 
//Method. 


#include <stdio.h> 
#define MAX_VERTICES 100 
int graph [MAX_VERTICES] [MAX_VERTICES]; 
void createDirectedGraph(int vertices) 
{ 
int i, j; 
for (i = 0; i < vertices; i++) 
{ 
for (j = 0; j < vertices; j++) 
{ 
graph[i][j] = 0; 
} 
} 
int source,destination; 
while (1) 
{ 
printf("Enter source vertex (-1 to exit): "); 
scanf("%d", &source); 
if (source == -1) 
break; 
printf("Enterdestination vertex: "); 
scanf("%d", &destination); 
if (source>= vertices || destination >= vertices || source< 0 || destination < 0) 
{ 
printf("Invalid vertices! Pleasetry again.\n"); 
continue; 
} 
graph[source][destination] = 1; 
} 
} 
void displayGraph(int vertices) 
{ 
int i, j; 
printf("Directed Graph:\n"); 
for (i = 0; i < vertices; i++) 
{ 
for (j = 0; j < vertices; j++){ 
printf("%d", graph[i][j]); 
} 
printf("\n"); 
} 
} 
int main() 
{ 
int vertices; 
printf("Enter the numberof vertices in the graph: "); 
scanf("%d", &vertices); 
createDirectedGraph(vertices); 
displayGraph(vertices); 
return 0; 
}