#include <stdio.h>
#include <stdlib.h>
#include "vincent.h"

int main(int argc, char const *argv[]) {
	/*
	BinomialTree T = insertKey(NULL, 1);
	printf("T->key=%d / T->degree=%d\n", T->key, T->degree);
	*/

	BinomialHeap H = createHeap();

	BinomialTree T1 = createTree();
	T1->key = 7;
	T1->leftSon = createTree();
	T1->leftSon->father = T1;
	T1->leftSon->key = 11;
	T1->leftSon->leftSon = createTree();
	T1->leftSon->leftSon->father = T1->leftSon;
	T1->leftSon->leftSon->key = 27;
	T1->leftSon->rightBrother = createTree();
	T1->leftSon->rightBrother->father = T1;
	T1->leftSon->rightBrother->key = 10;

	BinomialTree T2 = createTree();
	T2->key = 12;
	T2->leftSon = createTree();
	T1->leftSon->father = T2;
	T2->leftSon->key = 37;
	T2->leftSon->leftSon = createTree();
	T1->leftSon->leftSon->father = T2->leftSon;
	T2->leftSon->leftSon->key = 41;
	T2->leftSon->rightBrother = createTree();
	T1->leftSon->rightBrother->father = T2;
	T2->leftSon->rightBrother->key = 18;

	H->tree = T1;

	displayTree(T1, 0);
	printf("\n");
	displayTree(T2, 0);
	printf("\n");

	BinomialTree T = linkTrees(T1, T2);
	displayTree(T, 0);
	printf("\n");

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

Boolean emptyHeap(BinomialHeap heap) {
	return (heap == NULL);
}

BinomialTree insertKey(BinomialTree T, int key) {
	if(T == NULL) {
		T = createTree();
		T->key = key;
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

BinomialHeap addKey(BinomialHeap H, BinomialTree T) {



	return H;
}

BinomialHeap mergeHeaps(BinomialHeap H1, BinomialHeap H2) {
	BinomialHeap heap = createHeap();

	while((H1 != NULL) && (H2 != NULL)) {
		if(H1->tree->degree == H2->tree->degree) {
			heap = insertHeap(heap, H1);
			heap = insertHeap(heap, H2);

			H1->tree = H1->tree->rightBrother;
			H2->tree = H2->tree->rightBrother;
		}
		else if(H1->tree->degree < H2->tree->degree) {
			heap = insertHeap(heap, H1);
			H1->tree = H1->tree->rightBrother;
		}
		else {
			heap = insertHeap(heap, H2);
			H2->tree = H2->tree->rightBrother;
		}
	}

	while (H1 != NULL) {
		heap = insertHeap(heap, H1);
		H1->tree = H1->tree->rightBrother;
	}

	return heap;
}

BinomialHeap joinHeaps(BinomialHeap H1, BinomialHeap H2) {
	return H1;
}

BinomialHeap insertHeap(BinomialHeap H1, BinomialHeap H2) {
	BinomialHeap heap = createHeap();
	heap->tree = createTree();
	H2->tree->father = NULL;
	H2->tree->leftSon = NULL;
	H2->tree->rightBrother = NULL;
	H2->tree->degree = 0;
	heap->next = heap;
	heap->tree = H2->tree;

	heap = joinHeaps(heap, H1);

	return heap;
}

void displayTree(BinomialTree T, int current) {
	if(T != NULL) {
		if(T->key < 10) {
			printf("-> 0%d ", T->key);
		}
		else {
			printf("-> %d ", T->key);
		}
		if(T->leftSon != NULL) {
			displayTree(T->leftSon, current+1);
		}
		if(T->rightBrother != NULL) {
			printf("\n");
			int i;
			for(i=0 ; i<current ; i++) {
				printf("      ");
			}
			displayTree(T->rightBrother, current);
		}
	}
}

void displayHeap(BinomialHeap H) {
	while(! emptyHeap(H)) {
		displayTree(H->tree, 0);
		printf("\n");
		H = H->next;
	}
}

BHeap createBHeap() {
	BHeap heap = malloc(sizeof(struct heapNode));
	heap->degree = 0;
	heap->key = 0;
	heap->father = NULL;
	heap->son = NULL;
	heap->brother = NULL;
	return heap;
}

BHeap mergeBHeaps(BHeap H1, BHeap H2) {
	BHeap heap = createBHeap();
	while((H1 != NULL) && (H2 != NULL)) {
		if(H1->degree == H2->degree) {
			heap = insertBHeap(heap, H1);
			heap = insertBHeap(heap, H2);
			H1 = H1->brother;
			H2 = H2->brother;
		}
		else if(H1->degree < H2->degree) {
			heap = insertBHeap(heap, H1);
			H1 = H1->brother;
		}
		else {
			heap = insertBHeap(heap, H2);
			H2 = H2->brother;
		}
	}

	while(H1 != NULL) {
		heap = insertBHeap(heap, H1);
		H1 = H1->brother;
	}
	while(H2 != NULL) {
		heap = insertBHeap(heap, H2);
		H2 = H2->brother;
	}

	return heap;
}

BHeap joinBHeaps(BHeap H1, BHeap H2) {
	BHeap heap = createBHeap();
	BHeap prev, next, x;

	heap = mergeBHeaps(H1, H2);

	if(heap != NULL) {
		prev = NULL;
		x = heap;
		next = x->brother;

		while(next != NULL) {
			if((x->degree != next->degree) || ((next->brother != NULL) && (next->brother->degree == x->degree))) {
				prev = x;
				x = next;
			}
			else if(x->key <= next->key) {
				x->brother = next->brother;
				linkBHeaps(next, x);
			}
			else {
				if(prev == NULL) {
					heap = next;
				}
				else {
					prev->brother = next;
				}
				linkBHeaps(x, next);
				x = next;
			}
			next = x->brother;
		}
	}

	return heap;
}

BHeap insertBHeap(BHeap H1, BHeap H2) {
	BHeap heap = createBHeap();
	H2->father = NULL;
	H2->son = NULL;
	H2->brother = NULL;
	H2->degree = 0;

	heap->brother = heap;
	heap = H2;
	heap = joinBHeaps(heap, H1);

	return heap;
}

BHeap linkBHeaps(BHeap H1, BHeap H2) {
	if(H1->key < H2->key) {
		H2->brother = H1->son;
		H2->father = H1;
		H1->son = H2;
		H1->degree ++;

		return H1;
	}
	else {
		H1->brother = H2->son;
		H1->father = H2;
		H2->son = H1;
		H2->degree ++;

		return H2;
	}
}
