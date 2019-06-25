//jeu.c fonction principale jeu et associées.

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

#include "constantes.h"
#include "fichiers.h"
#include "jeu.h"
#include "fonctions.h"


void jeu(SDL_Surface* ecran)
{
    SDL_Surface *menuJeu1 = NULL, *menuJeu2 = NULL, *fond = NULL;
    SDL_Surface *n[9] = {NULL};
    SDL_Surface *r[9] = {NULL};
    SDL_Surface *select = NULL;
    SDL_Rect pos; //position de l'écran
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
    int continuer = 1;
    int terminer = 0; //renvoie au menu principal
    int mode1 = 0, mode2 = 0;
    int grille[9][9] = {{0}};

    SDL_EnableKeyRepeat(100, 100);

    // chargement des sprites

    menuJeu1 = SDL_LoadBMP("sprites/menuJeu1.bmp");
    menuJeu2 = SDL_LoadBMP("sprites/menuJeu2.bmp");
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

    // Menus 1 et 2 :

    SDL_BlitSurface(menuJeu1, NULL, ecran, &pos);
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

    continuer = 1;

    SDL_BlitSurface(menuJeu2, NULL, ecran, &pos);
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

                case SDLK_q :
                terminer = 1;
                break;

                case SDLK_KP1 :
                mode1 = 1;
                mode2 = 0;
                continuer = 0;
                break;

                case SDLK_KP2:
                mode2 = 1;
                mode1 = 0;
                continuer = 0;
                break;

                default:
                break;
            }

            default:
            break;

        }
    }
    continuer = 1;

    // En avant !

    if(!terminer)
    {
        SDL_BlitSurface(fond, NULL, ecran, &pos);
        SDL_Flip(ecran);

        if(mode1)
        {
            //charger grille
            if(!chargerGrille(grille))
            {
            terminer = 1;
            }

        }

        else if(mode2)
        {
            ; //générer grille
        }

        else
        {
            terminer = 1;
        }

        SDL_Flip(ecran);

    }



    // Boucle principale jeu

    while(!terminer)
    {
        //début de la boucle principale jeu

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
                case SDLK_ESCAPE :
                terminer = 1;
                break;

                case SDLK_q :
                terminer = 1;
                break;

                case SDLK_s :
                sauvegarderGrille(grille); // "s" envoie la grille affichée à sauvegarderGrille
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
                if (grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] <= 9)
                grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] = 0;
                break;

                case SDLK_KP1 :
                if (grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] <= 9)
                grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] = 1;
                break;

                case SDLK_KP2 :
                if (grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] <= 9)
                grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] = 2;
                break;

                case SDLK_KP3 :
                if (grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] <= 9)
                grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] = 3;
                break;

                case SDLK_KP4 :
                if (grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] <= 9)
                grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] = 4;
                break;

                case SDLK_KP5 :
                if (grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] <= 9)
                grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] = 5;
                break;

                case SDLK_KP6 :
                if (grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] <= 9)
                grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] = 6;
                break;

                case SDLK_KP7 :
                if (grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] <= 9)
                grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] = 7;
                break;

                case SDLK_KP8 :
                if (grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] <= 9)
                grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] = 8;
                break;

                case SDLK_KP9 :
                if (grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] <= 9)
                grille[(selection.x/TAILLE_CASE)][(selection.y/TAILLE_CASE)] = 9;
                break;

                default:
                break;
            }
            break;

            default:
            break;

        }


        //Blit général


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

        if(verifierGrille(grille))
        {
            terminer = 1;
        }

        //fin de la boucle principale jeu
    }




    SDL_FreeSurface(menuJeu1);
    SDL_FreeSurface(menuJeu2);
    SDL_FreeSurface(fond);
    SDL_FreeSurface(select);

    for(i=1; i<=9; i++)
    {
        SDL_FreeSurface(r[i]);
        SDL_FreeSurface(n[i]);
    }

}
