#include <stdio.h>
#include <stdlib.h>
#include "tasBinomial.h"

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
    T->A = NULL;
    T->suivant = NULL;
    return T;
}

ArbreBinomial Inserer(ArbreBinomial A, int cle){
    ArbreBinomial ArbreDeux = CreerArbreBinomial();
    ArbreDeux->pere = ArbreDeux->pfd = ArbreDeux->pfg = NULL;
    ArbreDeux->cle = cle;
    ArbreDeux->degre = 0;

    return A;
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

/* On insère dans le tas l'arbre,
 * On vérifie que l'arbre à le même degré que le suivant
 *      Si oui on les lies
 *      Si non on laisse ainsi
 * Puis on revérifie les autres
 */
TasBinomial AjouterCle(TasBinomial Tas, ArbreBinomial ArbreB){
    TasDeux = CreerTas();
    TasDeux->A = ArbreB;
    TasDeux->suivant = Tas;
    if(TasDeux->A->degre == TasDeux->suivant->A->degre){
        /*Ici il faut lier les deux Arbres pour n'en faire qu'un seul
         */
        Tas = Lier(TasDeux->A,Tas->A);
        TasDeux->suivant = NULL;
        free(TasDeux);
    }else{
    }
    return Tas;
}

ArbreBinomial ExtraireMin(TasBinomial T){
    ArbreBinomial B, C;
    int cleMin = 100000000000;
    B = T->A;
    C = T->A;
    if(T->suivant != NULL){
        B = ExtraireMin(T->suivant);
        while(B!=NULL){
            if(B->cle < min){
                min = B->cle;
                C = B;
            }
            B = B->fd;
        }
    }
    return C;
}

TasBinomial Fusionner(TasBinomial TasUn, TasBinomial TasDeux){
    TasBinomial T = CreerTasBinomial();
    while(TasUn != NULL){
        if(TasUn->A->degre == TasDeux->A->degre){
            T = AjouterCle

}

TasBinomial Union(TasBinomial){

}

TasBinomial SupprimerMinTas(TasBinomial){

}

TasBinomial DecrementerCle(TasBinomial, ArbreBinomial){

}

Booleen TasBinomialVide(TasBinomial){

}
