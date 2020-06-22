#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#include "MurDeBrique.hpp"

MurDeBrique::MurDeBrique(int longueur_totale, int hauteur_totale,SDL_Window *window,SDL_Renderer* renderer)
{
    lignes=4;
    colonnes=10;

    int pas_y_brique = hauteur_totale/lignes;
    int pas_x_brique = longueur_totale/colonnes;

    
    int y_brique = 0;
    int x_brique = 0;
    int i = 0;
    int j = 0;
    int resistance =1;

    const char* chemin = "src/brique1.bmp";

    for(i = 0; i<lignes; i++)
    {
        for(j = 0; j< colonnes;j++)
        {
            tableau [i][j] = new Brique(x_brique,y_brique,pas_x_brique,pas_y_brique,chemin,window,renderer,resistance);
            x_brique += pas_x_brique;
        }

        y_brique += pas_y_brique;
        x_brique = 0;

    }

    
}

MurDeBrique::~MurDeBrique()
{
}

void MurDeBrique::Renderer(SDL_Renderer* renderer)
{
    int i;
    int j;

    for(i=0 ; i< lignes ; i++)
    {
        for( j=0 ; j < colonnes ; j++)
        {
            if( tableau[i][j]->GetResistance() >= 1)
            {
                tableau[i][j]->Renderer(renderer);
                SDL_Rect temp = tableau[i][j]->GetRectangle();
                SDL_Texture* texture_temp = tableau[i][j]->GetTexture();
                SDL_RenderCopy(renderer,texture_temp,NULL,&(temp));
            }
        }
    }

}

void MurDeBrique::collision_avec_balle(Balle& balle,SDL_bool* partie_gagne)
{
    int i;
    int j;

    (*partie_gagne) = SDL_TRUE;

    for(i=0 ; i< lignes ; i++)
    {
        for( j=0 ; j < colonnes ; j++)
        {
            if( tableau[i][j]->GetResistance() >= 1)
            {
                (*partie_gagne) = SDL_FALSE; // Si on rentre une fois c'est que la partie n'est pas finis
                tableau[i][j]->collision_avec_balle(balle);
            }
        }
    }
}