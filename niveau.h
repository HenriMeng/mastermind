#ifndef __NIVEAU_H__
#define __NIVEAU_H__

/* STRUCTURE ########################################################## */

typedef struct
{
    char libelle[10];            // libellé (FACILE - INTERMEDIAIRE - DIFFICILE)
    int pion;                    // nombre d'éléments à trouver
    int coup;                    // nombre de tentatives autorisées 
    char combinaison_Secrete[6]; // combinaison !aléatoire! secrète
} niveau;

/* PROTOTYPES ########################################################## */

void Afficher_Niveaux();                                                 // affiche les niveaux disponnibles
int Saisir_Niveau();                                                     // récupère le choix du niveau
void Modifier_Niveau(niveau *niveau, char *libelle, int pion, int coup); // modifie les attributs du niveau sélectionné
void Afficher_Combinaison_Secrete(niveau niveau);                        // affiche la combinaison secrète
void Generation_Combinaison_Secrete(niveau *niveau);                     // génère une combinaison aléatoire

#endif
