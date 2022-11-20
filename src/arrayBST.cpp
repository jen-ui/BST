/*
    @file arrayBST.cpp
    @author Jenisha Khulal
    @purpose contains funtion definition of the BST methods declared in the file arrayBST.h
*/

#include "arrayBST.h"

// default constructor for class node

node::node()
{
    key = 0;
    value = "/0";
}

// parametarized constructor for class node

node::node(int key, string value)
{
    this->key = key;
    this->value = value;
}

// destructor for class node

node::~node()
{
    key = 0;
    value = "/0";
}

/*
    default constructor for class arrayBST
    initializes an array of object node
*/

arrayBST::arrayBST()
{
    array = new node[MAXSIZE];
}

/*
    this funtion checks if the root of tree or subtree is empty
    @param rootIndex index of root to be checked
    @return true if the root is empty
*/
bool arrayBST::isEmpty(int rootIndex)
{
    if (!array[rootIndex].key || (rootIndex >= MAXSIZE))
    {
        return true;
    }
    else
        return false;
}

/*
    This function adds newnode to the BST
    @param newNode node to be added
    @param rootIndex index of root,1 by default
    @return true if the node is added
*/
int arrayBST::add(node newNode, int rootIndex)
{
    rightSubtreeIndex = rootIndex * 2 + 1;
    leftSubtreeIndex = rootIndex * 2;

    if (isEmpty(rootIndex))
    {

        array[rootIndex] = newNode;
        return rootIndex;
    }
    if (newNode.key > array[rootIndex].key)
    {

        return add(newNode, rightSubtreeIndex);
    }
    else
    {

        return add(newNode, leftSubtreeIndex);
    }
}

/*
    This function seraches for a given key in binary search tree
    @param key key to be searched
    @param rootIndex index of root, 1 by default
    @return true if the key is found
*/
bool arrayBST::search(int key, int rootIndex)
{
    leftSubtreeIndex = rootIndex * 2;
    rightSubtreeIndex = rootIndex * 2 + 1;
    if (isEmpty(rootIndex))
    {
        return false;
    }
    if (key > array[rootIndex].key)
    {

        return search(key, rightSubtreeIndex);
    }
    else if (key < array[rootIndex].key)
    {

        return search(key, leftSubtreeIndex);
    }
    else
    {
        return true;
    }
}

/*
    This function searches for a largest key in the tree or subtree
    @param rootIndex root of tree to be searched
    @return array index of node which has the largest key
*/
int arrayBST::largest(int rootIndex)
{
    rightSubtreeIndex = rootIndex * 2 + 1;
    if (isEmpty(rightSubtreeIndex))
    {
        return rootIndex;
    }
    else
    {

        return largest(rightSubtreeIndex);
    }
}

/*
    This fucntion serches for the smallest key in a tree
    @param rootIndex root of the tree to be searched
    @return array index of node which has the smallest key
*/
int arrayBST::smallest(int rootIndex)
{
    leftSubtreeIndex = 2 * rootIndex;
    if (isEmpty(leftSubtreeIndex))
    {
        return rootIndex;
    }
    else
    {

        return smallest(leftSubtreeIndex);
    }
}

/*
    This function removes a node from the tree
    @param key key to be removed
    @param rootIndex index of root, 1 by default
*/
bool arrayBST::remove(int key, int rootIndex)
{
    rightSubtreeIndex = rootIndex * 2 + 1;
    leftSubtreeIndex = rootIndex * 2;
    if (isEmpty(rootIndex))
    {
        return false;
    }
    if (key > array[rootIndex].key)
    {
        return remove(key, rightSubtreeIndex);
    }
    else if (key < array[rootIndex].key)
    {
        return remove(key, leftSubtreeIndex);
    }
    else
    {

        if (isEmpty(leftSubtreeIndex) && isEmpty(rightSubtreeIndex))
        {
            array[rootIndex].~node();
        }
        else if (isEmpty(leftSubtreeIndex)&& noChildren(rightSubtreeIndex))// this is used only if the node to be deleted has right child only and that rightchild has no children
        {

            array[rootIndex] = array[rightSubtreeIndex];

            return remove(array[rootIndex].key, rightSubtreeIndex);
        }
        else if (isEmpty(rightSubtreeIndex)&&noChildren(leftSubtreeIndex))
        {
            array[rootIndex] = array[leftSubtreeIndex];

            return remove(array[rootIndex].key, leftSubtreeIndex);
        }
        else
        {
            if(!isEmpty(leftSubtreeIndex)){
                int large = largest(leftSubtreeIndex);

                array[rootIndex] = array[large];

                return remove(array[large].key, leftSubtreeIndex);
            }
            else{
                int small = smallest(rightSubtreeIndex);

                array[rootIndex] = array[small];

                return remove(array[small].key, rightSubtreeIndex);
            }
        
        }
    }

}
/*
    this function checks if the given node has any children
    @param rootIndex index of node to be checked
    @return true if the  node has no child
*/
bool arrayBST:: noChildren(int rootIndex){
    int right = rootIndex * 2 + 1;
    int left = rootIndex * 2;
    if(isEmpty(left)&&isEmpty(right)){
        return true;
    }
    else
        return false;
}


