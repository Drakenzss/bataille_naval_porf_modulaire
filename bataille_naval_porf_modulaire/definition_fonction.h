#pragma once


#include "Tcase.h"
#include "Tbateau.h"

enum Bool controlCase(Bateau mBat, Case mCase);


//definition

//Return True si la case passé en paramètre appartient bien à un bateau
enum Bool controlCase(Bateau mBat, Case mCase) {


    int i;
    enum Bool valTest = False;
    for (i = 0; i < MAXCASE; i++) {

        if (cmpCase(mBat.nCase[i], mCase) == True)
            valTest = True;


    }

    return valTest;


}
