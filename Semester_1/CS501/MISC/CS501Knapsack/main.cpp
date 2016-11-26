/* 
 * File:   main.cpp
 * Author: anooptoffy
 *
 * Created on November 21, 2016, 6:02 PM
 * 
 * Dynamic Programming
 * 
 * 0-1 Knapsack 
 * Exercise 16.2
 * 
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <string>

using namespace std;

int knapsack(int W, int weights[], int profit[], int N) {
    int dp[N + 1][W + 1];

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (weights[i - 1] <= j) {
                dp[i][j] = max(profit[i - 1] + dp[i - 1][j - weights[i - 1]], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[N][W];
}

/*
 * 
 */
int main(int argc, char** argv) {
    int profit[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int W = 50;
    int n = sizeof (profit) / sizeof (profit[0]);
    printf("Knapsack sol : %d ", knapsack(W, weights, profit, n));
    return 0;
}

