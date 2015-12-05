#include <stdio.h>
#include <stdlib.h>
#include "tasBinomial.h"

/*Fonctionne*/
ArbreBinomial CreerArbreBinomial(){
    ArbreBinomial A;
    A = malloc(sizeof(ArbreBinomial));
    A->degre = 0;
    A->cle = 0;
    A->pere = A->pfg = A->pfd = NULL;
    return A;
}

TasBinomial CreerTasBinomial(){
    TasBinomial T;
    T = malloc(sizeof(TasBinomial));
    T->A = CreerArbreBinomial();
    T->suivant = NULL;
    return T;
}

/*Fonctionne*/
/*VOir s'il ne faut pas vérifier le cas que A non vide*/
ArbreBinomial Inserer(ArbreBinomial A, int cle){
    A->pere = A->pfd = A->pfg = NULL;
    A->cle = cle;
    A->degre = 0;

    return A;
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

/* On insère dans le tas l'arbre,
 * On vérifie que l'arbre à le même degré que le suivant
 *      Si oui on les lies
 *      Si non on laisse ainsi
 * Puis on revérifie les autres
 */
TasBinomial AjouterCle(TasBinomial Tas, ArbreBinomial ArbreB){
	if(!TasBinomialVide(Tas)){

		TasBinomial TasDeux = CreerTasBinomial();

		TasDeux = AjouterCle(TasDeux,ArbreB);
		TasDeux->suivant = Tas;
		Tas = NULL;
		printf("Tas->A->cle = %d\n",TasDeux->A->cle);

		TasDeux->suivant = TasDeux->suivant->suivant;
		while(TasDeux->suivant != NULL){
			TasDeux->suivant = TasDeux->suivant->suivant;
			while(TasDeux->A->degre == TasDeux->suivant->A->degre ){
				/*Ici il faut lier les deux Arbres pour n'en faire qu'un seul
				 */
				TasDeux->A = Lier(TasDeux->A,TasDeux->suivant->A);
			}
		}
		return TasDeux;
	} else{
			Tas->A = ArbreB;
			return Tas;
	}
}

ArbreBinomial ExtraireMin(TasBinomial T){
    ArbreBinomial B, C;
    int cleMin = 10000000;
    B = T->A;
    C = T->A;
    if(T->suivant != NULL){
        B = ExtraireMin(T->suivant);
        while(B!=NULL){
            if(B->cle < cleMin){
                cleMin = B->cle;
                C = B;
            }
            B = B->pfd;
        }
    }
    return C;
}
/*
TasBinomial Fusionner(TasBinomial TasUn, TasBinomial TasDeux){
    TasBinomial T = CreerTasBinomial();
    while(TasUn != NULL){
        if(TasUn->A->degre == TasDeux->A->degre){
           // T = AjouterCle

}

TasBinomial Union(TasBinomial){

}

TasBinomial SupprimerMinTas(TasBinomial){

}

TasBinomial DecrementerCle(TasBinomial, ArbreBinomial){

}
*/
int TasBinomialVide(TasBinomial T){
	return (T->A->cle == 0);
}


/*Affiche un tas
 * Plus tard il faudra qu'il affiche par ordre croissant*/
void AfficherTas(TasBinomial T){}
