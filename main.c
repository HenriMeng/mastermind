#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

/* PROTYPES ########################################################## */

void Affichage_Resultats(int argc, char *argv[]);            // affiche le dernier résultat si un deuxième argument est écrit lors de l'exécution du programme
void Separateur();                                           // esthetique
void Appel_Menu(int *choix);                                 // appels de méthodes faisant le menu
void Gestion_Choix_Menu(int choix);                          // dirige l'utilisateur selon son choix : tuto - jeu - sortie
void Appel_Mastermind();                                     // appels de méthodes faisant le Mastermind
void Appel_Niveau(mastermind mastermind);                    // appels de méthodes gérant le niveau choisi du Mastermind
void Gestion_Choix_Niveau(mastermind mastermind, int choix); // modifie les paramètres du jeu selon la difficulté choisie
void Lancement_Mastermind(mastermind mastermind);            // Mastermind

/* MAIN ############################################################## */

int main(int argc, char *argv[])
{
    int choix = 0;

    Affichage_Resultats(argc, argv);

    for (;;) // boucle infinie
    {
        Appel_Menu(&choix);
        Gestion_Choix_Menu(choix);
    }

    return 0;
}

/* FONCTIONS ######################################################### */

/*****
 * affiche le dernier résultat si un deuxième argument est écrit lors de l'exécution du programme. 
 *****/
void Affichage_Resultats(int argc, char *argv[])
{
    FILE *in = fopen("resultat.txt", "r");
    char texte[100];

    if (argc > 1)
    {
        if ((fgets(texte, 100, in)) != NULL)
        {
            printf("\n\nDernier resultat : %s", texte);
        }
    }

    fclose(in);
}

/* Une simple barre :) */
void Separateur()
{
    printf("\n________________________________________\n\n");
}

/** 
 * Affichage menu
 * Choix 
 **/
void Appel_Menu(int *choix)
{
    Separateur();
    Afficher_Menu();
    *choix = Saisir_Menu();
    Separateur();
}

/** 
 * récupère le choix lors de l'affichage du menu
 * renvoie la fonction adéquate
 **/
void Gestion_Choix_Menu(int choix)
{
    switch (choix)
    {
    case 1: // affiche le tutoriel
        Afficher_Tutoriel();
        break;
    case 2: // lance le mastermind
        Appel_Mastermind();
        break;
    case 3: // quitte le programme
        printf("Au revoir");
        Separateur();
        exit(0);
    default: // autres
        printf("Choix incorrect.");
        break;
    }
}

void Appel_Mastermind()
{
    /* déclaration variables*/
    mastermind mastermind;

    /* demande un pseudonyme */
    mastermind.joueur = Saisir_Nom_Joueur();
    Separateur();

    /* mastermind -> niveau */
    Appel_Niveau(mastermind);
}

void Appel_Niveau(mastermind mastermind)
{
    int choix;

    /* demande niveau + lancement du mastermind */
    Afficher_Niveaux();
    choix = Saisir_Niveau();
    Gestion_Choix_Niveau(mastermind, choix);
}

void Gestion_Choix_Niveau(mastermind mastermind, int choix)
{
    /* modifie niveau-> nom - pion - coup */
    switch (choix)
    {
    case 1: // niveau facile
        Modifier_Niveau(&mastermind.niveau, "FACILE", 4, 10);
        Generation_Combinaison_Secrete(&mastermind.niveau);
        Separateur();
        /* affiche règles et lance le Mastermind */
        printf("| Niveau %s |\n%s, tu as %d coups pour trouver la combinaison secrete de %d pions", mastermind.niveau.libelle, mastermind.joueur.nom, mastermind.niveau.coup, mastermind.niveau.pion);
        Lancement_Mastermind(mastermind);
        break;

    case 2: // niveau intermédiaire
        Modifier_Niveau(&mastermind.niveau, "INTERMEDIAIRE", 5, 8);
        Generation_Combinaison_Secrete(&mastermind.niveau);
        Separateur();
        /* affiche règles et lance le Mastermind */
        printf("| Niveau %s |\n%s, tu as %d coups pour trouver la combinaison secrete de %d pions", mastermind.niveau.libelle, mastermind.joueur.nom, mastermind.niveau.coup, mastermind.niveau.pion);
        Lancement_Mastermind(mastermind);
        break;

    case 3: // niveau difficile
        Modifier_Niveau(&mastermind.niveau, "DIFFICILE", 6, 6);
        Generation_Combinaison_Secrete(&mastermind.niveau);
        Separateur();
        /* affiche règles et lance le Mastermind */
        printf("| Niveau %s |\n%s, tu as %d coups pour trouver la combinaison secrete de %d pions", mastermind.niveau.libelle, mastermind.joueur.nom, mastermind.niveau.coup, mastermind.niveau.pion);
        Lancement_Mastermind(mastermind);
        break;

    default:
        Separateur();
        printf("Votre choix est incorrecte.");
        Separateur();
        Appel_Niveau(mastermind);
        break;
    }
}

/**
 * demande une combinaison à l'utilisateur
 * compte le nombre de coup réalisé
 * compare les deux combinaisons
 * affiche un résultat
 **/
void Lancement_Mastermind(mastermind mastermind)
{
    int bonnes_Reponses = 0;
    char resultat[50];

    /* boucle autant de fois que le nombre de coups possible */
    for (int i = 0; i <= mastermind.niveau.coup; i++)
    {
        Separateur();

        /* L'utilisateur a GAGNE */
        if (bonnes_Reponses == mastermind.niveau.pion) // nombre de bonnes réponses = nombre de pions à trouvés
        {
            /* stocke le résultat dans "résultat" */
            sprintf(resultat, "%s -> GAGNE (NIVEAU %s) -> %d coups\n", mastermind.joueur.nom, mastermind.niveau.libelle, mastermind.joueur.tentative);
            Sauvegarder_Resultat(mastermind, resultat);

            /* affiche le résultat */
            printf("%s", resultat);
            break;
        }

        /* L'utilisateur a PERDU */
        else if (mastermind.joueur.tentative > mastermind.niveau.coup)
        {
            /* stocke le résultat dans "résultat" */
            sprintf(resultat, "%s -> PERDU (NIVEAU %s)\n", mastermind.joueur.nom, mastermind.niveau.libelle);
            Sauvegarder_Resultat(mastermind, resultat);

            /* affiche le résultat */
            printf("%s -> PERDU (NIVEAU %s) -> la combinaison secrete etait : ", mastermind.joueur.nom, mastermind.niveau.libelle);
            Afficher_Combinaison_Secrete(mastermind.niveau);
            break;
        }

        /* L'utilisateur JOUE */
        else
        {
            /* demande une combinaison et compte le nombre de tentative */
            Saisir_Combinaison_Joueur(&mastermind.joueur, mastermind.niveau.pion);
            Incrementation_Tentative_Joueur(&mastermind.joueur);

            /* affiche les indices */
            Affichage_Combinaison(mastermind);
            bonnes_Reponses = Comparaison(mastermind);
        }
        vider_Buffer(); // mesure de sécurité
    }
}