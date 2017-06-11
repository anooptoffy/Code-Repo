// A C++ Program to detect cycle in an undirected graph
#include<iostream>
#include <list>
#include <limits.h>
using namespace std;
 
// Class for an undirected graph
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
    bool isCyclicUtil(int v, bool visited[], int parent);
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // to add an edge to graph
    bool isCyclic();   // returns true if there is a cycle
    void BFS(int s, bool visited[]);
    Graph getTranspose();
    bool isConnected();
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
    adj[w].push_back(v); // Add v to w’s list.
}
 
// A recursive function that uses visited[] and parent to detect
// cycle in subgraph reachable from vertex v.
bool Graph::isCyclicUtil(int v, bool visited[], int parent)
{
    // Mark the current node as visited
    visited[v] = true;
 
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        // If an adjacent is not visited, then recur for that adjacent
        if (!visited[*i])
        {
           if (isCyclicUtil(*i, visited, v))
              return true;
        }
 
        // If an adjacent is visited and not parent of current vertex,
        // then there is a cycle.
        else if (*i != parent)
           return true;
    }
    return false;
}
 
// Returns true if the graph contains a cycle, else false.
bool Graph::isCyclic()
{
    // Mark all the vertices as not visited and not part of recursion
    // stack
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper function to detect cycle in different
    // DFS trees
    for (int u = 0; u < V; u++)
        if (!visited[u]) // Don't recur for u if it is already visited
          if (isCyclicUtil(u, visited, -1))
             return true;
 
    return false;
}
 

/*
 *  A recursive function to print BFS starting from s
 */
void Graph::BFS(int s, bool visited[])
{
    list<int> q;
    list<int>::iterator i;
    visited[s] = true;
    q.push_back(s);
    while (!q.empty())
    {
        s = q.front();
        q.pop_front();
        for(i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                q.push_back(*i);
            }
        }
    }
}
/*
 * Function that returns reverse (or transpose) of this graph
 */
Graph Graph::getTranspose()
{
    Graph g(V);
    for (int v = 1; v <= V; v++)
    {
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            g.adj[*i].push_back(v);
        }
    }
    return g;
}
/*
 * Check if Graph is Connected
 */
bool Graph::isConnected()
{
    bool visited[V];
    for (int i = 1; i <= V; i++)
        visited[i] = false;
    BFS(1, visited);
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            return false;
    Graph gr = getTranspose();
    for(int i = 0; i < V; i++)
        visited[i] = false;
    gr.BFS(0, visited);
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            return false;
    return true;
}

// Driver program to test above functions
int main()
{
    Graph g1(10);
    g1.addEdge(2, 1);
    g1.addEdge(8, 1);
    g1.addEdge(5, 1);
    g1.addEdge(10, 2);
    g1.addEdge(6, 2);
    g1.addEdge(9, 5);
    g1.addEdge(6, 10);
    g1.addEdge(3, 10);
    g1.addEdge(4, 6);
    g1.addEdge(7, 8);
    g1.isCyclic()? cout << "Graph contains cycle\n":
                   cout << "Graph doesn't contain cycle\n";

    if (g1.isConnected())
        cout<<"The Graph is Connected"<<endl;
    else
        cout<<"The Graph is not Connected"<<endl;                   
 
    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.isCyclic()? cout << "Graph contains cycle\n":
                   cout << "Graph doesn't contain cycle\n";
 
    return 0;
}