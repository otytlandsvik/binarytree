#include <stdlib.h>
#include <stdio.h>

#include "binarytree.h"
#include "common.h"

static int compare_ints(void *a, void *b)
{
    int *ia = a;
    int *ib = b;

    return (*ia)-(*ib);
}

static void *newint(int i)
{
    int *p = malloc(sizeof(int));
    *p = i;
    return p;
}

int main() {
    tree_t *tree = tree_create(compare_ints);

    tree_add(tree, newint(5));
    tree_add(tree, newint(2));
    tree_add(tree, newint(9));
    tree_add(tree, newint(6));
    tree_add(tree, newint(7));
    tree_add(tree, newint(1));
    tree_add(tree, newint(12));
    tree_add(tree, newint(43));
    tree_add(tree, newint(4));
    tree_add(tree, newint(11));
    
    tree_remove(tree, newint(5));

    //tree_print(tree);

    printf("size: %d\n", tree_getsize(tree));
    tree_print(tree);
    //printf("Tree contains num: %d\n", tree_contains(tree, newint(7)));

    
}