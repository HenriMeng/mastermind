#include <stdio.h>
#include "menu.h"

void Afficher_Menu()
{
    printf(" Mastermind :\n"
           " - 1. TUTORIEL\n"
           " - 2. JOUER\n"
           " - 3. EXIT\n\n");
}

int Saisir_Menu()
{
    int choix;

    /* récupère le choix de l'utilisateur */
    printf("Appuyez sur 1, 2 ou 3 : ");
    scanf("%d", &choix);

    return choix;
}

/***** 
 * Explication du fonctionnement du jeu 
 *****/
void Afficher_Tutoriel()
{
    printf(
        "| BUT |\n"
        " - Trouvez la combinaison secrete.\n"
        " - Selon le niveau de difficulte la combinaison varie de 4 a 6 pions\n"
        " - Chaque pion peut etre soit 'A', 'B', 'C', 'D', 'E', 'F'\n\n"
        "| INDICES |\n"
        "Lorsque que vous essayez de trouver la combinaison des indices vous seront indiques\n"
        " O -> correct\n"
        " C -> il est existant mais mal place\n"
        " X -> il n'existe pas\n\n"
        "| FINAL |\n"
        " - vous gagnez la partie lorsque que vous trouvez la combinaison secrete\n"
        " - Vous perdez lorsque que vous depassez la limite de coups qui varie selon le niveau de difficulte");
}
