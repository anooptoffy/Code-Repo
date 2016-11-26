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

using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2

class Graph{
    int V;
    list<int> *vertices;
    int *color;
    int *d, *f;
    int *pi;
    int time;
    
public: 
    
    Graph(int n){
        this->V =  n;
        this->vertices = new list<int>[n + 1];
        this->color =  new int[this->V + 1];
        this->d = new int[this->V + 1];
        this->f = new int[this->V + 1];
        this->pi = new int[this->V + 1];
    }
    
    void addEdge(int u, int v){
        this->vertices[u].push_back(v);
    }
    
    void DFS(){
        for(int i = 1; i <= this->V; ++i){
            this->color[i] = WHITE;
            this->pi[i] = NULL;
        }
        this->time = 0;
        for(int i = 1; i <= this->V; ++i){
            if(this->color[i] == WHITE)
                DFS_VISIT(i);
        }
    }
    
    void DFS_VISIT(int u){
        this->color[u] = GRAY;
        this->time += 1;
        this->d[u] = time;
        list<int>::iterator k;
        cout << u << " ";
        for(k = vertices[u].begin(); k != vertices[u].end(); ++k){
            if(color[*k] == WHITE){
                this->pi[*k] = u;
                DFS_VISIT(*k);                
            }            
        }
        this->color[u] = BLACK;
        time += 1;
        this->f[u] = time; 
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
    
    G.DFS();
    
    return 0;
}

