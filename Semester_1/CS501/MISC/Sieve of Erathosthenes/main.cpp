/* 
 * SIMPLE SIEVE OF ERATHOSTHENES
 * 
 * File:   main.cpp
 * Author: anooptoffy
 *
 * The Sieve of Erathosthenes.
 * http://www.geeksforgeeks.org/sieve-of-eratosthenes/
 * 
 * 
 * Problems with Simple Sieve:
 * 
 * The Sieve of Eratosthenes looks good, 
 * but consider the situation when n is large, 
 * the Simple Sieve faces following issues.
 * 
 * An array of size Θ(n) may not fit in memory
 * 
 * The simple Sieve is not cache friendly even for slightly bigger n. 
 * The algorithm traverses the array without locality of reference
 * 
 * Created on November 12, 2016, 11:52 AM
 * 
 * O(n log log n)
 * 
 */

#include <cstdlib>
#include <iostream>

using namespace std;

#define LIMIT 100000

/*
 *  Program to find the N primes numbers between 1 and N
 * 
 */
int main() {
    
    long long int i, j, N[LIMIT+1] = {0};
    j = 2;
    while(j*j <= LIMIT){
        if(N[j] == 0){
            N[j*j] = 1;
            for(i = j*j; i <= LIMIT +1 ; i += j)
                N[i] = 1;
        }
        j++;
    }
    
    int count = 0;
    for(i = 2; i <=  LIMIT+1 ; i++){
        if(N[i] == 0){
            cout << i <<  endl;
            count++;
        }
    }
    cout << "Count :" << count << endl;
    return 0;
}

