/* 
 * File:   main.cpp
 * Author: anooptoffy
 *
 * Created on November 26, 2016, 4:37 PM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <climits>
#include <vector>
#include <list>
#include <algorithm>
#include <map>
#include <utility>


using namespace std;

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

/*
 * 
 * Implementation of disjoint set using ranks and path compression.
 * 
 */
int main(int argc, char** argv) {
    
    DisjointSets ds;
    ds.makeSet(1);
    ds.makeSet(2);
    ds.makeSet(3);
    ds.makeSet(4);
    ds.makeSet(5);
    ds.makeSet(6);
    ds.makeSet(7);
    
    ds.unionSet(1,2);    
    ds.unionSet(2,3);
    ds.unionSet(4,5);
    ds.unionSet(6,7);
    ds.unionSet(5,6);
    ds.unionSet(3,7);
    
    cout << ds.findSet(1) << endl;
    cout << ds.findSet(2) << endl;
    cout << ds.findSet(4) << endl;
    cout << ds.findSet(6) << endl;
    cout << ds.findSet(7) << endl;
    
    return 0;
}

