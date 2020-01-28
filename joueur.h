#ifndef __JOUEUR_H__
#define __JOUEUR_H__

/* STRUCTURE ########################################################## */

typedef struct
{
    char nom[10];               // faudra faire un enum
    char combinaison_Joueur[6]; // nombre d'éléments à trouver
    int tentative;              // nombre de tentatives
} joueur;

/* PROTOTYPES ##########################################################*/

joueur Saisir_Nom_Joueur();                            // déclare un joueur et lui demande son speudo
void Saisir_Combinaison_Joueur(joueur *joueur, int n); // demande une combinaison
void Incrementation_Tentative_Joueur(joueur *joueur);  // compteur de manches

#endif
