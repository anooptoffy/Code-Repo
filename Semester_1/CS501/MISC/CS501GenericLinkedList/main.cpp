/* 
 * File:   main.cpp
 * Author: Anoop Toffy
 *
 * Created on October 25, 2016, 8:59 AM
 */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


struct node {
    void *data; // It points to address of any type of data.
    struct node *next;
};

struct node* createNode();
void printList(struct node *temp, void (*fptr)(void *));
void insertNode(struct node** head, void *data, size_t data_s);
void printIntegers(void *data);
void printFloats(void *data);
void printChars(void *data);

struct node* createNode(){
    return (struct node *)malloc(sizeof(struct node));
}

/*
 * Insertion can be done either in the forward direction or in the backward
 * direction. It is up to the programmer.
 * 
 * Visit geeksforgeeks for insertion to be done in the backward direction.
 * In this case we read the numbers to be inserted in the backward direction from the end of the given stream.
 * 
 * Assumption :
 * Deallocation is not done. Since we are not deleting nodes in between, after termination memories are freed.
 * 
 */
void insertNode(struct node** head, void *data, size_t data_s){
    struct node *temp;
    if((*head) ==  NULL){
        (*head) = createNode();
        (*head)->data = malloc(sizeof(int));
        static int zero = 0;
        for(int i = 0; i < sizeof(int); i++){
            *(char *)((*head)->data + i) = *(char *)(&zero + i); 
            // we are reading each character at a time, since we don't know what type of data is being held in the memory.
        }
        (*head)->next = NULL;
        temp = createNode();
        temp->data = malloc(data_s);
        for(int i = 0; i < data_s; i++){
            *(char *)((temp)->data + i) = *(char *)(data + i);
        }
        temp->next = (*head);
        (*head) = temp;
    }else{
        temp = createNode();
        temp->data = malloc(data_s);
        for(int i = 0; i < data_s; i++){
            *(char *)((temp)->data + i) = *(char *)(data + i);
        }
        temp->next = (*head);
        (*head) = temp;
    }
}

void printList(struct node *temp, void (*fptr)(void *)){
    struct node *t;
    t = temp;
    while(t != NULL){
        (*fptr)(t->data);
        t = t->next;
    }
}

void printIntegers(void *data){
    printf("%d ", *(int*)data);
}

void printFloats(void *data){
    printf("%f ", *(float *)data);
}

void printChars(void *data){
    printf("%c ", *(char *)data);
}
/*
 *  Creating a Generic Linked List.
 * 
 *  Since we are using C, Generic support can be obtained using void pointer (void *)
 *  1. Insertion
 *  2. Traversal 
 *  
 */
int main(int argc, char** argv) {
    struct node *head = NULL, *history = NULL;
    
    int num;
    char ch;
    float fp;
    int type;
    enum flag {integer, floating, string}; // Type of Generic Linked List
    
    unsigned  intSize = sizeof(int);
    unsigned  floatSize = sizeof(float);
    unsigned  charSize = sizeof(char);
    
    
    printf("Enter the Type of Linked List to be created 0-int,1-float,2-string:\t");
    scanf("%d", &type);
    printf("Enter the nodes to be inserted in to LinkedList (0 for stopping in int, 0.0 for string in float, a for stopping in string) :\n");
    while(true){
        
        switch(type){
            case 1:
                scanf("\n%f", &fp);
                if(fp == 0.1f) exit(0); // http://www.geeksforgeeks.org/comparison-float-value-c/
                insertNode(&head,&fp,floatSize);
                printList(head, printFloats);
                break;
            case 2:
                // Reminder : Put & for characters.
                scanf("\n%c", &ch); // http://stackoverflow.com/questions/3911653/comparing-user-inputted-characters-in-c
                if(ch == 'q') exit(0);
                insertNode(&head,&ch,charSize);
                printList(head, printChars);
                break;
            default : // Integer data stored in Linked List!
                scanf("\n%d", &num);
                if(num == 0) exit(0); // Using exit to terminate the programs.
                insertNode(&head,&num,intSize);
                printList(head, printIntegers);
                break;
        }
    }
    
    return 0;
}

