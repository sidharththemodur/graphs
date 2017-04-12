
import "graph.h"

struct graph {
    Vertex *vertices;
    int numVerticies;
}

struct vertex {
    int element;
    int numNeighbors;
    Vertex *neighbors;
};

struct edge {
    Vertex a;
    Vertex b;
};

Graph *MakeGraph(int *vertices, int **neighbors, int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        addToVertArr(vertices[i], numVertices, vertArr);
    }
    for (int i = 0; i < numVertices; i++) {
        Vertex v = getVertex(vertices[i]);
        for (int j = 0; neighbors[i][j]; j++) {
            Vertex neighbor = getVertex(neighbors[i][j]);
            v->neighbors[v->numNeighbors++];
        }
    }
}

Vertex *Vertices(Graph G){
    return vertices;
}

Edge *Edges(Graph G) {
    int capacity = 0;
    for (int i = 0; i < numVerticies; i++) {
        capacity += G->vertices[i]->numNeighbors;
    }
    Edge *edges = calloc(capacity * sizeof(struct edge));
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numNeighbors; j++) {
            Edge e = malloc(sizeof(struct edge));
            e->a = G->vertices[i];
            e->b = G->vertices[i]->neighbors[j];
            addToSet(e, edges, capacity);
        }
    }
    return edges;
}

Vertex *Neighbors(Graph G, Vertex V) {
    return V->connections; 
}

void addToSet(Edge *e, Edge *arr, int arrLength) {
    int hash = (e->a + e->b) % arrLength;
    for (int i = hash; i % arrLength != hash - 1; i++) {
        if (arr[i] == NULL) {
            arr[i] = e;
            break;
        } else if (arr[i]->a == e->a && arr[i]->b == e->b) {
            return;
        }
    }
}

void addToVertArr(int e, int length, Vertex *arr) {
    int hash = e % length;
    Vertex v = malloc(sizeof(struct vertex));
    v->element = e;
    v->numNeighbors = 0;
    v->neighbors = malloc(length * sizeof(Vertex));
    for (int i = hash; i % length != hash - 1; i++) {
        if (arr[i] == NULL) {
            arr[i] = v;
    }
}

Vertex getVertex(int e, Vertex *arr) {
    int hash = e % length;
    for (int i = hash; i % length != hash - 1; i++) {
        if (arr[i]->element == e) {
            return arr[i];
        }
    }
    return NULL
}
