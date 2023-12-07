//
// Created by asus on 12/8/2023.
//

#ifndef EXTRA_BST_H
#define EXTRA_BST_H

/*
* Binary search tree
*/
class BST
{
public:
    // destructor
    virtual ~BST() {}
    // inserts "val" into the tree
    virtual void insert(int val) = 0;
    // returns true if and only if "val" exists in the tree.
    virtual bool find(int val) const = 0;
    // prints the tree elements in the in-order traversal order
    virtual void print_inorder() const = 0;
    // prints the tree elements in the pre-order traversal order
    virtual void print_preorder() const = 0;
    // prints the tree elements in the post-order traversal order
    virtual void print_postorder() const = 0;
};


#endif //EXTRA_BST_H
