#include <iostream>
#include "BST.h"
#include "LinkedBST.h"

int main(){
     linkedBST B;
         if (B.isEmpty())
            {
                cout << "The tree is empty." << endl;
            }
            else
            {
                cout << "The tree is not empty." << endl;
            }

        B.addBST(-1,20 );
        B.addBST(-1,10);
        B.addBST(-1,50);
        B.addBST(-1, 30);
        B.addBST(-1, 15);
        B.traverse(B.root);
        B.removeBST(B.root,50);
        cout<<"after removing"<<endl;
        B.traverse(B.root);
        if (B.searchBST(60))
            {
                cout << "The node is in the tree." << endl;
            }
            else
            {
                cout << "The node is not in the tree." << endl;
            }
        



}
