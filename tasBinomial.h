typedef {Faux, Vrai} Booleen;
typedef struct noeud{
    int degre;
    int cle;
    struct noeud *pere, *pfg, *pfd;
}*ArbreBinomial;
typedef struct cellule{
    A_Binomial A;
    struct cellule *suivant;
}*TasBinomial;


ArbreBinomial Creer_Arbre_Binomial();
ArbreBinomial Inserer(ArbreBinomial, int);
ArbreBinomial Lier(ArbreBinomial, ArbreBinomial);
TasBinomial AjouterCle(TasBinomial, ArbreBinomial);
ArbreBinomial ExtraireMin(TasBinomial);
TasBinomial Fusionner(TasBinomial, TasBinomial);
TasBinomial Union(TasBinomial);
TasBinomial SupprimerMinTas(TasBinomial);
TasBinomial DecrementerCle(TasBinomial, ArbreBinomial);
Booleen TasBinomialVide(TasBinomial);
