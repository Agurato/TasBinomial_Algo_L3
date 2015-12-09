#include <stdio.h>
#include <stdlib.h>
#include "tasBinomial.h"

ArbreBinomial CreerArbreBinomial(){
    ArbreBinomial A;
    A = malloc(sizeof(struct noeud));
    A->pere = NULL;
    A->pfd = NULL;
    A->pfg = NULL;
    A->degre = 0;
    A->cle = 0;
    return A;
}

/*Voir s'il ne faut pas vérifier le cas que A non vide*/
ArbreBinomial Inserer(ArbreBinomial T, ArbreBinomial x){
	ArbreBinomial T1 = CreerArbreBinomial();
	x->pere = NULL;
	x->pfg = NULL;
	x->pfd = NULL;
	x->degre = 0;
	T1 = x;
	printf("T1->cle = %d\n",T1->cle);
	T1 = Union(T1,T);
    return T1;
}

/* On lie deux arbres binomiaux
 * La racine d'un des arbres devient le fils gauche de l'autre arbre
 */
ArbreBinomial Lier(ArbreBinomial A, ArbreBinomial B){
    	B->pere = A;
    	B->pfd = A->pfg;
  		A->pfg = B;
    	A->degre++;
    	return A;
}

ArbreBinomial Fusionner(ArbreBinomial TasUn, ArbreBinomial TasDeux){
    ArbreBinomial T = CreerArbreBinomial();
	//printf("TasDeux =  \n",TasDeux->cle);
    while(TasUn != NULL && TasDeux != NULL){
        if(TasUn->degre == TasDeux->degre){
            T = Inserer(T,TasUn);
			T = Inserer(T,TasDeux);
			TasUn = TasUn->pfd;
			TasDeux = TasDeux->pfd;
		}
		else{
			if(TasUn->degre < TasDeux->degre){
				T = Inserer(T,TasUn);
				TasUn = TasUn->pfd;
			}else{
				T = Inserer(T,TasDeux);
				TasDeux = TasDeux->pfd;
			}
		}
	}
	while(TasUn != NULL){
			T = Inserer(T,TasUn);
			TasUn = TasUn->pfd;
	}
	while(TasDeux != NULL){
			T = Inserer(T,TasDeux);
			TasDeux = TasDeux->pfd;
	}
	return T;
}

ArbreBinomial Union(ArbreBinomial T1, ArbreBinomial T2){
	ArbreBinomial T = CreerArbreBinomial();
	ArbreBinomial x = CreerArbreBinomial();
	ArbreBinomial Succ= CreerArbreBinomial();
	ArbreBinomial Pred= CreerArbreBinomial();
	T = Fusionner(T1,T2);

	if(T == NULL){
		return T;
	}
    else{
		Pred = NULL;
		x = T;
		Succ = x->pfd;
		while(Succ != NULL){
			if((x->degre != Succ->degre) || ((Succ->pfd != NULL) &&
					(Succ->pfd->degre == x->degre))) {
				Pred = x;
				x = Succ;
			}
            else {
				if(x->cle <= Succ->cle) {
				    x->pfd = Succ->pfd;
				    Lier(Succ,x);
				}
                else {
					if(Pred == NULL) {
					    T = Succ;
					}
                    else {
						Pred->pfd = Succ;
					}
					Lier(x,Succ);
					x=Succ;
				}
			}
			Succ = x->pfd;
		}
		return T;
	}
}

ArbreBinomial DecrementerCle(ArbreBinomial T, ArbreBinomial x, int  k){
	ArbreBinomial y,z;
	int tmp;
	if(k > x->cle){
		return NULL;
	}else{
		x->cle = k;
		y = x;
		x = y->pere;
		while((x != NULL) && (y->cle < x->cle)){
			tmp = y->cle;
			y->cle = x->cle;
			x->cle = tmp;
			y = x;
			x = y->pere;
		}
		return T;
	}
}

ArbreBinomial ExtraireMin(ArbreBinomial A){
	ArbreBinomial B,C;
	int cle = 10000000;
	B = A;
	C = A;
	while(B != NULL){
		if(B->cle < cle){
			cle = B->cle;
			C = B;
		}
		B = B->pfd;
	}
	return C;
}
/*
ArbreBinomial insererTri(ArbreBinomial A1, ArbreBinomial A2) {
	if(A1->cle < A2->cle) {
		A2->pfd = A1->pfg;
		A2->pere = A1;
		A1->pfg = A2;
		A1->degre ++;

		return A1;
	}
	else {
		A1->pfd = A2->pfg;
		A1->pere = A2;
		A2->pfg = A1;
		A2->degre ++;

		return A2;
	}
}
*/
