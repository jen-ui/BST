/*
    @file arrayBST.h
    @author Jenisha Khulal
    @purpose contains declaration of BST methods and data members
*/
#include <iostream>
using namespace std;
#include "BST.h"

#define MAXSIZE 16

class arrayBST:public BST{
    public:
        arrayBST();
        int add(node,int rootIndex=1);//returns the index of array where data has been inserted
        bool remove(int,int rootIndex=1);
        bool search(int,int rootIndex=1);//returns true if the data is found, false if not found
        bool isEmpty(int); // returns true if the passed arrayIndex is empty
        int largest(int);
        int smallest(int);

        node *array;//array to use as BST
        
        int leftSubtreeIndex;//
        int rightSubtreeIndex;
        //int arrayIndex;//used as "n" to assign left and right subtree when a temp root is created
};

