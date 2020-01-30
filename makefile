main.o : main.c menu.h mastermind.h joueur.h niveau.h
gcc -o main joueur.o niveau.o mastermind.o menu.o main.o

niveau.o : niveau.c niveau.h
gcc -c -Wall niveau.c

joueur.o : joueur.c joueur.h
gcc -c -Wall joueur.c

mastermind.o : mastermind.c mastermind.h joueur.h niveau.h
gcc -c -Wall mastermind.c

menu.o : menu.c menu.h mastermind.h joueur.h niveau.h
gcc -c -Wall menu.c

main : main.o menu.c menu.h mastermind.h joueur.h niveau.h
gcc -c -Wall main.c