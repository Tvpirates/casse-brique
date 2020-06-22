#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#include "Batte.hpp"


Batte::Batte(int x, int y, int w, int h,const char* source_image,SDL_Window *window,SDL_Renderer* renderer):ObjetParent(x,y,w,h,source_image,window,renderer)
{
    pas=10;
}

Batte::~Batte()
{
}

void Batte::MoveLeft()
{
    if(rectangle.x > 0)
    {
        rectangle.x -= pas;
    }
}

void Batte::MoveRight()
{
    if((rectangle.x+rectangle.w) < WINDOW_WIDTH)
    {
        rectangle.x += pas;
    }
}

