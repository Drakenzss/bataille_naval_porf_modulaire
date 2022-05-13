#pragma once

#include "Tcase.h"


typedef struct Bateau {


    Case nCase[MAXCASE];



}Bateau;

enum positionBateau {

    enLigne, enColonne, enDiag

}positionBateau;

enum etatBateau {

    toucher, couler

}etatBateau;

//Prototypes
Bateau createBateau(Case nCase, int taille);


//definition

//Fct de création de bateau
//Return une structure bateau
Bateau createBateau(Case nCase, int taille) {

    Bateau res;


    positionBateau = rand() % 3;


    int i;
    for (i = 0; i < MAXCASE; i++) {
        if (i < taille) {
            res.nCase[i].ligne = nCase.ligne;
            res.nCase[i].col = nCase.col;
        }
        else {

            res.nCase[i].ligne = 0;
            res.nCase[i].col = 0;
        }
        if (positionBateau == enLigne) {

            nCase.col++;

        }
        else if (positionBateau == enColonne) {

            nCase.ligne++;

        }
        else if (positionBateau == enDiag) {

            nCase.ligne++;
            nCase.col++;
        }



    }

    return res;
}