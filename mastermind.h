#ifndef __MASTERMIND_H__
#define __MASTERMIND_H__

#include "niveau.h"
#include "joueur.h"

/* STRUCTURE ########################################################## */

typedef struct mastermind
{
    joueur joueur; // nom - combinaison_Joueur - tentative
    niveau niveau; // nom - pion - coup - combinaison_Secrete
    FILE *out;     // fichier de sauvegarde des résultats
} mastermind;

/* PROTOTYPES ########################################################## */

void vider_Buffer();                                              // vide le buffer - "tampon"
void Affichage_Combinaison(mastermind mastermind);                // affiche la combinaison du joueur
int Comparaison(mastermind mastermind);                           // détermine si la combinaison est bonne et donne des indices à l'utilisateur
int Existant(mastermind mastermind, char c);                      // vérifie si le pion inséré fait parti de la combinaison secrète
void Sauvegarder_Resultat(mastermind mastermind, char texte[25]); // sauvegarde le résultat de la partie dans un fichier

#endif
