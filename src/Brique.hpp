#ifndef Brique_hpp
#define Brique_hpp

#include <iostream>
#include <stdio.h>
#include <SDL.h>

#include "ObjetParent.hpp"
#include "Batte.hpp"
#include "Balle.hpp"

class Brique : public ObjetParent
{
    protected:
        int resistance;


    public:
        Brique(int,int,int,int,const char*, SDL_Window*,SDL_Renderer*,int);
        ~Brique();
        int GetResistance();
        void collision_verticale_avec_balle(Balle&); // Si collision verticale avec la balle, change son sens 
        void collision_horizontale_avec_balle(Balle&);// Si collision horizontale avec la balle, change son sens 
        void collision_avec_balle(Balle&); // collision_verticale + collision_horizontale
        

};

#endif 