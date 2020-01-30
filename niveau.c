#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "niveau.h"

void Afficher_Niveaux()
{ 
    printf(" Niveau de difficulte :\n"
           " - 1. FACILE\n"
           " - 2. INTERMEDIAIRE\n"
           " - 3. DIFFICILE\n\n");
}

int Saisir_Niveau()
{
    /* récupère le choix de l'utilisateur */
    int choix;
    printf("Appuyez sur 1, 2 ou 3 : ");
    scanf("%d", &choix);
    return choix;
}

/**
 * modifie les attributs nom - pion - coup
 **/
void Modifier_Niveau(niveau *niveau, char *libelle, int pion, int coup)
{
    strcpy(niveau->libelle, libelle);
    niveau->pion = pion;
    niveau->coup = coup;
}

void Afficher_Combinaison_Secrete(niveau niveau)
{
    for (int i = 0; i < niveau.pion; i++)
    {
        printf(" %c", niveau.combinaison_Secrete[i]);
    }
}

/**
 * Utilisation de srand() pour générer une combinaison aléatoire 
 **/
void Generation_Combinaison_Secrete(niveau *niveau)
{
    char ascii = 'A';
    time_t t;

    /* initialisation du générateur de nombre aléatoire */
    srand((unsigned)time(&t));

    /* génère des valeurs aléatoires et les insère dans la combinaison secrète */
    for (int i = 0; i < niveau->pion; i++)
    {
        niveau->combinaison_Secrete[i] = ascii + rand() % 6; // ascii + un nombre entre 0 - 5
    }
}
