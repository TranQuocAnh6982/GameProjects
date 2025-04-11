#ifndef HOLE_H_INCLUDED
#define HOLE_H_INCLUDED

#include<SDl.h>
#include<SDL_image.h>
#include"Math.h"
#include"Entity.h"

class Hole : public Entity{
    Hole(Vector2f _pos, SDL_Texture* _tex):Entity(p_pos, p_tex){

    }
};

#endif // HOLE_H_INCLUDED
