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

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    srand(time(NULL));
    int r = rand();
    cout << r;
    return 0;
}

