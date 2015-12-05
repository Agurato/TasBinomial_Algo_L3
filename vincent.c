#include <stdio.h>
#include <stdlib.h>
#include "vincent.h"

int main(int argc, char const *argv[]) {

	return 0;
}

BinomialTree createTree() {
	BinomialTree tree = malloc(sizeof(struct node));

	tree->degree = 0;
	tree->key = 0;
	tree->father = NULL;
	tree->leftSon = NULL;
	tree->rightBrother = NULL;

	return tree;
}

BinomialHeap createHeap() {
	BinomialHeap heap = malloc(sizeof(struct cell));

	heap->tree = NULL;
	heap->next = NULL;

	return heap;
}

BinomialTree insertKey(BinomialTree T, int key) {
	

	return T;
}
