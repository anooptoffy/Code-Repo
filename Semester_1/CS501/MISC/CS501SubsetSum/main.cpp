/* 
 * File:   main.cpp
 * Author: anooptoffy
 *
 * Created on November 25, 2016, 11:14 AM
 * 
 * Dynamic Programming Solution for Subset Sum problem.
 * 
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <climits>

using namespace std;

/*
 * The Subset Sum Problem
 * 
 * An instance of subset sum problem is a pair of (S,t) where S is a set {x1, x2,..., sn}
 * of positive integers and t is a positive integer. 
 * 
 * It is a Decision Problem.
 * It is NP-Complete.
 * 
 * Whether or not a subset of S adds up to exactly to the target value of t.
 * 
 */

/*
 * 
 * This function returns 0/1 if the sum is possible with any one subset of S.
 * 
 */
bool SubSetSum(int S[], int t, int N){
    bool dp[N+1][t+1];    
    
    if(t == 0 || N == 0)
        return false;
        
    
    for(int j = 0; j < N; j++)
        dp[j][0] = true;
    
    for(int j = 0; j < N; j++)
    {
        for(int i = 1; i <= t; i++)
        {
            if(j == 0){
                if(i == S[j])
                    dp[j][i] = true;
                else
                    dp[j][i] = false;
            }
            else if(dp[j-1][i - S[j]] ==  true)
            {
                dp[j][i] = true;
            }
            else
                dp[j][i] = false;
                
        }
    }
    
    return dp[N-1][t];
}

/*
 * 
 *  It is a decision problem.
 * 
 * The numbers are all positive .
 * 
  */
int main() {
    int a[] = {2, 3, 7, 8, 10};
    int t = 11;
    int N;
    N = sizeof(a)/sizeof(a[0]);
    
    bool flag;
    flag = SubSetSum(a,t,N);
    if(flag == 1){
        cout << "Yes. A sum of " << t << " is possible with a subset of S" << endl;
    }
    else
    {
        cout << "No. A sum of " << t << " is not possible with any subset of S" << endl;
    }
    
    return 0;
}

