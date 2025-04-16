#ifndef TILE_H_INCLUDED
#define TILE_H_INCLUDED

#include<SDl.h>
#include<SDL_image.h>
#include"Math.h"
#include"Entity.h"

class Tile: public Entity{

public:

 Tile(Vector2f p_pos, SDL_Texture* p_tex):Entity(p_pos, p_tex){}

};

#endif // TILE_H_INCLUDED
