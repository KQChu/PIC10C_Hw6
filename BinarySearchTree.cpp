/** @file BinarySearchTree.cpp
    @brief This file contains the definitions for the BinarySearchTree class
 */

#include "BinarySearchTree.h"

/** Default constructor that sets the root node of the binary search tree to nullptr
 */
BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

/** Overloaded the copy constructor to make a deep copy of the BinarySearchTree object. The constructor uses the copy_node function which sets the left and right children and  the recursive set_parent function to update the parent node pointers.
 @param copy is a const reference of the BinarySearchTree object that is being copied
 */
BinarySearchTree::BinarySearchTree(const BinarySearchTree& copy) {
    root = node_copy(copy.root);
    root->node_parent = nullptr;
    set_parent(root);
}

/** Creates a deep copy of a TreeNode object starting from the input pointer.  Recursion is used to cycle through all the left and right children to set them in the new TreeNode object.
 @param copy is a const pointer to the TreeNode object being copied
 @returns a pointer to the TreeNode object with all left and right children copied that was created
 */
TreeNode* BinarySearchTree::node_copy(const TreeNode* copy) {
    //if input is nullptr cannot set left and right children and instead returns nullptr
    if(copy == nullptr) {
        return nullptr;
    }
    TreeNode* new_node = nullptr;
    //try to allocate heap memory
    try {
        new_node = new TreeNode;
    }
    //if cannot allocate heap memory, print out error statement and set pointer to nullptr
    catch (std::exception& e) {
        std::cerr << "BinarySearchTree::node_copy(const TreeNode* copy) failed to allocate heap memory." << std::endl;
        new_node = nullptr;
    }
    new_node->data = copy->data;
    //recursively calls the node_copy function on the left and right children
    new_node->left = node_copy(copy->left);
    new_node->right = node_copy(copy->right);
    return new_node;
}

/** Recursively cycles through all the left and right children setting their node_parent as the TreeNode before
 @param child is a pointer to the TreeNode object being cycled through and having each parent TreeNode set
 */
void BinarySearchTree::set_parent(TreeNode* child) {
    //if TreeNode pointer is nullptr, then cannot continue to set node_parent in that direction
    if(child == nullptr) {
        return;
    }
    //if left child is not nullptr, continue in the left direction
    if(child->left != nullptr) {
        child->left->node_parent = child;
        set_parent(child->left);
    }
    //if right child is not nullptr, continue in the right direction
    if(child->right != nullptr) {
        child->right->node_parent = child;
        set_parent(child->right);
    }
}

/** Swap function exchanges pointers between the called BinarySearchTree object and other.
 @param other is the BinarySearchTree object whose root pointer is being swapped
 */
void BinarySearchTree::swap(BinarySearchTree& other) {
    std::swap(root, other.root);
}

/** Overload operator= to use copy and swap idiom to make a deep copy of the BinarySearchTree copy.
 @oaram copy is a copy of the BinarySearchTree object being assigned
 @returns a reference to the BinarySearchTree object that was assigned (through swap) the values of copy
 */
BinarySearchTree& BinarySearchTree::operator=(BinarySearchTree copy) {
    copy.swap(*this);
    return *this;
}

/** Print function recursively calls print_nodes() TreeNode function
 */
void BinarySearchTree::print() const {
    //if root is not nullptr, call print_nodes() function
    if(root != nullptr) {
        root->print_nodes();
    }
}

/** Insert a new TreeNode containing input data into the BinarySearchTree.  Use insert_node(TreeNode* new_node) TreeNode function on TreeNode pointer created to recursively find location
 @param data is the int value of the new TreeNode being added
 */
void BinarySearchTree::insert(int data) {
    int in_tree = count(data);
    if(in_tree == 1) {
        return;
    }
    
    TreeNode* new_node = nullptr;
    //try to allocate heap memory safely
    try {
        new_node = new TreeNode;
    }
    //if cannot allocate heap memory, then print error statement and set pointer to nullptr
    catch(std::exception& e) {
        std::cerr << "BinarySearchTree::insert(int data) failed to allocate heap memory." << std::endl;
        new_node = nullptr;
    }
    new_node->data = data;
    new_node->left = nullptr;
    new_node->right = nullptr;
    new_node->node_parent = nullptr;
    
    //if the BinarySearchTree root is nullptr then set new_node to root
    if(root == nullptr) {
        root =  new_node;
    }
    else {
        root->insert_node(new_node);
    }
}

/** Counts the number of times the data value is in the BinarySearchTree by using the find(int value) TreeNode recursively to cycle through the BinarySearchTree.
 @param data is the int value that is being looked for
 @returns an int 0 or 1 whether or not the input data has been found
 */
int BinarySearchTree::count(int data) const {
    //if root is nullptr then data is not in BinarySearchTree
    if(root == nullptr) {
        return 0;
    }
    //calls find function recursively to search whether data is in BinarySearchTree
    else if(root->find(data)) {
        return 1;
    }
    //data is not in BinarySearchTree
    else {
        return 0;
    }
}

/** If input value exists in the BinarySearchTree object, remove that TreeNode and connect appropriate pointers.  For TreeNodes with two children, use the largest child of left subtree and update node_parent.
 @param data is the int value of the TreeNode being removed
 */
