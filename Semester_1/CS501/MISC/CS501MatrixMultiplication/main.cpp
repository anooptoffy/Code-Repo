/* 
 * File:   main.cpp
 * Author: Anoop Toffy
 *
 * Created on November 25, 2016, 5:31 PM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <climits>

using namespace std;

/*
 * Matrix Chain Multiplication
 * 
 * THis is to optimally multiply matrices. Not really Multiply. 
 * But find an order in which one can multiply matrices with minimum number of 
 * scalar multiplications.
 * 
 */

int MATRIX_CHAIN_ORDER(int P[]){
    int N = sizeof(P)/sizeof(P[0]);    
    N--;    
    int M[N+1][N+1], S[N+1][N+1], L, i, j, k, SUM;
    
    for(i = 1; i <= N; i++)
        M[i][i] = 0;
    
    for(L = 2; L <= N; L++)
    {
        for(i = 1; i <= N - L + 1; i++){
            j = i + L - 1;
            M[i][j] = INT_MAX;
            for(k = i; k <= j -1 ; k++){
                int q = M[i][k] + M[k+1][j] + P[i-1]*P[k]*P[j];
                if(q < M[i][j])
                {
                    M[i][j] =q;
                    S[i][j] =k;
                }
            }
        }
    }
    
    for(i = 0; i <= N; i++){
        for(j = 0; j <= N; j++){
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
    
    return M[1][N-1];
}

int main() {
    int P[] = {1, 2, 3, 4};    
    cout << "The minimum sum is : " << MATRIX_CHAIN_ORDER(P);    
    return 0;
}

