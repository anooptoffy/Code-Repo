/* 
 * File:   main.cpp
 * Author: Anoop Toffy
 *
 * Created on November 21, 2016, 1:53 PM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <climits>
#include <list>
#include <queue>

#define WHITE 0
#define GRAY 1
#define BLACK 2

using namespace std;

class Graph{
    int V;
    list<int> *vertices;
public: 
    
    Graph(int n){
        this->V =  n;
        this->vertices = new list<int>[n+1];
    }
    
    void addEdge(int u, int v){
        this->vertices[u].push_back(v);
    }
    
    void BFSCormen(int source){
        int color[this->V];
        int d[this->V];
        int pi[this->V];
        
        for(int i = 1; i <= this->V; i++){
            color[i] = WHITE;
            d[i] = INT_MAX;
            pi[i] = NULL;
        }
        
        color[source] = GRAY;
        d[source] = 0;
        pi[source] = NULL;
        queue<int> Q;
        
        Q.push(source);
        list<int>::iterator k;
        
        while(!Q.empty()){
            int u = Q.front();
            cout << u << " ";
            Q.pop();
            for(k = vertices[u].begin(); k != vertices[u].end(); ++k){
                if(color[*k] == WHITE){
                    color[*k] = GRAY;
                    d[*k] = d[u] + 1;
                    pi[*k] = u;
                    Q.push(*k);
                }
                color[u] = BLACK;
            }
        }
    }
};

/*
 * 
 * Main program to list the vertices.
 * 
 */

int main(int argc, char** argv) {
    
    Graph G(8);
    
    // Populating the adjacency list of the Graph.
    G.addEdge(2,1);
    G.addEdge(1,8);
    G.addEdge(2,7);
    G.addEdge(7,3);
    G.addEdge(7,6);
    G.addEdge(3,4);
    G.addEdge(6,4);
    G.addEdge(6,5);
    G.addEdge(5,4);
    G.addEdge(6,3);
    
    G.BFSCormen(2);
    
    return 0;
}

