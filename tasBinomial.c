#include <stdio.h>
#include <stdlib.h>
#include "tasBinomial.h"

ArbreBinomial CreerArbreBinomial(){
    ArbreBinomial A;
    A = malloc(sizeof(struct noeud));
    A->degre = 0;
    A->cle = 0;
    A->pere = A->pfg = A->pfd = NULL;
    return A;
}

/*Fonctionne*/
/*Voir s'il ne faut pas vérifier le cas que A non vide*/
ArbreBinomial Inserer(ArbreBinomial T, int cle){
	ArbreBinomial T1 = CreerArbreBinomial();
	ArbreBinomial x = CreerArbreBinomial();
	x->pere = NULL;
	x->pfg = NULL;
	x->pfd = NULL;
	x->degre = 0;
	x->cle = cle;
	T1 = Union(x,T);
    return T1;
}

/* On lie deux arbres binomiaux
 * La racine d'un des arbres devient le fils gauche de l'autre arbre
 *
 * Fonctionne
 */
ArbreBinomial Lier(ArbreBinomial A, ArbreBinomial B){
    B->pere = A;
    B->pfd = A->pfg;
    A->pfg = B;
    A->degre++;
    return A;
}

ArbreBinomial ExtraireMin(ArbreBinomial T){
    ArbreBinomial B, C;
    int cleMin = 10000000;
    B = T;
    C = T;
        while(B!=NULL){
            if(B->cle < cleMin){
                cleMin = B->cle;
                C = B;
            }
            B = B->pfd;
        }
    return C;
}




ArbreBinomial Fusionner(ArbreBinomial TasUn, ArbreBinomial TasDeux){
    ArbreBinomial T = CreerArbreBinomial();
    while(TasUn != NULL && TasDeux != NULL){
        if(TasUn->degre == TasDeux->degre){
            T = Lier(T,TasUn);
			T = Lier(T,TasDeux);
			TasUn = TasUn->pfd;
			TasDeux = TasDeux->pfd;
		}
		else{
			if(TasUn->degre < TasDeux->degre){
				T = Lier(T,TasUn);
				TasUn = TasUn->pfd;
			}else{
				T = Lier(T,TasDeux);
				TasDeux = TasDeux->pfd;
			}
		}
	}

}

ArbreBinomial Union(ArbreBinomial T1, ArbreBinomial T2){
	ArbreBinomial T = CreerArbreBinomial();
	ArbreBinomial x, Succ, Pred;
	T = Fusionner(T1,T2);
	if(T == NULL){
		return T;
	}else{
		Pred = NULL;
		x = T;
		Succ = x->pfd;
		while(Succ != NULL){
			if((x->degre != Succ->degre) || (Succ->pfd->degre == x->degre) && 
					(Succ->pfd->degre == x->degre)){
				Pred = x;
				x = Succ;
			}else{
				if(x->cle <= Succ->cle){
				x->pfd = Succ->pfd;
				Lier(Succ,x);
				}else{
					if(Pred == NULL){
					T = Succ;
					}else{
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
