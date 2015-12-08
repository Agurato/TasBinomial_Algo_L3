#include <stdio.h>
#include <stdlib.h>
#include "tasBinomial.h"


int main(int argc, char *argv[]){

	ArbreBinomial A = CreerArbreBinomial();
	ArbreBinomial B = CreerArbreBinomial();
	ArbreBinomial C = CreerArbreBinomial();
	A = Inserer(A,5);
	A = Inserer(A,2);

	B = Inserer(A,17);
	B = Inserer(B,1);

	A = Union(A,B);
	C = ExtraireMin(A);
	printf("%d\n",C->cle);
    return 0;
}
