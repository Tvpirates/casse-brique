#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#include "Balle.hpp"
#include "Batte.hpp"

Balle::Balle(int x, int y, int w, int h,const char* source_image,SDL_Window *window,SDL_Renderer* renderer):ObjetParent(x,y,w,h,source_image,window,renderer)
{
    pasx=1;
    pasy=1;
    collision_horizontale = SDL_TRUE;
    collision_verticale = SDL_TRUE;
}

Balle::~Balle()
{
}

void Balle::MoveHorizontale()
{
    if(collision_horizontale==SDL_TRUE)
    {
        if((rectangle.x+rectangle.w)>= WINDOW_WIDTH)
        {
            collision_horizontale = SDL_FALSE;
            rectangle.x -= pasx;
        }
        else
        {
            rectangle.x += pasy;
        }
    }

    if(collision_horizontale == SDL_FALSE)
    {
        if(rectangle.x <= 0)
        {
            collision_horizontale = SDL_TRUE;
            rectangle.x += pasx;
        }
        else
        {
            rectangle.x -= pasx;
        }
    }
}

void Balle::MoveVerticale(SDL_bool* partie_perdue)
{
    if(collision_verticale == SDL_TRUE)
    {
        if(rectangle.y <= 0)
        {
            collision_verticale = SDL_FALSE;
            rectangle.y += pasy;
        }
        else
        {
            rectangle.y -= pasy;
        }
    }

    if(collision_verticale == SDL_FALSE)
    {
        if((rectangle.y+rectangle.h) >= WINDOW_HEIGHT)
        {
            (*partie_perdue) = SDL_FALSE; // partie perdue
            collision_verticale = SDL_TRUE;
            rectangle.y -= pasy;
        }
        else
        {
            rectangle.y += pasy;
        }
        
    }
}

void Balle::Move(SDL_bool* partie_perdue)
{
    MoveHorizontale();
    MoveVerticale(partie_perdue);
}

void Balle::CollisionAvecBatte(Batte& batte)
{
    if((this->rectangle.y+this->rectangle.h) ==batte.GetY() )
    {
        if((this->rectangle.x >= (batte.GetX() - this->rectangle.w)) && (this->rectangle.x <= (batte.GetX() + batte.GetW() )) )
        {
            if( this->rectangle.x <= (batte.GetX() + (batte.GetW() / 2)) )
            {
                collision_horizontale = SDL_FALSE;
                collision_verticale = SDL_TRUE;
            }
            else
            {
                collision_horizontale = SDL_TRUE;
                collision_verticale = SDL_TRUE;
            }
            
        }
    }
}

void Balle::SetCollision_verticale(SDL_bool source)
{
    collision_verticale = source;
}

void Balle::SetCollision_horizontale(SDL_bool source)
{
    collision_horizontale = source;
}

int Balle::GetPasX()
{
    return pasx;
}

int Balle::GetPasY()
{
    return pasy;
}