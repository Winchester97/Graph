#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include<iostream>
#include<stdlib.h>

#define numVertex(V) V->numVertex
#define firstEdge(V) V->firstEdge
#define nextVertex(V) V->nextVertex
#define source(E) E->source
#define dest(E) E->dest
#define sNextEdge(E) E->sNextEdge
#define dNextEdge(E) E->dNextEdge
#define firstSource(G) G.firstSource
#define firstDest(G) G.firstDest

using namespace std;

typedef struct elmtVertex *adrVertex;
typedef struct elmtEdge *adrEdge;

typedef struct elmtVertex{
    int numVertex;
    adrEdge firstEdge;
    adrVertex nextVertex;
};

typedef struct elmtEdge{
    int source;
    int dest;
    adrEdge sNextEdge;
    adrEdge dNextEdge;
};

typedef struct graph{
    adrVertex firstSource;
    adrVertex firstDest;
};

adrVertex createVertex(int nomor);
graph createGraph();
adrEdge createEdge(int asal, int tujuan);
adrVertex sourceVertex(int numVertex, graph G);
adrVertex destinationVertex(int numVertex, graph G);
void addEdge(int X, int Y, graph &G);
void printArah(graph G);

#endif // GRAPH_H_INCLUDED
