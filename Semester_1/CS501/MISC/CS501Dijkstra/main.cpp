/* 
 * File:   main.cpp
 * Author: Anoop Toffy
 *
 * Created on November 21, 2016, 2:47 PM
 * 
 * Dijkstra's using Min Priority Queue
 * 
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <climits>
#include <list>
#include <queue>
#include <vector>

using namespace std;

class Graph{
    // dest and its weight;
    list< pair<int,int> > *vertices;
    int V;
    // that contains dest and its corresponding weights
    priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > priorityQ;
    
public:

    Graph(int n){
        this->V = n;
        this->vertices = new list< pair<int,int> >[n+1];
    }
    
    void addEdge(int u, int v, int w){
        // Graph under consideration is undirected.
        this->vertices[u].push_back(make_pair(v,w));
        this->vertices[v].push_back(make_pair(u,w));        
    }
    
    void DIJKSTRA(int source){
        
        vector<int> distances(this->V, INT_MAX);
        priorityQ.push(make_pair(0,source));
        distances[source] = 0;
        
        while(!priorityQ.empty()){
            int u = priorityQ.top().second;
            priorityQ.pop();
            list < pair<int, int> > :: iterator i;
            for(i = vertices[u].begin(); i != vertices[u].end(); ++i){
                
                int v = (*i).first;
                int w = (*i).second;
                
                if(distances[v] > distances[u] + w){
                    distances[v] = distances[u] + w;
                    priorityQ.push(make_pair(distances[v], v));
                }
            }
        }
        
        for (int i = 0; i < this->V; ++i)
        printf("%d \t\t %d\n", i, distances[i]);
    }
};

/*
 * Main method where everything starts
 */
int main(int argc, char** argv) {

    // create a graph and initialize the adjacency list and adjacency matrix.
    Graph g(9);
    
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
    
    // we are considering 2 as the source.
    g.DIJKSTRA(2);
    return 0;
}

