#include <stdio.h>
#include <stdlib.h>
#include "tasBinomial.h"


int main(int argc, char *argv[]){

	ArbreBinomial A = CreerArbreBinomial();
	ArbreBinomial B = CreerArbreBinomial();
	ArbreBinomial C = CreerArbreBinomial();
	B->cle = 5;
	A = Inserer(A,B);
	printf("A = %d\n",A->cle);

	/*
	B = Inserer(A,17);
	printf("B = %d\n",B->cle);
	B = Inserer(B,1);
	printf("B = %d\n",B->cle);

	A = Union(B,A);*/
	C = ExtraireMin(A);
	
	printf("Min = %d\n",C->cle);
    return 0;
}
