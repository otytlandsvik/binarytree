## Author: Steffen Viken Valvaag <steffenv@cs.uit.no> 
TREE_SRC= binarytree.c
TEST_SRC= treetest.c common.c $(TREE_SRC)
HEADERS=common.h binarytree.h

all: test

test: $(TEST_SRC) $(HEADERS) Makefile
	gcc -g -o $@ $(TEST_SRC)

clean:
	rm -f *~ *.o *.exe test
