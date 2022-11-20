/*
    @author Jenisha Khulal
    @date 11/20/2022
    @file main.cpp
    @purpose implements the methods included in arrayBST class defined in file arrayBST.cpp
*/

#include <iostream>
using namespace std;
#include "arrayBST.h"

int main()
{
    arrayBST A;

    node x(8, "jen"); // generating a node to add to the binary search tree
    A.add(x);
    node y(3, "ken");
    A.add(y);
    node z(10, "len");
    A.add(z);
    node c(1, "ten");
    A.add(c);
    node a(6, "ldf");
    A.add(a);
    node b(14, "fdf");
    A.add(b);
    node d(4, "dfs");
    node e(7, "dfas");
    node f(13, "afd");
    A.add(d);
    A.add(e);
    A.add(f);

    cout << "\n=>before removing:" << endl;

    for (int i = 0; i < MAXSIZE; i++)
    { // prints the content of binary search tree
        cout << A.array[i].key << "\t";
    }
    cout << "\n\n=>seraching for 14..." << A.search(14) << endl;
    cout << "\n=>searching for 99..." << A.search(99) << endl;

    A.remove(10);

    cout << "\n=>after removing 10:" << endl;
    for (int i = 0; i < MAXSIZE; i++) // prints the content of binary searh tree after removal of a node
    {
        cout << A.array[i].key << "\t";
    }
}