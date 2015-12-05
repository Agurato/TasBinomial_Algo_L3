typedef struct node {
	int degree;
	int key;
	struct node *father, *leftSon, *rightBrother;
} *BinomialTree;

typedef struct cell {
	BinomialTree tree;
	struct cell *next;
} *BinomialHeap;