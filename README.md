# MASTERMIND
#mastermind 
#C 
#ESIPE


<h1> Introduction </h1>

Présentation :
 - Ecrire un programme en C implémentant le jeu Mastermind. 
 - Une boucle de jeu doit permettre de jouer autant de parties qu’il est souhaité. 
 - Une partie est une série de tentatives du joueur. 
 - La partie s’arrête lorsque la combinaison secrète est trouvée ou lorsque le nombre  de tentatives autorisées est atteint. 
 - La combinaison secrète de 4 caractères parmi 6, à trouver par le joueur, est générée aléatoirement par le programme. 
 - Les caractères possibles sont ‘A’, ‘B’, ‘C’, ‘D’, ‘E’ et ‘F’. 

Compétences utilisées :
 - [x] pointeur
 - [x] structure
 - [x] programmation modulaire
 - [x] makefile
 - [x] algorithmie
 - [x] fichier



<h1> Compréhension du code : </h1>
 
 Structures : 
 
  - joueur (regroupe le nom, la combinaison, le nombres de tentatives du joueur)
     ```c
     typedef struct
     {
         char nom[10];               // speudo
         char combinaison_Joueur[6]; // combinaison du joueur
         int tentative;              // nombre de tentatives réalisées
     } joueur;
     ```
     
  - niveau
     ```c
     typedef struct
     {
         char nom[10];                // libellé difficulté FACILE - INTERMEDIAIRE - DIFFICILE
         int pion;                    // nombre d'éléments à trouver
         int coup;                    // nombre de tentatives autorisées
         char combinaison_Secrete[6]; // combinaison aléatoire à trouver
     } niveau;
     ```
     
  - mastermind
     ```c
     typedef struct mastermind
     {
         joueur joueur; // nom - combinaison_Joueur - tentative
         niveau niveau; // nom - pion - coup - combinaison_Secrete
         FILE *out;     // fichier de sauvegarde des résultats
     } mastermind;
     ```
  


     

