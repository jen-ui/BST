/*
    @file BST.h
    @author Jenisha Khulal
    @purpose contains class definition for BST and nodes of BST
*/

#include <iostream>
using namespace std;

// class node for nodes of BST
class node
{
public:
    node();
    ~node();
    node(int, string);
    int key;
    string value;
};
// interface class for BST
class BST
{
public:
    virtual int add(node, int) = 0;
    virtual bool remove(int, int) = 0;
    virtual bool search(int, int) = 0;
    virtual bool isEmpty(int) = 0;
    virtual int largest(int) = 0;
    virtual int smallest(int) = 0;
    
};