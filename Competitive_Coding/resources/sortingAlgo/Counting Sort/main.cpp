/* 
 * File:   main.cpp
 * Author: @AnoopToffy
 * Page No: 194 CLRS - Counting Sort
 * Created on 13 August, 2016, 6:58 AM
 */

#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;

ifstream f("data.in");
ofstream g("data.out");

int A[11],B[11],C[11],i,n; // maximum element is 10 in the array,
// Globals are initialized to zero by default,
// A[i] contains the data to be sorted.
// B[i] stores the count.
// C[i] is the temporary array to store the result.
/*
 * Counting Sort
 */
int main(int argc, char** argv) {
    f>>n;
    int maximum;
    for(i = 1; i <= n; i++){
        int x;
        f>>x;
        A[i] = x;
        B[x]++;
    }
    
    for(i = 1; i <= 10 ; i++){
        B[i] = B[i] + B[i-1];
    }
    
    for(i = 10 ;i >= 0;i--){
        C[B[A[i]]] = A[i];
        B[A[i]] = B[A[i]] - 1;
    }
    
    for(i = 1; i<= n; i++)
        g<<C[i]<<" ";
    
    return 0;
}

