#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#include <iostream>
#include <stdio.h>
#include <SDL.h>

#include "Batte.hpp"
#include "Balle.hpp"
#include "Brique.hpp"
#include "MurDeBrique.hpp"

void Renderer(SDL_Renderer* renderer, Balle balle,Batte batte,MurDeBrique murdebrique)
{
    SDL_RenderClear(renderer);

    balle.Renderer(renderer);
    batte.Renderer(renderer);
    murdebrique.Renderer(renderer);

    SDL_RenderPresent(renderer);
}

void Event(SDL_Event* event, SDL_bool* program_launched, Batte &batte, Balle &balle)
{
    while(SDL_PollEvent(event)) // Attends un évènement sans bloquer le programme, sinon SDL_WaitEvent() 
    {
            

        switch(event->type)
        {
            case SDL_KEYDOWN:
                switch(event->key.keysym.sym)
                {
                    case SDLK_q: // Si appuie sur q
                        batte.MoveLeft();
                        continue;

                    case SDLK_d: // Si appuie sur d
                        batte.MoveRight();
                        continue;

                    case SDLK_LEFT:
                        batte.MoveLeft();
                        continue;

                    case SDLK_RIGHT:
                        batte.MoveRight();
                        continue;

                    default:
                        continue;
                }


            case SDL_QUIT:
                (*program_launched) = SDL_FALSE;
                break;

            default:
                break;
        }
    }

    balle.Move(program_launched);
}

void wait_debut_game(SDL_Window* window, SDL_Renderer* renderer)
{

    SDL_Rect rectangle;
    rectangle.w = WINDOW_WIDTH ;
    rectangle.h = WINDOW_HEIGHT / 2;
    rectangle.x = 0;
    rectangle.y = (WINDOW_WIDTH/ 4);

    SDL_Surface* surface;
    SDL_Texture* texture;

    surface = SDL_LoadBMP("src/affichage_debut.bmp"); // Charge l'image
    if(surface == NULL)
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);  
        SDL_Log("ERREUR : problème chargement image > %s\n",SDL_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);     
    }

    texture= SDL_CreateTextureFromSurface(renderer,surface); // Crée la texture à partir de la surface !
    SDL_FreeSurface(surface); // On peux free la surface 
    if(texture == NULL)
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);  
        SDL_Log("ERREUR : Problème création surface > %s\n", SDL_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    SDL_RenderCopy(renderer,texture,NULL,&rectangle);// On charge 

    SDL_RenderPresent(renderer); // Affiche tout le rendu 


    int continuer = 1;
    SDL_Event event;
    
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
             case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {

                    case SDLK_SPACE: // Si appuie sur espace on quitte
                        continuer=0;
                        break;
                }

            case SDL_QUIT:
                continuer=0;
                break;

            
            default:
                break;

            
        }
    }
}

void partie_perdue(SDL_Window* window, SDL_Renderer* renderer)
{
    SDL_Rect rectangle;
    rectangle.w = WINDOW_WIDTH ;
    rectangle.h = WINDOW_HEIGHT / 2;
    rectangle.x = 0;
    rectangle.y = (WINDOW_WIDTH/ 4) ;

    SDL_Surface* surface;
    SDL_Texture* texture;

    surface = SDL_LoadBMP("src/perdu.bmp"); // Charge l'image
    if(surface == NULL)
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);  
        SDL_Log("ERREUR : problème chargement image > %s\n",SDL_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);     
    }

    texture= SDL_CreateTextureFromSurface(renderer,surface); // Crée la texture à partir de la surface !
    SDL_FreeSurface(surface); // On peux free la surface 
    if(texture == NULL)
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);  
        SDL_Log("ERREUR : Problème création surface > %s\n", SDL_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    SDL_RenderCopy(renderer,texture,NULL,&rectangle);// On charge 

    SDL_RenderPresent(renderer); // Affiche tout le rendu 

    SDL_Event event;
    int continuer = 1;
    
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
             case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {

                    case SDLK_SPACE: 
                        continuer=0;
                        break;
                }

            case SDL_QUIT:
                continuer=0;
                break;

            
            default:
                break;
            
        }
    }
}

int main (int argc, char *argv[])
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) // Chargement vidéo + évènements
    {
        SDL_Log("ERREUR : Initialisation SDL > %s\n",SDL_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
    }


    if (SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer) != 0)
    {
        SDL_Log("ERREUR : Impossible de créer la fenêtre et le rendu > %s\n",SDL_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
    SDL_SetWindowTitle(window, "Casse Brique"); // Titre de la fenêtre */

    /*-----------------------------------------*/

    Batte batte(350,550,70,15,"src/batterouge.bmp",window,renderer);
    int balle_w = 20;
    int balle_y = batte.GetY()-balle_w; // pour mettre le balle sur la batte
    int balle_h = balle_w; // La balle doit avoir la même hauteur que largeur 
    int balle_x = batte.GetX() + (batte.GetW() /2) - (balle_w/2);
    Balle balle(balle_x,balle_y,20,20,"src/balle.bmp",window,renderer);
    MurDeBrique murdebrique(WINDOW_WIDTH,100,window,renderer);

    wait_debut_game(window,renderer); // On attend que l'utilisateur appuie sur espace pour lancer la partie 
    
    SDL_bool program_launched = SDL_TRUE;

    const int FPS = 120;
    const int frameDelay = 1000/ FPS;

    Uint32 frameStart;
    int frameTime;

    while(program_launched)
    {
        SDL_Event event;

        frameStart= SDL_GetTicks();
        
        Event(&event,&program_launched,batte,balle); // Fonction qui gère les évènements ( pour bouger la batte ) et bouge la balle

        balle.CollisionAvecBatte(batte); // Modifie sens de la balle si collision avec batte
        murdebrique.collision_avec_balle(balle); // Modifie le sens de la balle si collision avec une des briques du mur

        Renderer(renderer,balle,batte,murdebrique); // Fonction qui charge et affiche les rendues
        
        frameTime = SDL_GetTicks() - frameStart;

        if(frameDelay > frameTime)
        {
            SDL_Delay(frameDelay-frameTime);
        }

    }

    partie_perdue(window,renderer); // Affichage de partie perdue

    /*-----------------------------------------*/

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window); // Ferme la fenêtre
    SDL_Quit(); // Libère les ressources

    return EXIT_SUCCESS;
}
