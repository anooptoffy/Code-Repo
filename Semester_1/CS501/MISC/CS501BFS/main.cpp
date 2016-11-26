/* 
 * File:   main.cpp
 * Author: Anoop Toffy
 *
 * Created on November 20, 2016, 2:39 PM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <climits>
#include <list>
#include <queue>

using namespace std;

class Graph{
    int V; // list of vertices.
    list<int> *vertices;     // adjacency list.

public:    
    // Constructor.
    Graph(int n){
        this->V = n;
        this->vertices = new list<int>[this->V+1];
    }
    
    void BFS(int source){
        
        // visited array
        int visited[this->V];
        for(int i = 1; i <= this->V;i++)
            visited[i] = false;
        
        // queue to store the vertices
        queue<int> Q;
        
        // visit the source first
        Q.push(source);
        visited[source] = true;
        list<int>::iterator i;
        
        while(!Q.empty()){
            
            source = Q.front();
            cout << source << " ";
            Q.pop();
            for(i = vertices[source].begin(); i != vertices[source].end(); i++){
                if(!visited[*i]){
                    visited[*i] = true;
                    Q.push(*i);
                }
            }
        }
        
        
        
        
    }
    
    void addEdge(int u, int v){
        this->vertices[u].push_back(v);
    }         
};


/*
 * The main function that run first.
 */
int main(int argc, char** argv) {

    // Creating a graph.
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
    
    G.BFS(2);
    return 0;
}

