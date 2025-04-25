#ifndef HOLE_H_INCLUDED
#define HOLE_H_INCLUDED

#include<SDl.h>
#include<SDL_image.h>
#include"Math.h"
#include"Entity.h"

class Hole : public Entity{
    public:
    Hole(Vector2f p_pos, SDL_Texture* p_tex):Entity(p_pos, p_tex){}
};

#endif // HOLE_H_INCLUDED
