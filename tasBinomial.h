typedef struct noeud{
    int degre;
    int cle;
    struct noeud *pere, *pfg, *pfd;
}*ArbreBinomial;


ArbreBinomial CreerArbreBinomial();
ArbreBinomial Inserer(ArbreBinomial T, int cle);
ArbreBinomial Lier(ArbreBinomial, ArbreBinomial);
ArbreBinomial AjouterCle(ArbreBinomial, ArbreBinomial);
ArbreBinomial Union(ArbreBinomial T1, ArbreBinomial T2);
ArbreBinomial ExtraireMin(ArbreBinomial);
ArbreBinomial Fusionner(ArbreBinomial, ArbreBinomial);
ArbreBinomial SupprimerMinTas(ArbreBinomial);
ArbreBinomial DecrementerCle(ArbreBinomial T, ArbreBinomial x, int  k);
int TasBinomialVide(ArbreBinomial);
void AfficherTas(ArbreBinomial T);
