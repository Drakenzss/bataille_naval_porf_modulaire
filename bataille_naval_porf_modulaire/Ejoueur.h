#pragma once



enum etatJoueur {

    gagne, perd

}etatJoueur;

//Prototypes
void fPlayer(Case mCase, Flotte* f);
void saisirAttaque(Case* mCase);
enum etatJoueur etatJ(Flotte f);
int validSaisiJoueur(char val[]);
void saisieJoueur(char valLigne[], char valCol[]);

//definition

//construit la flotte d'un joueur
void fPlayer(Case mCase, Flotte* f) {

    int i;
    int valRandPosLigne = 0;
    int valRandPosCol = 0;
    int valRandTailleBateau = 0;



    for (i = 0; i < NBBATEAU; i++) {

        valRandPosLigne = rand() % (MAXL - MAXCASE) + 1;
        valRandPosCol = rand() % (MAXC - MAXCASE) + 1;
        valRandTailleBateau = rand() % MAXCASE + 1;
        createCase(valRandPosLigne, valRandPosCol, &mCase);
        f->nBateau[i] = createBateau(mCase, valRandTailleBateau);
    }
}


//initFlotteJoueur
void initFlotteJoueur(Flotte* flotteJoueur1, Flotte* flotteJoueur2, Case mCase) {


    printf("Initialisation Bateaux Player 1\n");

    fPlayer(mCase, flotteJoueur1);

    puts("Appuyer sur enter pour continuer\n");
    getchar();
    fflush(stdin);


    printf("Initialisation Bateaux Player 2\n");

    fPlayer(mCase, flotteJoueur2);

    puts("Appuyer sur enter pour continuer\n");
    getchar();
    fflush(stdin);
}

//retourne  etat du joueur
enum etatJoueur etatJ(Flotte f) {


    if (etatFlot(f) == aSombrer)
        return perd;
    else
        return gagne;


}

//fct valide saisie joueur
int validSaisiJoueur(char val[]) {

    int i;


    for (i = 0; i < strlen(val); i++) {

        if (!isdigit(val[i]))
            return 0;
    }

    return 1;


}

//procédure saisie val joueur

void saisieJoueur(char valLigne[], char valCol[]) {


    printf("Entrez votre tir\n");

    printf("Entrez ligne :\n");
    scanf_s("%d", valLigne);
    fflush(stdin);

    printf("Entrez Colonne :\n");
    scanf_s("%d", valCol);
    fflush(stdin);


}