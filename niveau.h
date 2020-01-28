#ifndef __NIVEAU_H__
#define __NIVEAU_H__

/* STRUCTURE ########################################################## */

typedef struct
{
    char nom[10];                // faudra faire un enum
    int pion;                    // nombre d'éléments à trouver
    int coup;                    // nombre de tentatives
    char combinaison_Secrete[6]; // doit être généré aléatoirement
} niveau;

/* PROTOTYPES ########################################################## */

void Afficher_Niveaux();                                             // affiche les niveaux disponnibles
int Saisir_Niveau();                                                 // récupère le choix du niveau
void Modifier_Niveau(niveau *niveau, char *nom, int pion, int coup); // modifie les attributs du niveau sélectionné
void Afficher_Combinaison_Secrete(niveau niveau);                    // affiche la combinaison secrète
void Generation_Combinaison_Secrete(niveau *niveau);                 // génère une combinaison aléatoire

#endif
