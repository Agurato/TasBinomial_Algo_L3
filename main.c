#include <stdio.h>
#include <stdlib.h>
#include "tasBinomial.h"


int main(int argc, char *argv[]){
		ArbreBinomial A = CreerArbreBinomial();
		
		TasBinomial T = CreerTasBinomial();

		A = Inserer(A,12);
		T = AjouterCle(T,A);
		
		A = NULL;
		A = CreerArbreBinomial();
		printf("A = %d\n", A->cle);
		A = Inserer(A,10);
		T = AjouterCle(T,A);

		printf(" Cle = %d\n",T->A->pfg->cle);	

    return 0;
}
