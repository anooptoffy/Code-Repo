/* 
 * File:   main.cpp
 * Author: anooptoffy
 *
 * Created on November 26, 2016, 10:57 AM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <climits>
#include <list>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>


using namespace std;

/* 
 * Kruskal's Algorithms
 * 
 * Using disjoint set data structure on trees
 * It has the following operations:
 * 
 *  Make Set
 *  Find
 *  Union/Merger
 * 
 *  It is achieved by using rank heuristics and path compression.
 *  Each set has a representative element which identifies the set
 * 
 * Application of Disjoint set includes: 
 * 
 *  Kruskal's Alg
 *  Finding Cycle in a graph.
 * 
 * Complexity of Kruskal's : O(E*lgV)
 * 
 * 
 */


/*
 * 
 *  Disjoint sets
 * 
 */

class Node{
public:
        int data;
        int rank;
        Node* parent;
};

class DisjointSets{
    // Dynamic Allocation done.
    map<long, Node> *hmap;        
    
public:
    
    DisjointSets(){
        this->hmap = new map<long, Node>;
    }
    
    void makeSet(long data){
        Node* nd = new Node();
        nd->data = data;
        nd->rank = 0;
        nd->parent = nd;
        hmap->insert(pair<long, Node>(data, *nd));
    }
    
    // for getting the representative/leader
    long findSet(long num1){
        map<long,Node>::iterator itr1 = hmap->find(num1);
        Node p = itr1->second;
        Node* parent1 = findParent(&p);
        return findParent(parent1)->data;
    }
    
    // Path compression done here
    Node* findParent(Node* nd){
        Node* parent = nd->parent;
        if(parent ==  nd)
            return parent;
        nd->parent =  findParent(nd->parent);
        return nd->parent;    
    } 
    
    /*
     * here we do rank heuristics. 
     * :D
     */
    bool unionSet(long num1, long num2){
        map<long,Node>::iterator itr1 = hmap->find(num1);
        map<long,Node>::iterator itr2 = hmap->find(num2);
        
        Node p1 = itr1->second;
        Node p2 = itr2->second;
        Node* parent1 = findParent(&p1);
        Node* parent2 = findParent(&p2);
        
        if(parent1->data == parent2->data)
            return false;
        
        if(parent1->rank >= parent2->rank)
        {
            parent1->rank = parent1->rank == parent2->rank ? parent1->rank + 1 : parent1->rank;
            parent2->parent = parent1; 
        }
        else
            parent1->parent = parent2;
        
        return true;
    }
    
};

class Graph{
    int V, E;
    list < pair<int, int> > *vertices; // to sore the list of edges that form the MST
    list < pair<int, int> > *edges;
    int *wt;
public:
    
    Graph(int n,int E){
        this->V = n;
        this->E = E;
        this->vertices = new list< pair<int, int> > [n-1]; // Since a MST contains n-1 edges, where n is the number of vertices.
        this->edges = new list < pair<int, int> > [E+1]; // edges in the increasing order.
        this->wt = new int[E+1];
    }
    
    void addEdge(int i, int u, int v, int w){
        this->edges[i].push_back(make_pair(u,v));
        this->wt[i] = w;
    }
    
    void MST_KRUSKAL(){
       
        DisjointSets ds; // we add vertices to disjoint sets.
        int k = 0;
        for(long i = 1; i <= this->V; i++)
            ds.makeSet(i);
        
        // this->edges has edges in the increasing order of weights
        for(int j = 0; j < this->E; j++){
            if(ds.findSet(this->edges[j].front().first) != ds.findSet(this->edges[j].front().second))
            {
                this->vertices[k].push_back(make_pair(this->edges[j].front().first, this->edges[j].front().second));
                k++;
                ds.unionSet(this->edges[j].front().first, this->edges[j].front().second);
            }
        }
        
        cout << "The edges in the MST are : " << endl;
        for(int h = 0; h < this->V - 1; h++){       
            cout << this->vertices[h].front().first << " " << this->vertices[h].front().second  << endl;
        }
    }
};

/*
 * 
 * Kruskal's algorithm using Disjoint Sets
 * 
 */

int main(int argc, char** argv) {
       
    Graph G(6,9);
    G.addEdge(0,1,4,1);
    G.addEdge(1,2,3,1);
    G.addEdge(2,3,4,1);
    G.addEdge(3,5,6,2);
    G.addEdge(4,2,4,3);
    G.addEdge(5,1,2,3);
    G.addEdge(6,3,6,4);
    G.addEdge(7,3,5,4);
    G.addEdge(8,4,5,6);
    
    G.MST_KRUSKAL();
    
    return 0;
}

