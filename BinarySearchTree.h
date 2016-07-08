/** @file BinarySearchTree.h
 @brief This file contained the declarations for the BinarySearchTree class.  Functionality of the code has been extended from the version in the book.
 
 */


#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include "TreeNode.h"
#include "TreeIterator.h"

/** @class BinarySearchTree
    @brief The BinarySearchTree class creates a Binary Search Tree of int values.  The BinarySearchTree class contains a pointer to its root TreeNode object (which has pointers to its left, right, and parent neighbors in the binary search tree).  Functions have been added to add new int values to the tree, delete int values, determine whether an int value is in the tree, and also provides the smallest and largest int values of the BinarySearchTree object.  A copt and swap idiom was implemented to make a deep copy of the binary search tree, and a recursive iterator was used to go through all the TreeNode objects. The BinarySearchTree class has friendship with the TreeIterator class allowing the BinarySearchTree class to access the variables and functions of the TreeIterator class.
 
 */

class BinarySearchTree {
public:
    //Constructors
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree& copy);
    
    //Other functions
    TreeNode* node_copy(const TreeNode* copy);
    void set_parent(TreeNode* child);
    void swap(BinarySearchTree& other);
    BinarySearchTree& operator=(BinarySearchTree copy);
    
    void insert(int data);
    void erase(int data);
    int count(int data) const;
    void print() const;
    int smallest();
    int largest();
    TreeIterator begin();
    TreeIterator end();
    
    void recursive_destructor(TreeNode* node);
    
    /** Virtual destructor for the BinarySearchTree class, calls recursive_destructor function to recursively delete children and root
     */
    virtual ~BinarySearchTree() {
        recursive_destructor(root);
    }
    
private:
    TreeNode* root;
    friend class TreeIterator;
};

#endif
#pragma once
