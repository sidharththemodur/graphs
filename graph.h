// A simple implementation of a Graph
// Siddhartha Modur 4/12/17

typedef struct graph *Graph;
typedef struct vertex *Vertex;
typedef struct edge *Edge;

Graph *MakeGraph(int *vertices, int *connections);
Vertex *Vertices(Graph G);
Edge *Edges(Graph G);
Vertex *Neighbors(Graph G, Vertex v);
