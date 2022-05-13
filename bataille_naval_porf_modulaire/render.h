#pragma once

#include "Tflotte.h"


void afficheDebug(Flotte f);
void effaceEcran();
void minMax(Flotte f, int* minLigne, int* maxLigne, int* minCol, int* maxCol);


//procedure Attaque bateau de flotteJoueur
void saisirAttaque(Case* mCase) {

    char valLigne[4], valCol[4];

    saisieJoueur(valLigne, valCol);



    while (!validSaisiJoueur(valLigne) || !validSaisiJoueur(valCol) || (atoi(valLigne) < MINL || atoi(valLigne) > MAXL)
        || (atoi(valCol) < MINC || atoi(valCol) > MAXC)) {

        effaceEcran();
        printf("Mauvaise saisie, recommencer vous devez saisir une val numerique comprise entre %d et %d\n", VALMIN, VALMAX);

        saisieJoueur(valLigne, valCol);


    }
    mCase->ligne = atoi(valLigne);
    mCase->col = atoi(valCol);

}

//procedure efface
void effaceEcran() {

    puts("Appuyer sur enter pour continuer\n");
    getchar();
    system("cls");

}

//Set val min, max de ligne et colonne d'une flotte de bateaux
void minMax(Flotte f, int* minLigne, int* maxLigne, int* minCol, int* maxCol) {


    int i, j;

    *maxLigne = *maxCol = VALMIN - 1;
    *minLigne = *minCol = VALMAX;

    for (i = 0; i < NBBATEAU; i++) {
        for (j = 0; j < MAXCASE; j++) {

            if (f.nBateau[i].nCase[j].ligne < *minLigne && f.nBateau[i].nCase[j].ligne>0)
                *minLigne = f.nBateau[i].nCase[j].ligne;
            else if (f.nBateau[i].nCase[j].ligne > *maxLigne && f.nBateau[i].nCase[j].ligne > 0)
                *maxLigne = f.nBateau[i].nCase[j].ligne;
            if (f.nBateau[i].nCase[j].col < *minCol && f.nBateau[i].nCase[j].col>0)
                *minCol = f.nBateau[i].nCase[j].col;
            else if (f.nBateau[i].nCase[j].col > *maxCol && f.nBateau[i].nCase[j].col > 0)
                *maxCol = f.nBateau[i].nCase[j].col;



        }
    }




}

//Affichage val col et ligne bateau pour debug
void afficheDebug(Flotte f) {

    int i, j;
    for (i = 0; i < NBBATEAU; i++) {
        for (j = 0; j < MAXCASE; j++) {
            printf("ligne : %d\n", f.nBateau[i].nCase[j].ligne);
            printf("col : %d\n", f.nBateau[i].nCase[j].col);
        }
        printf("\n");
    }


}


