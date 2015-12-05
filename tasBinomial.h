typedef struct noeud{
    int degre;
    int cle;
    struct noeud *pere, *pfg, *pfd;
}*ArbreBinomial;

typedef struct cellule{
    ArbreBinomial A;
    struct cellule *suivant;
}*TasBinomial;


ArbreBinomial CreerArbreBinomial();
TasBinomial CreerTasBinomial();
ArbreBinomial Inserer(ArbreBinomial, int);
ArbreBinomial Lier(ArbreBinomial, ArbreBinomial);
TasBinomial AjouterCle(TasBinomial, ArbreBinomial);
ArbreBinomial ExtraireMin(TasBinomial);
TasBinomial Fusionner(TasBinomial, TasBinomial);
TasBinomial Union(TasBinomial);
TasBinomial SupprimerMinTas(TasBinomial);
TasBinomial DecrementerCle(TasBinomial, ArbreBinomial);
int TasBinomialVide(TasBinomial);
void AfficherTas(TasBinomial T);
