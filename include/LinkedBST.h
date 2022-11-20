/*
    @author Simran Mahat
    @file linkedBST.h
    @purpose contains declaration of BST methods and data members
   
*/


#pragma once
#include "BST.h"
class linkedBST
{

public:
    node *root;
    linkedBST()
    {
        root = nullptr;
    }
    bool isEmpty();
    void addBST(int key, int data);
    bool searchBST(int targetKey);
    node *removeBST(node *root, int keyToDelete);
    void traverse(node *root);
};
