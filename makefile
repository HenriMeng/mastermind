niveau.o : niveau.c niveau.h
joueur.o : joueur.c joueur.h
mastermind.o : mastermind.c mastermind.h joueur.h niveau.h
menu.o : menu.c menu.h mastermind.h joueur.h niveau.h
main : main.o menu.c menu.h mastermind.h joueur.h niveau.h
main.o : main.c menu.h mastermind.h joueur.h niveau.h

gcc -c -Wall niveau.c
gcc -c -Wall joueur.c
gcc -c -Wall mastermind.c
gcc -c -Wall menu.c
gcc -c -Wall main.c
gcc -o main joueur.o niveau.o mastermind.o menu.o main.o