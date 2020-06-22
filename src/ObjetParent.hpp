#ifndef ObjetParent_hpp
#define ObjetParent_hpp

#include <iostream>
#include <stdio.h>
#include <SDL.h>


class ObjetParent
{
    protected:
     SDL_Surface* surface;
     SDL_Rect rectangle;
     SDL_Texture* texture;
     

     public:

     ObjetParent(int,int,int,int,const char*,SDL_Window*,SDL_Renderer*);
     ~ObjetParent();
     void Renderer(SDL_Renderer*);
     int GetX();
     int GetY();
     int GetW();
     int GetH();
     SDL_Rect GetRectangle();
     SDL_Texture* GetTexture();

};

#endif 