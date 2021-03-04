#include <stdlib.h>
#include <stdio.h>

#include "binarytree.h"
#include "common.h"

struct tree {
    node_t *root;
    cmpfunc_t cmp;
    size_t size;
};

struct node {
    node_t *left;
    node_t *right;
    void *elem;
};

/*
 * Creates a binary search tree
 */
tree_t *tree_create(cmpfunc_t cmp) {
    /* Allocate memory */
    tree_t *tree = malloc(sizeof(tree_t));
    if (tree == NULL)
        fatal_error("Could not allocate tree");

    /* Assign values */
    tree->root = NULL;
    tree->cmp = cmp;
    tree->size = 0;

    return tree;
}

/*
 * Destroys a given binary tree, freeing the memory used
 */
void tree_destroy(tree_t *tree) {
    free(tree);
    // Also free nodes
}

/*
 * Creates a new node
 */
static node_t *new_node(void *elem) {
    node_t *node = malloc(sizeof(node_t));

    node->elem = elem;
    node->left = NULL;
    node->right = NULL;

    return node;
}

/*
 * Recursive help function for tree_add
 */
static int _tree_add(node_t *current, cmpfunc_t cmp, void *elem) {
    /* if elem is smaller, go left */
    if (cmp(elem, current->elem) < 0) {
        if (current->left == NULL) { // Add node here
            current->left = new_node(elem);
            return 1;
        }
        return _tree_add(current->left, cmp, elem); // Keep searching
    /* if elem is larger, go right */
    }
    if (cmp(elem, current->elem) > 0) {
        if (current->right == NULL) { // Add node here
            current->right = new_node(elem);
            return 1;
        }
        return _tree_add(current->right, cmp, elem); // Keep searching
    }

    // If elem is already in tree, don't add it
    if (cmp(elem, current->elem) == 0)
        return 0;

}

/*
 * Appends a given element to the binary tree
 */
void tree_add(tree_t *tree, void *elem) {
    
    // If tree is empty, add a root
    if (tree->root == NULL) {
        tree->root = new_node(elem);
        tree->size++;
        return;
    }

    // If tree is non-empty, find the nodes place
    if (_tree_add(tree->root, tree->cmp, elem))
        tree->size++;
}

/*
 * Get amount of elements in tree
 */
int tree_getsize(tree_t *tree) {
    return tree->size;
}

/*
 * Recursive help function for tree_print
 */
static void _tree_print(node_t *current) {
    if (current == NULL)
        return;

    _tree_print(current->left);
    printf("%d->", *(int *)current->elem);
    _tree_print(current->right);
}

/*
 * Prints tree in order
 */
void tree_print(tree_t *tree) {
    if (tree->root == NULL) {
        printf("Tree is empty\n");
        return;
    }
    // If tree is non-empty, print it
    _tree_print(tree->root);
    printf("\n");
}

/*
 * Recursive help function for tree_remove
 */
static void _tree_remove(node_t *current, void *elem) {
    /* If it is a leaf node */
    if (current->left == NULL && current->right == NULL) {
        free(current->elem);
        free(current);
    }
}

/*
 * Removes a given element from the binary tree, if it exists
 */
void tree_remove(tree_t *tree, void *elem) {
    /* Do nothing if tree is empty */
    if (tree->root == NULL)
        return;
    /* Check if the root is to be removed */
    if (tree->cmp(tree->root->elem, elem) == 0) {

    }


    _tree_remove(tree->root, elem);
}

/*
 * Recursive help function for tree_contains
 */
static int _tree_contains(node_t *current, cmpfunc_t cmp, void *elem) {
    /* Return if we reach bottom */
    if (current == NULL)
        return 0;

    /* Return 1 if we have found elem */
    if (cmp(elem, current->elem) == 0)
        return 1;
    
    /* Otherwise, keep searching */
    if (_tree_contains(current->left, cmp, elem))
        return 1;
    if (_tree_contains(current->right, cmp, elem))
        return 1;
    
    /* Return 0 if elem was not in subtree */
    return 0;
}

/*
 * Check whether an element is contained in a given tree
 */
int tree_contains(tree_t *tree, void *elem) {
    /* Return 0 if tree is empty */
    if (tree->root == NULL)
        return 0;
    
    return _tree_contains(tree->root, tree->cmp, elem);

}