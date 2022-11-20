/*
    @file arrayBST.h
    @author Jenisha Khulal
    @purpose contains declaration of BST methods and data members
*/
#include <iostream>
using namespace std;
#include "BST.h"

#define MAXSIZE 16 // size of array used

class arrayBST : public BST
{
public:
    arrayBST();
    int add(node, int rootIndex = 1);
    bool remove(int, int rootIndex = 1);
    bool search(int, int rootIndex = 1);
    bool isEmpty(int);
    int largest(int);
    int smallest(int);
    bool noChildren(int rootIndex);

    node *array; // array to use as BST

    int leftSubtreeIndex; //
    int rightSubtreeIndex;
};
