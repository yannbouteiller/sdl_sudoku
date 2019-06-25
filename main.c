
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include "constantes.h"
#include "jeu.h"
#include "editeur.h"


int main(int argc, char *argv[])
{

    SDL_Surface *ecran = NULL, *menu = NULL;
    SDL_Rect pos;
    pos.x = 0;
    pos.y = 0;
    SDL_Event event;

    int continuer = 1;


    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    ecran = SDL_SetVideoMode(LARGEUR_ECRAN, HAUTEUR_ECRAN, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

    if(ecran == NULL)
    {
        return EXIT_FAILURE;
    }

    SDL_WM_SetCaption("Sudoku", NULL);
    menu = SDL_LoadBMP ("sprites/menu.bmp");


    while(continuer)
    {
        SDL_BlitSurface (menu, NULL, ecran, &pos);
        SDL_Flip(ecran);


        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
            continuer = 0;
            break;

            case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
                case SDLK_ESCAPE:
                continuer = 0;
                break;

                case SDLK_KP1:
                jeu(ecran);
                break;

                case SDLK_KP2:
                editeur(ecran);
                break;

                default:
                break;
            }

            default:
            break;
        }
    }



    SDL_FreeSurface(menu);

    TTF_Quit();
    SDL_Quit();

    return EXIT_SUCCESS;
}
