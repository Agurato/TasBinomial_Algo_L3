#include <stdio.h>
#include <stdlib.h>
#include "vincent.h"

int main(int argc, char const *argv[]) {
	BinomialTree T = insertKey(NULL, 1);

	printf("T->key=%d / T->degree=%d\n", T->key, T->degree);

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
	if(T == NULL) {
		T = createTree();
		T->key = key;
		T->degree ++;
	}
	else {

	}

	return T;
}

// Used to link 2 tree with the same degree
BinomialTree linkTrees(BinomialTree T1, BinomialTree T2) {
	if(T1->key < T2->key) {
		T2->rightBrother = T1->leftSon;
		T2->father = T1;
		T1->leftSon = T2;
		T1->degree ++;

		return T1;
	}
	else {
		T1->rightBrother = T2->leftSon;
		T1->father = T2;
		T2->leftSon = T1;
		T2->degree ++;

		return T2;
	}
}
