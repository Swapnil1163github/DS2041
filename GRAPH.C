#include <stdio.h>
#include <stdlib.h>

struct Node {
  int vertex;
  struct Node *next;
};

struct Graph {
  int numVertices;
  struct Node **adjLists;
};

struct Node *create_Node(int v) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

struct Graph *create_Graph(int vertices) {
  int i;
  struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->adjLists = (struct Node **)malloc(vertices * sizeof(struct Node *));

  for (i = 0; i < vertices; i++) {
    graph->adjLists[i] = NULL;
  }

  return graph;
}

void add_Edge(struct Graph *graph, int src, int dest) {
  struct Node *newNode = create_Node(dest);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;

  newNode = create_Node(src);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
}

void print_Graph(struct Graph *graph) {
  int i;
  for (i = 0; i < graph->numVertices; i++) {
    struct Node *temp = graph->adjLists[i];
    printf("ADJACENCY LIST OF VERTEX %d\n", i);
    while (temp) {
      printf("%d -> ", temp->vertex);
      temp = temp->next;
    }
    printf("NULL\n");
  }
}

int main() {
  int vertices, edges, i;
  printf("ENTER THE NUMBER OF VERTICES: ");
  scanf("%d", &vertices);
  printf("ENTER THE NUMBER OF EDGES: ");
  scanf("%d", &edges);

  struct Graph *graph = create_Graph(vertices);

  printf("ENTER THE EDGES (SOURCE AND DESTINATION):\n");
  for (i = 0; i < edges; i++) {
    int src, dest;
    scanf("%d %d", &src, &dest);
    add_Edge(graph, src, dest);
  }

  printf("\nADJACENCY LIST REPRESENTATION OF THE GRAPH:\n");
  print_Graph(graph);

  return 0;
}
