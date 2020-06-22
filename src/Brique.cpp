#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#include "Brique.hpp"

Brique::Brique(int x, int y, int w, int h,const char* source_image,SDL_Window *window,SDL_Renderer* renderer, int s_resistance):ObjetParent(x,y,w,h,source_image,window,renderer)
{
    resistance = s_resistance;
}

Brique::~Brique()
{
}

int Brique::GetResistance()
{
    return resistance;
}


void Brique::collision_verticale_avec_balle(Balle& balle)
{
    if( ((balle.GetY()+balle.GetH())==this->rectangle.y) || (balle.GetY() == (this->rectangle.y + this->rectangle.h)) ) 
    {
        if(balle.GetY()+balle.GetH() == this->rectangle.y)
        {
            if( ( (balle.GetX() + balle.GetW()) >= this->rectangle.x) && (balle.GetX() <= (this->rectangle.x + this -> rectangle.w)) )  
            {
            resistance--;
            balle.SetCollision_verticale(SDL_TRUE);
            }
        }
        else
        {
            if( ( (balle.GetX() + balle.GetW()) >= this->rectangle.x) && (balle.GetX() <= (this->rectangle.x + this -> rectangle.w)) )  
            {
            resistance--;
            balle.SetCollision_verticale(SDL_FALSE);
            }
        }
    }
        
}




void Brique::collision_horizontale_avec_balle(Balle& balle)
{
    if( ((balle.GetX() + balle.GetW()) == this->rectangle.x) || (balle.GetX() == (this->rectangle.x + this->rectangle.w)) )
    {
        if( (balle.GetX() + balle.GetW()) == this->rectangle.x )
        {
            if( ((balle.GetY() + balle.GetW()) >= this->rectangle.y) && (balle.GetY() <= (this->rectangle.y + this->rectangle.h)) )
            {
                resistance--;
                balle.SetCollision_horizontale(SDL_FALSE);
            }
        }
        else
        {
            if( ((balle.GetY() + balle.GetW()) >= this->rectangle.y) && (balle.GetY() <= (this->rectangle.y + this->rectangle.h)) )
            {
                resistance--;
                balle.SetCollision_horizontale(SDL_TRUE);
            }
        }
    }
}

void Brique::collision_avec_balle(Balle& balle)
{
    collision_horizontale_avec_balle(balle);
    collision_verticale_avec_balle(balle);

}