void BinarySearchTree::erase(int data) {
    //find node that is going to be removed
    TreeNode* to_be_removed = root;
    TreeNode* parent = nullptr;
    bool found = false;
    //loop through BinarySearchTree as long as data has not been found and nullptr not reached
    while((!found) && (to_be_removed != nullptr)) {
        //if data is larger update TreeNode pointers to go to the right
        if(to_be_removed->data < data) {
            parent = to_be_removed;
            to_be_removed = to_be_removed->right;
        }
        //if data is smaller update TreeNode pointers to go to the left
        if(to_be_removed->data > data) {
            parent = to_be_removed;
            to_be_removed = to_be_removed->left;
        }
        //else data is equal and found is set to true
        else {
            found = true;
        }
    }
    
    if(!found) {
        return;
    }
    
    //to_be_removed contains data, if one of the children is empty, use the other
    if((to_be_removed->left = nullptr) || (to_be_removed->right = nullptr)) {
        TreeNode* new_child;
        //if left is nullptr and right is not, can only be in right, set new_child to to_be_removed->right
        if((to_be_removed->left == nullptr) && (to_be_removed->right != nullptr)) {
            new_child = to_be_removed->right;
            delete to_be_removed;
        }
        //if right is nullptr and left is not, children can only exist in the left, set new_child to to_be_removed->left
        else if((to_be_removed->right == nullptr) && (to_be_removed->left != nullptr)) {
            new_child = to_be_removed->left;
            delete to_be_removed;
        }
        //else both left and right are nullptr to_be_removed is end TreeNode
        else {
            new_child = nullptr;
            //if the left child is being removed, set it to nullptr
            if(parent->left == to_be_removed) {
                parent->left = new_child;
                delete to_be_removed;
            }
            //else right child is being removed, set it to nullptr
            else {
                parent->right = new_child;
                delete to_be_removed;
            }
            return;
        }
        //found in root
        if(parent == nullptr) {
            root = new_child;
        }
        //if left child is being removed, set it to new_child and update node_parent
        else if(parent->left == to_be_removed) {
            parent->left = new_child;
            parent->left->node_parent = parent;
        }
        //if right child is being removed, set it to new_child and update node_parent
        else {
            parent->right = new_child;
            parent->right->node_parent = parent;
        }
        return;
    }
    //neither subtree is empty, find largest element of left subtree
    TreeNode* largest_parent = to_be_removed;
    TreeNode* largest = to_be_removed->left;
    //cycle though the right to find largest value until reach nullptr
    while(largest->right != nullptr) {
        largest_parent = largest;
        largest = largest_parent->right;
    }
    //largest contains largest child in left subtree, move the content and unlink child
    to_be_removed->data = largest->data;
    //if largest parent is being removed, set its left to largest->left
    if(largest_parent == to_be_removed) {
        largest_parent->left = largest->left;
        delete largest;
    }
    //if largest parent is not removed, set its right to largest->left
    else {
        largest_parent->right = largest->left;
        delete largest;
    }
}

/** Determines the smallest int value contained within the BinarySearchTree
 @returns the int value of the smallest TreeNode
 */
int BinarySearchTree::smallest() {
    TreeNode* smallest_value = root;
    //cycles through BinarySearchTree to the left until it reaches the smallest value
    while(smallest_value->left != nullptr) {
        smallest_value = smallest_value->left;
    }
    return smallest_value->data;
}

/** Determines the largest int value conained within the BinarySearchTree
 @returns the int value of the largest TreeNode
 */
int BinarySearchTree::largest() {
    TreeNode* largest_value = root;
    //cycles through BinarySearchTree to the right until it reaches the largest value
    while(largest_value != nullptr) {
        largest_value = largest_value->right;
    }
    return largest_value->data;
}

/** Creates a TreeIterator object that points to the first (smallest) TreeNode in the BinarySearchTree
 @returns a TreeIterator object that points to the first TreeNode in the BinarySearchTree
 */
TreeIterator BinarySearchTree::begin() {
    TreeIterator begin;
    begin.container = this;
    TreeNode* smallest_value = root;
    //cycles through BinarySearchTree to the left until it reaches the smallest value
    while(smallest_value->left != nullptr) {
        smallest_value = smallest_value->left;
    }
    begin.node_pointer = smallest_value;
    return begin;
}

/** Creates a TreeIterator object that points to the last (one past the largest) TreeNode in the BinarySearchTree
 @returns a TreeIterator object that points to the last TreeNode in the BinarySearchTree
 */
TreeIterator BinarySearchTree::end() {
    TreeIterator end;
    end.container = this;
    TreeNode* largest_value = root;
    //cycles through BinarySearchTree to the right until it reaches the largest value
    while(largest_value->right != nullptr) {
        largest_value = largest_value->right;
    }
    largest_value = largest_value->right;
    end.node_pointer = largest_value;
    return end;
}

/** Cycles through TreeNodes of a BinarySearchTree and calls delete recursively.
 @param node is a pointer to the TreeNode whose children are being cycled through and deleted
 */
void BinarySearchTree::recursive_destructor(TreeNode* node) {
    //if TreeNode pointer is nullptr, cannot continue using recursive_destructor in that direction
    if(node == nullptr) {
        return;
    }
    recursive_destructor(node->left);
    recursive_destructor(node->right);
    delete node;
}





