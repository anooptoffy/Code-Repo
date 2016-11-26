/* 
 * File:   main.cpp
 * Author: anooptoffy
 *
 * Created on November 26, 2016, 10:09 AM
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
    int *key, *pi;
    int V;
    // that contains dest and its corresponding weights
    priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > priorityQ;
    
public:

    Graph(int n){
        this->V = n;
        this->vertices = new list< pair<int,int> >[n+1];
        this->key = new int[n+1];
        this->pi = new int[n+1];
    }
    
    void addEdge(int u, int v, int w){
        // Graph under consideration is undirected.
        this->vertices[u].push_back(make_pair(v,w));
        this->vertices[v].push_back(make_pair(u,w));        
    }
    
    void MST_PRIM(int source){
        vector<bool> AddedV(this->V+1, false);
        for(int i = 1; i <= this->V; i++){
            this->key[i] = INT_MAX;
            this->pi[i] = NULL;            
        }
        
        priorityQ.push(make_pair(0,source));
        this->key[source] = 0;
        
        while(!priorityQ.empty()){
            int u = priorityQ.top().second;
            priorityQ.pop();
            AddedV[u] = true;
            list < pair<int, int> > :: iterator i;
            for(i = vertices[u].begin(); i != vertices[u].end(); ++i){
                
                int v = (*i).first;
                int w = (*i).second;
                
                if(AddedV[v] ==  false && this->key[v] > w){
                    this->key[v] = w;
                    priorityQ.push(make_pair(this->key[v], v));
                    this->pi[v] = u;
                }
            }
        }
        
        for(int i = 1; i < this->V; i++)
            cout << this->pi[i] << " " << i << endl;
        
    }
};


/*
 * 
 * using Minimum Priority Queue
 * 
 */

int main(int argc, char** argv) {
//    Graph G(9);
//    
//    G.addEdge(1,2,4);
//    G.addEdge(1,8,8);
//    G.addEdge(2,8,11);
//    G.addEdge(2,3,8);
//    G.addEdge(8,9,7);
//    G.addEdge(8,7,1);
//    G.addEdge(9,7,6);
//    G.addEdge(3,4,7);
//    G.addEdge(3,6,4);
//    G.addEdge(7,6,2);
//    G.addEdge(4,6,14);
//    G.addEdge(4,5,9);
//    G.addEdge(6,5,10);
//    G.addEdge(9,3,2);
//    
//    G.MST_PRIM(1);
    
     int V = 9;
    Graph g(V);
 
    //  making above shown graph
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
    
    g.MST_PRIM(0);
    return 0;
}

