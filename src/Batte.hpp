#ifndef Batte_hpp
#define Batte_hpp

#include <iostream>
#include <stdio.h>
#include <SDL.h>

#include "ObjetParent.hpp"

class Batte : public ObjetParent
{
    protected:
        int pas;

    public:
        Batte(int,int,int,int,const char*, SDL_Window*,SDL_Renderer*);
        ~Batte();
        void MoveLeft(); 
        void MoveRight();
};

#endif 