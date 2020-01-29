#ifndef __JOUEUR_H__
#define __JOUEUR_H__

/* STRUCTURE ########################################################## */

typedef struct
{
    char nom[10];               // speudo
    char combinaison_Joueur[6]; // combinaison joueur
    int tentative;              // nombre de tentatives réalisées
} joueur;

/* PROTOTYPES ##########################################################*/

joueur Saisir_Nom_Joueur();                            // déclare un joueur et lui demande son speudo
void Saisir_Combinaison_Joueur(joueur *joueur, const int n); // demande une combinaison
void Incrementation_Tentative_Joueur(joueur *joueur);  // compteur de manches

#endif
