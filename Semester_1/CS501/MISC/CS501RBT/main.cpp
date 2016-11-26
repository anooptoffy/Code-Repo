/* 
 * File:   main.cpp
 * Author: anooptoffy
 *
 * Created on October 25, 2016, 10:26 AM
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <iostream>

using namespace std;

// RB Tree node structure.
struct node {
    int data;
    bool color;
    struct node *left, *right, *parent;
};


struct node* createNodeRBT(){
    return (struct node *)malloc(sizeof(struct node));
}
/*
 * 
 */
int main(int argc, char** argv) {
    
    return 0;
}

