#include "graph.h"

adrVertex createVertex(int nomor){
    adrVertex P;
    P = new elmtVertex;
    numVertex(P) = nomor;
    firstEdge(P) = NULL;
    nextVertex(P) = NULL;
    return P;
}
graph createGraph(){
    graph G;
    adrVertex P;

    //source
    P = createVertex(1);
    firstSource(G) = P;
    P = createVertex(10);
    nextVertex(firstSource(G)) = P;
    P = createVertex(17);
    nextVertex(nextVertex(firstSource(G))) = P;
    //destination
    P = createVertex(1);
    firstDest(G) = P;
    P = createVertex(10);
    nextVertex(firstDest(G)) = P;
    P = createVertex(17);
    nextVertex(nextVertex(firstDest(G))) = P;
    P = createVertex(21);
    nextVertex(nextVertex(nextVertex(firstDest(G)))) = P;
    return G;
}
adrEdge createEdge(int asal, int tujuan){
    adrEdge P = new elmtEdge;
    source(P) = asal;
    dest(P) = tujuan;
    sNextEdge(P) = NULL;
    dNextEdge(P) = NULL;
    return P;
}
adrVertex sourceVertex(int numVertex, graph G) {
    adrVertex P = firstSource(G);
    while ((numVertex(P) != numVertex) && (nextVertex(P) != NULL)) {
        P = nextVertex(P);
    } if (numVertex(P) == numVertex) {
        return P;
    } else {
        return NULL;
    }
}

adrVertex destinationVertex(int numVertex, graph G) {
    adrVertex P = firstDest(G);
    while ((numVertex(P) != numVertex) && (nextVertex(P) != NULL)) {
        P = nextVertex(P);
    } if (numVertex(P) == numVertex) {
        return P;
    } else {
        return NULL;
    }
}

void addEdge(int X, int Y, graph &G) {
    adrVertex Source = sourceVertex(X, G);
    adrVertex Dest = destinationVertex(Y, G);
    if (Source == NULL) {
        cout<<"Simpul asal tidak ada"<<endl;
    } else if(Dest == NULL) {
        cout<<"Simpul tujuan tidak ada"<<endl;
    } else {
        adrEdge E = createEdge(X,Y);
        if (firstEdge(Source) == NULL) {
            firstEdge(Source) = E;
        } else {
            sNextEdge(E) = firstEdge(Source);
            firstEdge(Source) = E;
        } if (firstEdge(Dest) == NULL) {
            firstEdge(Dest) = E;
        } else {
            dNextEdge(E) = firstEdge(Dest);
            firstEdge(Dest) = E;
        }
    }
}

void printArah(graph G){
    adrVertex P = firstSource(G);
    adrEdge E;
    while (P != NULL){
        cout << "Destinasi Vertex " << numVertex(P) << "\t: ";
        E = firstEdge(P);
        while (E != NULL){
            cout << dest(E) << " ";
            E = sNextEdge(E);
        }
        cout << endl;
        P = nextVertex(P);
    }
}
