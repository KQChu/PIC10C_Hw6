/** Name: Kendrick Chu
 UCLA ID: 004136504
 Date: 5/9/16
 @File:  This assignment was used to have us use iterators to modify an existing binary search tree that was provided in the book.  In this assignment, I modified the binary search tree to store an int data value and included functions that would get the smallest and largest value of the binary search tree.  A bidirectional iterator was also implemented containing the functions being(), end(), and appropriate operators overloaded for the iterator.  Parent nodes were added to the TreeNodes and the erase and insert functions were modified.  I also modified the destructor to make sure that my code wouldn't create any memory leaks.
 */

#include <iostream>
#include "TreeNode.h"
#include "BinarySearchTree.h"

int main() {
    
    // Create binary search tree give it values {2,3,5,11,13,17}
    BinarySearchTree bst;
    bst.insert(3);  bst.insert(2);  bst.insert(11);
    bst.insert(13); bst.insert(5);  bst.insert(17);
    
    // Prints to the console: 2,3,5,11,13,17,
    for(auto x : bst)   std::cout << x << ",";
    std::cout << std::endl;
    
    bst.erase(6);   //  {2,3,5,11,13,17}, no effect
    bst.erase(11);  //  {2,3,5,13,17}
    
    auto start = std::begin(bst);
    auto stop = std::end(bst);
    
    int value = 17;
    bool keep_looking = true;
    
    // For a 17 in the list
    while(start != stop && keep_looking)
        if( *start++ == value )
            keep_looking = false;
    --start;
    
    // Prints "17 is in the list."
    if(start != stop) std::cout<<*start<<" is in the list." << std::endl;
    
    // Construct a deep copy of bst.
    BinarySearchTree deep_copy( bst );
    
    deep_copy.insert(11);   deep_copy.insert(7);
    
    // Prints to the console: 2,3,5,7,11,13,17,
    for(auto x : deep_copy) std::cout << x << ",";
    std::cout << std::endl;
    
    return 0;
}
