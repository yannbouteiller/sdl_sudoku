all: editeur.o fichiers.o fonctions.o jeu.o main.o sudoku

editeur.o : editeur.c editeur.h
	gcc -Wall -o editeur.o -c editeur.c -lm -lSDLmain -lSDL -lSDL_ttf

fichiers.o : fichiers.c fichiers.h
	gcc -Wall -o fichiers.o -c fichiers.c -lm -lSDLmain -lSDL -lSDL_ttf

fonctions.o : fonctions.c fonctions.h
	gcc -Wall -o fonctions.o -c fonctions.c -lm -lSDLmain -lSDL -lSDL_ttf

jeu.o : jeu.c jeu.h
	gcc -Wall -o jeu.o -c jeu.c -lm -lSDLmain -lSDL -lSDL_ttf

main.o : main.c constantes.h jeu.h editeur.h
	gcc -Wall -o main.o -c main.c -lm -lSDLmain -lSDL -lSDL_ttf

sudoku : editeur.o fichiers.o fonctions.o jeu.o main.o
	gcc -Wall -o sudoku main.o editeur.o fichiers.o fonctions.o jeu.o -lm -lSDLmain -lSDL -lSDL_ttf

clean:
	rm -rf *.o
