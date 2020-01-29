#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mastermind.h"

/*****
 * "Vider_Buffer" permet tout simplement d'éviter les débordements, 
 * il ne faudrait pas qu'une valeur !en trop! soit mémorisée et mal réutilisée 
 *****/
void vider_Buffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

/*****
 * affiche d'une combinaison 
 *****/
void Affichage_Combinaison(mastermind mastermind)
{
    printf("\n| Verification |\n -> ");
    for (int i = 0; i < mastermind.niveau.pion; i++)
    {
        printf("%c ", mastermind.joueur.combinaison_Joueur[i]);
    }
}

/*****
 * détermine si la combinaison est bonne et donne des indices à l'utilisateur
 *****/
int Comparaison(mastermind mastermind)
{
    int bonnes_Reponses = 0;

    printf("\n -> ");
    for (int i = 0; i < mastermind.niveau.pion; i++)
    {
        /* pion à la bonne place */
        if (mastermind.joueur.combinaison_Joueur[i] == mastermind.niveau.combinaison_Secrete[i]) // CORRECT
        {
            printf("O ");
            bonnes_Reponses++;
        }

        /* pion faux */
        else
        {
            if (Existant(mastermind, mastermind.joueur.combinaison_Joueur[i]) == 0) // APPEL DE FONCTION
            {
                printf("X "); // n'est pas dans la combinaison secrete
            }
            else
            {
                printf("C "); // pas placé
            }
        }
    }

    return bonnes_Reponses;
}

/*****
 * - Vérifie si le pion inséré fait parti de la combinaison secrète 
 * - En récupérant le pion via les paramètres et en le comparant 
 *   à chaque pions de la combinaison secrète
 * - retourne 1 s'il existe
 *****/
int Existant(mastermind mastermind, char c)
{
    int existant = 0; // le pion n'existe pas

    for (int i = 0; i < mastermind.niveau.pion; i++)
    {
        /* compare le pion à chaque pions de la combinaison secrète */
        if (c == mastermind.niveau.combinaison_Secrete[i])
        {
            existant = 1; // le pion existe
            return existant;
        }
    }
    return existant;
}

/*****
 * sauvegarde le résultat de la partie dans le fichier "resultat.txt" 
 *****/
void Sauvegarder_Resultat(mastermind mastermind, char texte[50])
{
    /* ouverture fichier */
    if ((mastermind.out = fopen("resultat.txt", "a+")) == NULL)
    {
        printf("Erreur fichier");
    }

    /* développement */
    fputs(texte, mastermind.out);

    /* fermeture fichier */
    fclose(mastermind.out);
}

/**
 * TODO
 **/
void Stop_partie(mastermind mastermind)
{
    char resultat[100];

    if (strcmp(mastermind.joueur.combinaison_Joueur, "STOP") == 1)
    {
        if ((mastermind.out = fopen("partie_en_cours.txt", "w")) != NULL)
        {
            sprintf(resultat, "NOM : %s\nNIVEAU : %s\nCOUPS : %d/%d\nDERNIERE.COMBI : %s\nCOMBI.SECRETE : %s", mastermind.joueur.nom, mastermind.niveau.libelle, mastermind.joueur.tentative, mastermind.niveau.coup, mastermind.joueur.combinaison_Joueur, mastermind.niveau.combinaison_Secrete);
            fputs(resultat, mastermind.out);
            fclose(mastermind.out);
            printf("\nPartie sauvegardee.");
            exit(0);
        }
    }
}