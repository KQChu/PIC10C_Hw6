/** @file TreeNode.h
@brief This file contains the declarations for the TreeNode class
 */

#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>

/** @class TreeNode
 @brief The TreeNode class creates the nodes that will be connected to form the BinarySearchTree.  Each node contains an int data value and pointers to the left child, right child, and parent nodes.  The insert_node, find, and print_nodes all use recursion to perform there neccessary operations.
 */
class TreeNode {
public:
    void insert_node(TreeNode* new_node);
    void print_nodes() const;
    bool find(int value) const;
    
    /** Virtual destructor for the TreeNode class, should be empty
     */
    virtual ~TreeNode() {};
private:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode* node_parent;
    friend class BinarySearchTree;
    friend class TreeIterator;
};

#endif
#pragma once
