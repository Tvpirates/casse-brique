#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#include "ObjetParent.hpp"



ObjetParent::ObjetParent(int x, int y, int w, int h,const char* source_image, SDL_Window *window, SDL_Renderer *renderer)
{
    rectangle.x = x;
    rectangle.y = y;
    rectangle.w = w;
    rectangle.h = h;

    surface = NULL;
    texture = NULL;


    surface = SDL_LoadBMP(source_image); // Charge l'image
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
}

ObjetParent::~ObjetParent()
{
}


void ObjetParent::Renderer(SDL_Renderer* renderer)
{

    SDL_RenderCopy(renderer,texture,NULL,&rectangle);
}

int ObjetParent::GetX()
{
    return rectangle.x;
}

int ObjetParent::GetY()
{
    return rectangle.y;
}

int ObjetParent::GetW()
{
    return rectangle.w;
}

int ObjetParent::GetH()
{
    return rectangle.h;
}

SDL_Rect ObjetParent::GetRectangle()
{
    return rectangle;
}

SDL_Texture* ObjetParent::GetTexture()
{
    return texture;
}