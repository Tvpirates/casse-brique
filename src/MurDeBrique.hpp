#ifndef MurDeBrique_hpp
#define MurDeBrique_hpp

#include <iostream>
#include <stdio.h>
#include <SDL.h>

#include "ObjetParent.hpp"
#include "Batte.hpp"
#include "Brique.hpp"
#include "Balle.hpp"

class MurDeBrique
{
    protected:
        int lignes;
        int colonnes;
        Brique* tableau[4][10]; // Problème de gestion de tableau donc tableau statique.
        /* Je voulais gérer avec tableau dynamique Brique*** mais problème dans le constructeur,
            si je fais tableau = new Brique[lignes][colonnes] il n'accepte pas, pas le temps de trouver l'erreur :(
            Cela aurait permis de modifier le nombre de lignes de briques et le nombre de briques par colonne dans l'appel du constructeur
        */
        int longueur;
        int hauteur;



    public:
        MurDeBrique(int,int,SDL_Window*,SDL_Renderer*);
        ~MurDeBrique();
        void Renderer(SDL_Renderer*); 
        void collision_avec_balle(Balle& balle,SDL_bool*); // Modifie sens de la balle lorsqu'elle touche une brique
        
        

};

#endif 