/** @file TreeIterator.cpp
 @brief This file contains the definitions for the TreeIterator class
 */

#include "TreeIterator.h"
#include "BinarySearchTree.h"
#include "TreeNode.h"

/** Default constructor for TreeIterator class which sets node_pointer and container to nullptr
 */
TreeIterator::TreeIterator() : node_pointer(nullptr), container(nullptr) {
    
}

/** Swap function swaps pointers between the called TreeIterator and other
 @param other is the TreeIterator object whose node_pointer and container and are being swapped
*/
void TreeIterator::swap(TreeIterator& other) {
    std::swap(node_pointer, other.node_pointer);
    std::swap(container, other.container);
}

/** Overload operator= to swap copy of the TreeIterator input
 @param copy is a copy of the TreeIterator object being assigned
 @returns a reference to the TreeIterator object that was assigned the values of copy
*/
TreeIterator& TreeIterator::operator=(TreeIterator copy) {
    copy.swap(*this);
    return *this;
}

/** Overload prefix operator++ which moves TreeIterator to the TreeIterator with the next largest int data
 @returns a reference to the TreeIterator that has the next largest int data
*/
TreeIterator& TreeIterator::operator++() {
    //if there is a TreeNode to the right, go right
    if(node_pointer->right != nullptr) {
        node_pointer = node_pointer->right;
        //cycle node_pointer to the very left TreeNode
        while(node_pointer->left != nullptr) {
            node_pointer = node_pointer->left;
        }
    }
    //if there is a TreeNode to the left, go back
    else {
        TreeNode* store = nullptr;
        store = node_pointer->node_parent;
        //cycle until node_parent is nullptr or reach left child
        while(store != nullptr && node_pointer == store->right) {
            node_pointer = store;
            store = store->node_parent;
        }
        node_pointer = store;
    }
    return *this;
}

/** Overlaod postfix operator++ which increments the TreeIterator object and returns an unincremented copy
 @returns an unincremented copy of the TreeIterator object
*/
TreeIterator TreeIterator::operator++(int unused) {
    TreeIterator copy = *this;
    ++(*this);
    return copy;
}

/** Overload prefix operator-- which decrements the TreeIterator object to a TreeIterator object with the next smallest int data
 @returns a reference to the TreeIterator that has the next smallest int data
*/
TreeIterator& TreeIterator::operator--() {
    //if node_pointer is nullptr, then currently at one past the last TreeIterator
    if(node_pointer == nullptr) {
        node_pointer = container->root;
        //sets node_pointer to largest value
        while(node_pointer != nullptr) {
            node_pointer = node_pointer->right;
        }
        return *this;
    }
    //if there is a TreeNode to the left, go left
    if(node_pointer->left != nullptr) {
        node_pointer = node_pointer->left;
        //cycle node_pointer to the very right TreeNode of the left subtree
        while(node_pointer->right != nullptr) {
            node_pointer = node_pointer->right;
        }
    }
    //if there is a TreeNode to the right, go back
    else {
        TreeNode* store = nullptr;
        store = node_pointer->node_parent;
        //cycle until node_parent is nullptr or reach right child
        while(store != nullptr && node_pointer == store->left) {
            node_pointer = store;
            store = store->node_parent;
        }
        node_pointer = store;
    }
    return *this;
}

/** Overload postfix operator-- which decrements the TreeIterator object and returns an unincremented copy
 @returns an unincremented copy of the TreeIterator object
 */
TreeIterator TreeIterator::operator--(int unused) {
    TreeIterator copy = *this;
    --(*this);
    return copy;
}

/** Overload comparison operator== to compare if two int values of two TreeIterators are equal
 @param rhs is a const reference of the TreeIterator on the right of the == operator that is being compared
 @returns a bool value determining if the two int values of the TreeIterators are equal
 */
bool TreeIterator::operator==(const TreeIterator& rhs) {
    return ((this->node_pointer) == (rhs.node_pointer));
}

/** Overload comparison operator!= to compare if two int values of two TreeIterators are unequal
 @param rhs is the const reference of the TreeITerator on the right of the != operator that is being compared
 @returns a bool value determining if the two int values of the TreeITerators are unequal
 */
bool TreeIterator::operator!=(const TreeIterator& rhs) {
    return !(*this == rhs);
}

/** Overload operator* to dereference TreeIterator
 @returns an int reference to the int data value of the node_pointer
 */
int& TreeIterator::operator*() {
    return (this->node_pointer->data);
}

