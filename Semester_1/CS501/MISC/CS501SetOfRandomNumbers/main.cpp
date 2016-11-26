/* 
 * File:   main.cpp
 * Author: anooptoffy
 *
 * Created on October 26, 2016, 7:54 AM
 */

#include <cstdlib>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int r ;
    FILE *fp;
    fp = fopen("input105.txt", "w");
    for(unsigned long int i = 0; i < 100000; i++){        
        r = rand();
        fprintf(fp,"%lld\n",r);
    }
    fclose(fp);
    return 0;
}

