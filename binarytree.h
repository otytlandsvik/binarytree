#ifndef BINARYTREE_H
#define BINARYTREE_H

/* Structures */
typedef struct tree tree_t;
typedef struct node node_t;

/* Compare function. Returns a-b */
typedef int (*cmpfunc_t)(void*, void*);

/*
 * Creates a binary search tree
 */
tree_t *tree_create(cmpfunc_t cmp);

/*
 * Destroys a given binary tree, freeing the memory used
 */
void tree_destroy(tree_t *tree);

/*
 * Appends a given element to the binary tree
 */
void tree_add(tree_t *tree, void *elem);

/*
 * Prints tree in order
 */
void tree_print(tree_t *tree);

/*
 * Removes a given element from the binary tree
 */
void tree_remove(tree_t *tree, void *elem);

/* Tree iterator */
typedef struct tree_iter tree_iter_t;

/*
 * Creates an iterator for iterating through given binary tree
 */
tree_iter_t *tree_createiter(tree_t *tree);

/*
 * Destroys iterator, freeing the memory used
 */
void tree_destroyiter(tree_iter_t *iter);

/*
 * Returns 0 if iter has reached the end of the tree, 
 * 1 otherwise
 */
int tree_hasnext(tree_iter_t *iter);

/*
 * Returns the next element from tree, and increments
 * iterator
 */
void *tree_next(tree_iter_t *iter);

/*
 * Resets iterator
 */
void tree_resetiter(tree_iter_t *iter);

#endif