/* 
 * File:   main.cpp
 * Author: Anoop Toffy
 *
 * Created on October 24, 2016, 8:43 PM
 */

/*
 * Linked List
 * 
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

struct node {
    int data;
    struct node *next;
};

struct node* CreateNode(){
    return (struct node *)malloc(sizeof(struct node));
}

void printList(struct node *t){
    struct node *temp = NULL;
    temp = t;
    cout << endl;
    cout << "The number of nodes in the LinkedList is : " << temp->data << endl;
    temp = temp->next;
    if( temp == NULL){
        cout << "List is empty!!";
        return;
    }
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

/*
 * 1. Basic linked list structure
 * 1.1 Creation of head node.
 * 2. Insertion 
 * 2.1 Insertion after head node.
 * 3. Traversal of Linked List
 * 
 * NOTE :
 *  In the above implementation the data field of the head node stores the cout of nodes present in the linked list.
 *  Improvements!!
 * 1. Make the List store all types of data.
 *      ie. Make the list Generic.
 * 
 */
int main(int argc, char** argv) {
    
    int num;
    struct node *head = NULL, *history = NULL; // created a head node pointing to NULL
    
    
    cout << "\nEnter the numbers to be inserted in to the Linked List, 0 to exit! \n:";
    while(true){ // Insert 1000 to exit
        
        struct node *temp = NULL;
        temp = CreateNode();
        
        cin >> num;
        if(num == 0) break; // exit condition
        
        if(head == NULL){ // when list is pointing to NULL
            head = CreateNode();
            head->data = 0;
            head->next = NULL;
            temp->data = num;
            temp->next = NULL;
            head->next = temp;
            head->data++;
            history = head;
            history = history->next;
        }
        else // when List is not empty
        {
            head->data++;
            temp->data = num;
            temp->next = NULL;
            history->next = temp;
            history = history->next;
        }
        printList(head);
    }
    
    
    
    return 0;
}

