#include <stdio.h>
#include <stdlib.h>
#include "vincent.h"

int main(int argc, char const *argv[]) {
	/*
	BinomialTree T = insertKey(NULL, 1);
	printf("T->key=%d / T->degree=%d\n", T->key, T->degree);
	*/
	/*
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
	*/
	/* Code de test avec tas en 1.4
	BHeap heap = createBHeap();
	heap->key = 4;
	heap->son = createBHeap();
	heap->son->key = 12;
	heap->son->son = createBHeap();
	heap->son->son->key = 70;
	heap->son->brother = createBHeap();
	heap->son->brother->key = 20;

	BHeap heap2 = createBHeap();
	heap2->key = 7;
	heap2->son = createBHeap();
	heap2->son->key = 11;
	heap2->son->son = createBHeap();
	heap2->son->son->key = 27;
	heap2->son->brother = createBHeap();
	heap2->son->brother->key = 10;

	BHeap H = linkBHeaps(heap, heap2);
	*/

	BHeap H = NULL;
	BHeap addHeap = createBHeap();

	addHeap->key = 2;
	H = insertBHeap(H, addHeap);
	addHeap->key = 7;
	H = insertBHeap(H, addHeap);
	//addHeap->key = 3;
	//H = insertBHeap(H, addHeap);
	//displayBHeap(H, 0);
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
	BHeap heap = NULL;
	BHeap temp;

	if(H1 != NULL) {
		if((H2 != NULL) && (H1->degree <= H2->degree)) {
			heap = H1;
		}
		else if((H2 != NULL) && (H1->degree > H2->degree)) {
			heap = H2;
		}
		else {
			heap = H1;
		}
	}
	else {
		heap = H2;
	}

	while (H1 != NULL && H2 != NULL) {
		if(H1->degree < H2->degree) {
			H1 = H1->brother;
		}
		else if(H1->degree == H2->degree) {
			temp = H1->brother;
			H1->brother = H2;
			H1 = temp;
		}
		else {
			temp = H2->brother;
			H2->brother = H1;
			H2 = temp;
		}
	}

	/*
	while((emptyBHeap(H1)) && (emptyBHeap(H2))) {
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

	while(! emptyBHeap(H1)) {
		heap = insertBHeap(heap, H1);
		H1 = H1->brother;
	}
	while(! emptyBHeap(H2)) {
		heap = insertBHeap(heap, H2);
		H2 = H2->brother;
	}
	*/
	return heap;
}

BHeap BHeapUnion(BHeap H1, BHeap H2) {
	BHeap heap = NULL;
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
				next = linkBHeaps(next, x);
			}
			else {
				if(prev == NULL) {
					heap = next;
				}
				else {
					prev->brother = next;
				}
				next = linkBHeaps(x, next);
				x = next;
			}
			next = x->brother;
		}
	}

	return heap;
}

BHeap insertBHeap(BHeap H, BHeap x) {
	BHeap heap = NULL;
	x->father = NULL;
	x->son = NULL;
	x->brother = NULL;
	x->degree = 0;

	heap = x;
	H = BHeapUnion(H, heap);

	return H;
}

BHeap linkBHeaps(BHeap H1, BHeap H2) {
	H2->father = H1;
	H2->brother = H1->son;
	H1->son = H2;
	H1->degree ++;

	return H1;
	/*
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
	*/
}

BHeap deleteBHeap(BHeap heap) {
	if(heap != NULL) {
		heap->son = deleteBHeap(heap->son);
		heap->brother = deleteBHeap(heap->brother);
		free(heap);
		heap = NULL;
	}
	return heap;
}

void displayBHeap(BHeap heap, int current) {
	if(heap != NULL) {
		if(heap->key < 10) {
			printf("-> 0%d ", heap->key);
		}
		else {
			printf("-> %d ", heap->key);
		}
		if(heap->son != NULL) {
			displayBHeap(heap->son, current+1);
		}
		if(heap->brother != NULL) {
			printf("\n");
			int i;
			for(i=0 ; i<current ; i++) {
				printf("      ");
			}
			displayBHeap(heap->brother, current);
		}
	}
	/*
	while(heap != NULL) {
		printf("%d", heap->key);
		if(heap->brother != NULL) {
			printf(" --> ");
		}
		heap = heap->brother;
	}
	printf("\n");
	*/
}
