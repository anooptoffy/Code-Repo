/* 
 * File:   main.cpp
 * Author: Anoop Toffy
 *
 * Created on November 25, 2016, 4:47 PM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <climits>
#include <cstring>

using namespace std;

/*
 * Minimum Edit Distance Problem using DP
 * 
 * Minimum operations to convert a string X to a string Y.
 * 
 * Operations :
 * * replace/substitution 
 * * add
 * * delete
 * 
 */
int main(int argc, char** argv) {
    char str1[] = "azced";
    char str2[] = "abcdef";
    
    int len1, len2;
    len1 = strlen(str1);
    len2 = strlen(str2);
    
    int dp[len1+1][len2+1];
    
    dp[0][0] = 0;
    for(int i = 1; i <= len1; i++){
        dp[i][0] = i;
    }
    
    for(int j = 1; j <= len2; j++){
        dp[0][j] = j;
    }
    
    for(int i = 1; i <= len1; i++){
        for(int j = 1; j <= len2; j++){
            int val1 = dp[i-1][j];
            int val2 = dp[i][j-1];
            int val3 = dp[i-1][j-1];
            
            int min = (val1 <= val2) ? ((val1 <= val3) ? val1 : val3) : ((val2 <= val3) ? val2 : val3);
            if(str1[i] != str2[j])
                dp[i][j] = min + 1;          
            else
                dp[i][j] = dp[i-1][j-1];
        }
    }
    
    cout << "Minimum Edit Distance is : " << dp[len1][len2] << endl;
    
    for(int i = 0; i <= len1; i++){
        
        for(int j = 0; j <= len2; j++)
        {
            cout << dp[i][j] << " ";
        }
        
        cout << endl;
    }
    
    return 0;
}

