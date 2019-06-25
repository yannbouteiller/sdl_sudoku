//fichiers.c fonctions de sauvegarde et de chargement

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

int chargerGrille(int grille[9][9])
{
    FILE* fichier = NULL;
    fichier = fopen("grille_actuelle.txt", "r");
    int i = 0, j = 0;
    char ligne[9*9 + 1] = {0};

    if(fichier == NULL)
    {
        return EXIT_FAILURE;
    }

    fgets(ligne, 9*9 + 1, fichier);

    for(j=0; j<9; j++)
    {
        for(i=0; i<9; i++)
        {
            switch(ligne[i + 9*j])
            {
                case '0':
                grille[i][j] = 0;
                break;

                case '1':
                grille[i][j] = 1;
                break;

                case '2':
                grille[i][j] = 2;
                break;

                case '3':
                grille[i][j] = 3;
                break;

                case '4':
                grille[i][j] = 4;
                break;

                case '5':
                grille[i][j] = 5;
                break;

                case '6':
                grille[i][j] = 6;
                break;

                case '7':
                grille[i][j] = 7;
                break;

                case '8':
                grille[i][j] = 8;
                break;

                case '9':
                grille[i][j] = 9;
                break;

                case 'a':
                grille[i][j] = 0;
                break;

                case 'b':
                grille[i][j] = 11;
                break;

                case 'c':
                grille[i][j] = 12;
                break;

                case 'd':
                grille[i][j] = 13;
                break;

                case 'e':
                grille[i][j] = 14;
                break;

                case 'f':
                grille[i][j] = 15;
                break;

                case 'g':
                grille[i][j] = 16;
                break;

                case 'h':
                grille[i][j] = 17;
                break;

                case 'i':
                grille[i][j] = 18;
                break;

                case 'j':
                grille[i][j] = 19;
                break;

                default:
                break;
            }
        }
    }

    fclose(fichier);
    return 1;
}

int sauvegarderGrille(int grille[9][9])
{
    FILE* fichier = NULL;
    fichier = fopen("grille_actuelle.txt", "w");
    if(fichier == NULL)
    {
        return EXIT_FAILURE;
    }
    int i = 0, j = 0;

    for(j=0; j<9; j++)
    {
        for(i=0; i<9; i++)
        {
            if(grille[i][j] < 10)
            {
            fprintf(fichier, "%d", grille[i][j]);
            }
            else
            {
                switch(grille[i][j])
                {
                    case 11 :
                    fputc('b', fichier);
                    break;

                    case 12 :
                    fputc('c', fichier);
                    break;

                    case 13 :
                    fputc('d', fichier);
                    break;

                    case 14 :
                    fputc('e', fichier);
                    break;

                    case 15 :
                    fputc('f', fichier);
                    break;

                    case 16 :
                    fputc('g', fichier);
                    break;

                    case 17 :
                    fputc('h', fichier);
                    break;

                    case 18 :
                    fputc('i', fichier);
                    break;

                    case 19 :
                    fputc('j', fichier);
                    break;

                    default:
                    break;
                }
            }

        }

    }

    fclose(fichier);
    return 1;
}

