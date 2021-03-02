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

static int _tree_add(node_t *current, cmpfunc_t cmp, void *elem) {
    /* if elem is smaller, go left */
    if (cmp(elem, current->elem) < 0) {
        if (current->left == NULL) { // Add node here
            current->left = new_node(elem);
            return 1;
        }
        _tree_add(current->left, cmp, elem); // Keep searching
    /* if elem is larger, go right */
    }
    if (cmp(elem, current->elem) > 0) {
        if (current->right == NULL) { // Add node here
            current->right = new_node(elem);
            return 1;
        }
        _tree_add(current->right, cmp, elem); // Keep searching
    }

    // If elem is already in tree, don't add it
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