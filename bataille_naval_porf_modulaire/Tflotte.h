#pragma once

#include "Tbateau.h"



typedef struct Flotte {

    Bateau nBateau[NBBATEAU];


}Flotte;

enum etatFlotte {


    aFlot, aSombrer

}etatFlotte;

//Prototypes
enum Bool controlFlotte(Flotte f, Case mCase);
int tailleBateau(Flotte f, int numBateau);
void attaqueBateau(Flotte* f, Case mCase, int* numBateau);
enum etatBateau etatBat(Flotte f, int numBateau);
enum etatFlotte etatFlot(Flotte f);
void initFlotteJoueur(Flotte* flotteJoueur1, Flotte* flotteJoueur2, Case mCase);


//definition

//return True si la case passé en paramètre appatient bien à un bateau d'une flotte
enum Bool controlFlotte(Flotte f, Case mCase) {

    int i;
    enum Bool valTest = False;
    for (i = 0; i < NBBATEAU; i++) {
        if (controlCase(f.nBateau[i], mCase) == True)
            valTest = True;


    }

    return valTest;
}

//return la taille d'un bateau d'une flotte passé en paramètre
int tailleBateau(Flotte f, int numBateau) {

    int i;
    int tailleBat = 0;

    for (i = 0; i < MAXCASE; i++) {

        if (f.nBateau[numBateau].nCase[i].col > 0 && f.nBateau[numBateau].nCase[i].ligne > 0)
            tailleBat++;

    }

    return tailleBat;

}


//Procédure attaque bateau

void attaqueBateau(Flotte* f, Case mCase, int* numBateau) {

    int i, j;


    for (i = 0; i < NBBATEAU; i++) {
        for (j = 0; j < MAXCASE; j++) {
            if (f->nBateau[i].nCase[j].ligne == mCase.ligne && f->nBateau[i].nCase[j].col == mCase.col) {
                f->nBateau[i].nCase[j].ligne = 0;
                f->nBateau[i].nCase[j].col = 0;
                *numBateau = i;


            }

        }
    }

    if (etatBat(*f, *numBateau))
        printf("Couler!!!\n");

    else
        printf("Toucher!!!\n");

}

//retourne etat bateau

enum etatBateau etatBat(Flotte f, int numBateau) {


    if (tailleBateau(f, numBateau) == 0) {

        return couler;

    }
    else {


        return toucher;

    }

}

//retourne etat flotte
enum etatFlotte etatFlot(Flotte f) {

    int i, j;
    enum etatFlotte st = aFlot;

    for (i = 0; i < NBBATEAU; i++) {
        for (j = 0; j < MAXCASE; j++) {

            if (f.nBateau[i].nCase[j].ligne == 0 && f.nBateau[i].nCase[j].col == 0)
                st = aSombrer;
            else {
                st = aFlot;
                return st;

            }


        }

    }

    return st;

}


