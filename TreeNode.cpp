/** @file TreeNode.cpp
 @brief This file contains the declarations of the TreeNode class
 */

#include "TreeNode.h"

/** Uses the properties of the BinarySearchTree (left child is smaller, right child is larger) to determine recursively where the new node should be inserted 
 @param new_node is a pointer to the TreeNode object being inserted into the BinarySearchTree
 */
void TreeNode::insert_node(TreeNode* new_node) {
    //if new_node data is smaller than current node data, go left
    if(new_node->data < data) {
        //if left of current node is equal to nullptr, set that location to new_node
        if(left == nullptr) {
            left = new_node;
            left->node_parent = this;
        }
        //call insert_node recursively to further cycle through BinarySearchTree until the correct position is found
        else {
            left->insert_node(new_node);
        }
    }
    //if new_node int data is larger that current node data must continue to the right
    else if(data < new_node->data) {
        //if right of current node is equal to nullptr, set that location to new_node
        if(right == nullptr) {
            right = new_node;
            right->node_parent = this;
        }
        //call insert_node recursively to further cycle through BinarySearchTree until the correct position is found
        else {
            right->insert_node(new_node);
        }
    }
    //if there is already a TreeNode with the same int value as the new_node, do not add
    else {
        return;
    }
}

/** Uses the properties of the BinarySearchTree to determine recursively whether the TreeNode of a certain int value exists within the BinarySearchTree
 @returns bool value of 0 if TreeNode of input value is not in the BinarySearchTree and 1 if the value is in the BinarySearchTree
*/
bool TreeNode::find(int value) const {
    //if input value is smaller than current node data, go left
    if(value < data) {
        //if left of current node is equal to nullptr, cannot continue and return false
        if(left == nullptr) {
            return false;
        }
        //call find recursively to cycle through BinarySearchTree and search for TreeNode
        else {
            return left->find(value);
        }
    }
    // if input value is larger than current node data, go right
    if(data < value) {
        //if right of current node is equal to nullptr, cannot continue and return false
        if(right == nullptr) {
            return false;
        }
        //call find recursively to cycle through BinarySearchTree and search for TreeNode
        else {
            return right->find(value);
        }
    }
    //if data==value, return true
    else {
        return true;
    }
}

/** Recursively goes through BinarySearchTree and prints out all int values of the TreeNodes
 */
void TreeNode::print_nodes() const {
    //if left is not nullptr, go left and print
    if(left != nullptr) {
        left->print_nodes();
    }
    std::cout << data << std::endl;
    //if right is not nullptr, go right and print
    if(right != nullptr) {
        right->print_nodes();
    }
}
