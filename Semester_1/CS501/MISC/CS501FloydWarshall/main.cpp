/* 
 * File:   main.cpp
 * Author: anooptoffy
 *
 * Created on November 26, 2016, 10:12 PM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <climits>
#include <list>

using namespace std;

#define N 4

list<int> pathReturn(int u, int v, int PATH[N][N])
{
    list<int> path;
    if(PATH[u][v] ==  -1)
        return path;
    path.push_back(v);
    while(u != v){
        v = PATH[u][v];
        path.push_back(v);
    }
    return path;
}
/*
 * 
 * Flyod Warshall Algorithms
 * 
 * It is Dynamic programming solution.
 * 
 * 
 */
int main(int argc, char** argv) {
    
    // Distance Matrix and Path Matrix
    int DIS[N][N] = { {0, 3, 6, 15}, { 99999, 0, -2, 15}, {99999, 99999, 0, 2}, {1, 99999, 99999, 0}};
    int PATH[N][N] = {{-1, 0, 0, 0}, {-1, -1, 1, -1} , {-1, -1, -1, 2}, {3, -1, -1, -1} }, i, k, j;
    
    
//    for(i = 0; i < N; i++){
//        for(j = 0; j < N; j++){
//            cout << DIS[i][j] << " ";            
//        }
//        cout << endl;
//    }
//    cout << endl;
    
    // updating the distance and the path matrix
    for(k = 0; k < N; k++){
        for(i = 0; i < N; i++){
            for(j = 0; j < N; j++){
                if(DIS[i][j] >  DIS[i][k] + DIS[k][j]){
                    DIS[i][j] = DIS[i][k] + DIS[k][j];
                    PATH[i][j] = PATH[k][j];
                }
            }
        }
    }
    
//    for(i = 0; i < N; i++){
//        for(j = 0; j < N; j++){
//            cout << DIS[i][j] << " ";            
//        }
//        cout << endl;
//    }
//    cout << endl;
//    
//    
//    for(i = 0; i < N; i++){
//        for(j = 0; j < N; j++){
//            cout << PATH[i][j] << " ";            
//        }
//        cout << endl;
//    }
//    cout << endl;
    
    // Construction of the path
    // finding the shortest path form 0 to 3
    list<int> path = pathReturn(0,3, PATH);
    cout << endl;
    while(!path.empty()){
        cout << path.front() << " ";
        path.pop_front();
    }
    
    return 0;
}

