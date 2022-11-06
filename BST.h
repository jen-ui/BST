#include <iostream>
using namespace std;

// interface class

class BST
{
public:
    virtual void add(int) = 0;
    virtual void remove(int) = 0;
    virtual bool search(int) = 0;
    virtual bool isEmpty() = 0;
};