#include <stdio.h>
#include <string.h>
#include "joueur.h"

joueur Saisir_Nom_Joueur()
{
    /* déclaration du joueur */
    joueur joueur;
    joueur.tentative = 1; // initialisation à 1 !importante! pour l'incrémentation

    /* récupère le nom de l'utilisateur */
    printf("Entrez un pseudonyme : ");
    scanf("%s", joueur.nom);

    return joueur;
}

/******
 * "n" = nombre de pions (selon le niveau de difficulté)  
 ******/
void Saisir_Combinaison_Joueur(joueur *joueur, const int n)
{
    /* récupère la combinaison de l'utilisateur */
    printf("Entrez une combinaison : ");
    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &(joueur->combinaison_Joueur[i])); // attention à bien mettre le vide avant le format pour gérer les espaces que crée ENTREE
    }
}

void Incrementation_Tentative_Joueur(joueur *joueur)
{
    joueur->tentative++;
}
