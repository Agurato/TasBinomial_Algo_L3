#include <stdio.h>
#include <stdlib.h>
#include "tasBinomial.h"


int main(int argc, char *argv[]){

	ArbreBinomial A = CreerArbreBinomial();
	int cle;
	A = Inserer(A,5);
	printf("%d\n",A->cle);
    return 0;
}
