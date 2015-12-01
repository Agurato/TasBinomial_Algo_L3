#include <stdio.h>
#include <stdlib.h>
#include "tasBinomial.h"

ArbreBinomial CreerArbreBinomial(){
    ArbreBinomial A;
    A->degre = 0;
    A->cle = 0;
    A->pere = A->pfg = A->pfd = NULL;
    return A;
}

TasBinomial CreerTasBinomial(){
    TasBinomial T;
    T->A = NULL;
    T->suivant = NULL;
    return T;
}

ArbreBinomial Inserer(ArbreBinomial A, int cle){
    A->cle = cle;
    A->degre = 0;
    return A;
}

ArbreBinomial Lier(ArbreBinomial A, ArbreBinomial B){
    B->pere = A;
    B->pfd = A->pfg;
    A->pfg = B;
    A->degre++;
    return A;
}

TasBinomial AjouterCle(TasBinomial, ArbreBinomial){

}

ArbreBinomial ExtraireMin(TasBinomial){

}

TasBinomial Fusionner(TasBinomial, TasBinomial){

}

TasBinomial Union(TasBinomial){

}

TasBinomial SupprimerMinTas(TasBinomial){

}

TasBinomial DecrementerCle(TasBinomial, ArbreBinomial){

}

Booleen TasBinomialVide(TasBinomial){

}
