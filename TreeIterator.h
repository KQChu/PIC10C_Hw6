/** @file TreeIterator.h
 @brief This file contains the declarations for the TreeIterator class.
 */

#ifndef TREEITERATOR_H
#define TREEITERATOR_H

#include "TreeNode.h"

/** @class TreeIterator
 @brief The TreeIterator class is designed to be a bidirectional iterator used in the BinarySearchTree class.  Each TreeIterator object contains a TreeNode pointer and a BinarySearchTree.  The ++/-- (both prefix and postfix), ==, !=, and *(returns a reference) operators have been overloaded.
 */
class TreeIterator {
public:
    TreeIterator();
    void swap(TreeIterator& other);
    TreeIterator& operator=(TreeIterator copy);
    TreeIterator& operator++();
    TreeIterator operator++(int unused);
    TreeIterator& operator--();
    TreeIterator operator--(int unused);
    bool operator==(const TreeIterator& rhs);
    bool operator!=(const TreeIterator& rhs);
    int& operator*();
    
    /** Virtual destructor for the TreeIterator class, empty
     */
    virtual ~TreeIterator() {};
private:
    TreeNode* node_pointer;
    BinarySearchTree* container;
    friend class BinarySearchTree;
};


#endif
#pragma once
