#ifndef Balle_hpp
#define Balle_hpp

#include <iostream>
#include <stdio.h>
#include <SDL.h>

#include "ObjetParent.hpp"
#include "Batte.hpp"

class Balle : public ObjetParent
{
    protected:
        int pasx;
        int pasy;
        SDL_bool collision_verticale;
        SDL_bool collision_horizontale;

    public:
        Balle(int,int,int,int,const char*, SDL_Window*,SDL_Renderer*);
        ~Balle();
        void MoveHorizontale(); 
        void MoveVerticale(SDL_bool*);
        void Move(SDL_bool*); // Horizontale + verticale. Modifie sens de la balle lorsqu'elle touche un coin. Si elle touche le bas partie perdue grâce au booléen
        void CollisionAvecBatte(Batte&); // Modifie sens de la balle lorsqu'elle touche la batte.
        void SetCollision_verticale(SDL_bool);
        void SetCollision_horizontale(SDL_bool);
        int GetPasX();
        int GetPasY();

};

#endif 