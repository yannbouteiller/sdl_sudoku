//editeur.c fonction d'edition du fichier GrilleActuelle

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

#include "constantes.h"
#include "fichiers.h"
#include "editeur.h"
#include "fonctions.h"


void editeur(SDL_Surface* ecran)
{
    SDL_Surface *fond = NULL;
    SDL_Surface *menuEditeur = NULL;
    SDL_Surface *n[9] = {NULL};
    SDL_Surface *r[9] = {NULL};
    SDL_Surface *select = NULL;
    SDL_Rect pos; //position de l'�cran
    pos.x = 0;
    pos.y = 0;
    SDL_Rect position;
    position.x = 0;
    position.y = 0;
    SDL_Rect selection; //position du cadre de selection
    selection.x = 1;
    selection.y = 1;
    SDL_Event event;
    int i = 0;
    int j = 0;
    int shift = 0;
    int continuer = 1;
    int terminer = 0; //renvoie au menu principal
    int grille[9][9] = {{0}};

    Uint8 *keystates = NULL;


    SDL_EnableKeyRepeat(100, 100);

    // chargement des sprites

    menuEditeur = SDL_LoadBMP("sprites/menuEditeur.bmp");
    fond = SDL_LoadBMP("sprites/grille.bmp");
    select = SDL_LoadBMP("sprites/select.bmp");
    SDL_SetColorKey(select, SDL_SRCCOLORKEY, SDL_MapRGB(select->format, 255, 255, 255));


    n[1] = SDL_LoadBMP("sprites/1n.bmp");
    n[2] = SDL_LoadBMP("sprites/2n.bmp");
    n[3] = SDL_LoadBMP("sprites/3n.bmp");
    n[4] = SDL_LoadBMP("sprites/4n.bmp");
    n[5] = SDL_LoadBMP("sprites/5n.bmp");
    n[6] = SDL_LoadBMP("sprites/6n.bmp");
    n[7] = SDL_LoadBMP("sprites/7n.bmp");
    n[8] = SDL_LoadBMP("sprites/8n.bmp");
    n[9] = SDL_LoadBMP("sprites/9n.bmp");

    r[1] = SDL_LoadBMP("sprites/1r.bmp");
    r[2] = SDL_LoadBMP("sprites/2r.bmp");
    r[3] = SDL_LoadBMP("sprites/3r.bmp");
    r[4] = SDL_LoadBMP("sprites/4r.bmp");
    r[5] = SDL_LoadBMP("sprites/5r.bmp");
    r[6] = SDL_LoadBMP("sprites/6r.bmp");
    r[7] = SDL_LoadBMP("sprites/7r.bmp");
    r[8] = SDL_LoadBMP("sprites/8r.bmp");
    r[9] = SDL_LoadBMP("sprites/9r.bmp");

    AnalyseGrille Analyse = {0,{{0}},{{0}}}; //contiendra tous les r�sultats d'analyserGrille

    SDL_BlitSurface(menuEditeur, NULL, ecran, &pos);
    SDL_Flip(ecran);

    while(continuer && !terminer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT :
            terminer = 1;
            break;

            case SDL_KEYDOWN :
            switch(event.key.keysym.sym)
            {
                case SDLK_ESCAPE :
                terminer = 1;
                break;

                case SDLK_RETURN :
                continuer = 0;
                break;

                default:
                break;
            }

            default:
            break;

        }
    }

    SDL_BlitSurface(fond, NULL, ecran, &pos);
    SDL_Flip(ecran);

        //charger grille
        if(!chargerGrille(grille))
        {
            terminer = 1;
        }


    // Boucle principale editeur

    while(!terminer)
    {
        keystates = SDL_GetKeyState( NULL );
        if (keystates[SDLK_RCTRL] || keystates[SDLK_LCTRL])
        {
            shift = 1;
        }
        else
        {
            shift = 0;
        }

        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT :
            terminer = 1;
            break;

            case SDL_MOUSEBUTTONDOWN :
            switch(event.button.button)
            {
                case SDL_BUTTON_LEFT :

                    if(event.button.x < TAILLE_GRILLE && event.button.y < TAILLE_GRILLE)
                    {
                        selection.x = (event.button.x - (event.button.x % TAILLE_CASE)) + 1;
                        selection.y = (event.button.y - (event.button.y % TAILLE_CASE)) + 1;
                    }


                break;

                default:
                break;
            }
            break;

            case SDL_KEYDOWN :
            switch(event.key.keysym.sym)
            {

                case SDLK_DELETE :
                for(i=0;i<9;i++)
                {
                    for(j=0;j<9;j++)
                    {
                        grille[i][j] = 0;
                    }
                }
                break;

                case SDLK_ESCAPE :
                terminer = 1;
                break;

                case SDLK_q :
                terminer = 1;
                break;

                case SDLK_s :
                sauvegarderGrille(grille); // "s" envoie la grille affich�e � sauvegarderGrille
                break;

                case SDLK_l :
                if(!chargerGrille(grille))
                {
                    terminer = 1;
                }
                break;

                case SDLK_UP :
                if(selection.y >= TAILLE_CASE)
                {
                    selection.y = selection.y - TAILLE_CASE;
                }
                break;

                case SDLK_DOWN :
                if(selection.y <= (8 * TAILLE_CASE))
                {
                    selection.y = selection.y + TAILLE_CASE;
                }
                break;

                case SDLK_LEFT :
                if(selection.x >= TAILLE_CASE)
                {
                    selection.x = selection.x - TAILLE_CASE;
                }
                break;

                case SDLK_RIGHT :
                if(selection.x <= (8 * TAILLE_CASE))
                {
                    selection.x = selection.x + TAILLE_CASE;
                }
                break;

                case SDLK_KP0 :
                grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] = 0;
                break;

                case SDLK_KP1 :
                if(shift)
                {
                    grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] = 11;
                }
                else
                {
                    grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] = 1;
                }
                break;

                case SDLK_KP2 :
                if(shift)
                {
                    grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] = 12;
                }
                else
                {
                    grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] = 2;
                }
                break;

                case SDLK_KP3 :
                if(shift)
                {
                    grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] = 13;
                }
                else
                {
                    grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] = 3;
                }
                break;

                case SDLK_KP4 :
                if(shift)
                {
                    grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] = 14;
                }
                else
                {
                    grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] = 4;
                }
                break;

                case SDLK_KP5 :
                if(shift)
                {
                    grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] = 15;
                }
                else
                {
                    grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] = 5;
                }
                break;

                case SDLK_KP6 :
                if(shift)
                {
                    grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] = 16;
                }
                else
                {
                    grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] = 6;
                }
                break;

                case SDLK_KP7 :
                if(shift)
                {
                    grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] = 17;
                }
                else
                {
                    grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] = 7;
                }
                break;

                case SDLK_KP8 :
                if(shift)
                {
                    grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] = 18;
                }
                else
                {
                    grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] = 8;
                }
                break;

                case SDLK_KP9 :
                if(shift)
                {
                    grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] = 19;
                }
                else
                {
                    grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] = 9;
                }
                break;

                case SDLK_b :
                grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] = 11;
                break;

                case SDLK_c :
                grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] = 12;
                break;

                case SDLK_d :
                grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] = 13;
                break;

                case SDLK_e :
                grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] = 14;
                break;

                case SDLK_f :
                grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] = 15;
                break;

                case SDLK_g :
                grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] = 16;
                break;

                case SDLK_h :
                grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] = 17;
                break;

                case SDLK_i :
                grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] = 18;
                break;

                case SDLK_j :
                grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] = 19;
                break;

                case SDLK_LALT :
                analyserGrille(grille, &Analyse);
                for(j=0;j<9;j++)
                {
                    for(i=0;i<9;i++)
                    {
                        grille[i][j] = Analyse.grilleSoute[i][j];
                    }
                }
                break;

                case SDLK_TAB :
                for(j=0;j<9;j++)
                {
                    for(i=0;i<9;i++)
                    {
                        if(grille[i][j] < 10)
                        {
                            grille[i][j] =  0;
                        }
                    }
                }
                break;

                default:
                break;
            }
            break;

            default:

            break;

        }


        //Blit g�n�ral


        SDL_BlitSurface(fond, NULL, ecran, &pos);

        for(j=0; j<9; j++)
        {
            for(i=0; i<9; i++)
            {
                position.x = i*TAILLE_CASE + 1;
                position.y = j*TAILLE_CASE + 1;

                switch(grille[i][j])
                {
                    case 0 :
                    break;

                    case 1 :
                    SDL_BlitSurface(n[1], NULL, ecran, &position);
                    break;

                    case 2 :
                    SDL_BlitSurface(n[2], NULL, ecran, &position);
                    break;

                    case 3 :
                    SDL_BlitSurface(n[3], NULL, ecran, &position);
                    break;

                    case 4 :
                    SDL_BlitSurface(n[4], NULL, ecran, &position);
                    break;

                    case 5 :
                    SDL_BlitSurface(n[5], NULL, ecran, &position);
                    break;

                    case 6 :
                    SDL_BlitSurface(n[6], NULL, ecran, &position);
                    break;

                    case 7 :
                    SDL_BlitSurface(n[7], NULL, ecran, &position);
                    break;

                    case 8 :
                    SDL_BlitSurface(n[8], NULL, ecran, &position);
                    break;

                    case 9 :
                    SDL_BlitSurface(n[9], NULL, ecran, &position);
                    break;

                    case 11 :
                    SDL_BlitSurface(r[1], NULL, ecran, &position);
                    break;

                    case 12 :
                    SDL_BlitSurface(r[2], NULL, ecran, &position);
                    break;

                    case 13 :
                    SDL_BlitSurface(r[3], NULL, ecran, &position);
                    break;

                    case 14 :
                    SDL_BlitSurface(r[4], NULL, ecran, &position);
                    break;

                    case 15 :
                    SDL_BlitSurface(r[5], NULL, ecran, &position);
                    break;

                    case 16 :
                    SDL_BlitSurface(r[6], NULL, ecran, &position);
                    break;

                    case 17 :
                    SDL_BlitSurface(r[7], NULL, ecran, &position);
                    break;

                    case 18 :
                    SDL_BlitSurface(r[8], NULL, ecran, &position);
                    break;

                    case 19 :
                    SDL_BlitSurface(r[9], NULL, ecran, &position);
                    break;

                    default :
                    break;
                }
            }
        }

        SDL_BlitSurface(select, NULL, ecran, &selection);
        SDL_Flip(ecran);

        //fin de la boucle principale jeu
    }




    SDL_FreeSurface(fond);
    SDL_FreeSurface(select);

    for(i=1; i<=9; i++)
    {
        SDL_FreeSurface(r[i]);
        SDL_FreeSurface(n[i]);
    }

}
