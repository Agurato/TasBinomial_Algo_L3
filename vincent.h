#include <malloc.h>

typedef struct node {
	int degree;
	int key;
	struct node *father, *leftSon, *rightBrother;
} *BinomialTree;

typedef struct cell {
	BinomialTree tree;
	struct cell *next;
} *BinomialHeap;

typedef struct heapNode {
	int degree;
	int key;
	struct heapNode *father, *son, *brother;
} *BHeap;

typedef enum {false, true} Boolean;

BinomialTree createTree();
BinomialHeap createHeap();
BinomialTree insertKey(BinomialTree T, int key);
BinomialTree linkTrees(BinomialTree T1, BinomialTree T2);
BinomialHeap mergeHeaps(BinomialHeap H1, BinomialHeap H2);
BinomialHeap joinHeaps(BinomialHeap H1, BinomialHeap H2);
BinomialHeap insertHeap(BinomialHeap H, BinomialHeap x);
void displayTree(BinomialTree T, int current);
void displayHeap(BinomialHeap H);

BHeap createBHeap();
BHeap mergeBHeaps(BHeap H1, BHeap H2);
BHeap BHeapUnion(BHeap H1, BHeap H2);
BHeap insertBHeap(BHeap H1, BHeap H2);
BHeap linkBHeaps(BHeap H1, BHeap H2);
BHeap deleteBHeap(BHeap heap);
void displayBHeap(BHeap heap, int current);
