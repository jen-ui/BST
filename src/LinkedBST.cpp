/*
    @file linkedBST.cpp
    @author Simran Mahat
    @purpose contains funtion definition of the BST methods declared in the file linkedBST.h
*/

#include "linkedBST.h"
#include <stdio.h>
#include <iostream>
using namespace std;

/*
    this funtion checks if the root of tree or subtree is empty
    @param  root to be checked
    @return true if the root is empty
*/

bool linkedBST ::isEmpty()
{
  return root == nullptr;
}

/*
    This function adds newnode to the BST
    @param newNode node to be added
*/
void linkedBST::addBST(int key, int data)
{
  node *newNode = new Node(key, data);
  node *temp = root;
  node *ptr = nullptr;
  while (temp != nullptr)
  {
    ptr = temp;
    if (key > temp->data)
    {
      temp = temp->right;
    }
    else
    {
      temp = temp->left;
    }
  }
  if (ptr == nullptr)
  {
    root = newNode;
  }
  else if (key < ptr->data)
  {
    ptr->left = newNode;
  }
  else
  {
    ptr->right = newNode;
  }
}

/*
    This function seraches for a given key in binary search tree
    @param key key to be searched
    @return true if the key is found
*/

bool linkedBST ::searchBST(int targetKey)
{
  node *temp = root;
  while (temp != nullptr)
  {
    if (temp->data > targetKey)
    {
      temp = temp->left;
    }
    else if (temp->data < targetKey)
    {
      temp = temp->right;
    }
    else
    {
      return true;
    }
  }
  return false;
}
node *minValueNode(node *node)
{
  node *current = Node;
  while (current->left != nullptr)
  {
    current = current->left;
  }
  return current;
}
node *linkedBST ::removeBST(node *root, int keyToDelete)
{
  if (root == nullptr)
  {
    return root;
  }
  else if (keyToDelete < root->data)
  {
    root->left = removeBST(root->left, keyToDelete);
  }
  else if (keyToDelete > root->data)
  {
    root->right = removeBST(root->right, keyToDelete);
  }
  else
  {
    if (root->left == nullptr)
    {
      node *temp = root->right;
      delete root;
      return temp;
    }
    else if (root->right == nullptr)
    {
      node *temp = root->left;
      delete root;
      return temp;
    }
    else
    {
      node *temp = minValueNode(root->right);
      root->data = temp->data;
      root->right = removeBST(root->right, temp->data);
    }
  }
  return root;
}


/*
    This function prints all element  in binary search tree
*/
void linkedBST ::traverse(node *root)
{
  if (root == nullptr)
  {
    return;
  }
  traverse(root->left);
  cout << root->data << "  ";
  traverse(root->right);
  cout << endl;
}