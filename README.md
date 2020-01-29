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
         char nom[10];               
         char combinaison_Joueur[6]; // nombre d'éléments à trouver
         int tentative;              // nombre de tentatives
     } joueur;
     ```
     
  - niveau (regroupe la difficulté, la combinaison secrète, le nombre de coups et de pions)
     ```c
     typedef struct
     {
         char nom[10];                // faudra faire un enum
         int pion;                    // nombre d'éléments à trouver
         int coup;                    // nombre de tentatives
         char combinaison_Secrete[6]; // doit être généré aléatoirement
     } niveau;
     ```
     
  - mastermind (regroupe un joueur, un niveau, un fichier)
     ```c
     typedef struct mastermind
     {
         joueur joueur; // nom - tentative - combinaison_Joueur
         niveau niveau; // nom - pion - coup - combinaison_Secrete
         FILE *out;     // fichier de sauvegarde des résultats
     } mastermind;
     ```
  


     

