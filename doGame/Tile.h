#ifndef TILE_H_INCLUDED
#define TILE_H_INCLUDED

#include<SDl.h>
#include<SDL_image.h>
#include"Math.h"
#include"Entity.h"

class Tile: public Entity{
SDL_Texture* tiledarkTexture64, *tiledarkTexture32, *tilelightTexture64, *tilelightTexture32;
int level;
public:
 Tile(Vector2f p_pos, SDL_Texture* p_tex):Entity(p_pos, p_tex){}
     vector<Tile> loadTiles(){
        vector<Tile> temp={};
        switch(level){
        case 0:
            temp.push_back(Tile(Vector2f(64*3, 64*3), tiledarkTexture64));
            temp.push_back(Tile(Vector2f(64*4, 64*3), tiledarkTexture64));

            temp.push_back(Tile(Vector2f(64*0, 64*3), tiledarkTexture64));
            temp.push_back(Tile(Vector2f(64*1, 64*3), tiledarkTexture64));

            temp.push_back(Tile(Vector2f(64*3+64*5, 64*3), tilelightTexture64));
            temp.push_back(Tile(Vector2f(64*4+64*5, 64*3), tilelightTexture64));

            temp.push_back(Tile(Vector2f(64*0+64*5, 64*3), tilelightTexture64));
            temp.push_back(Tile(Vector2f(64*1+64*5, 64*3), tilelightTexture64));
        break;
        case 1:
            temp.push_back(Tile(Vector2f(64*2, 64*3), tiledarkTexture64));
            temp.push_back(Tile(Vector2f(64*4+64*5, 64*3), tilelightTexture64));
        break;
        case 2:
             temp.push_back(Tile(Vector2f(32*1+32*10+16, 32*5), tilelightTexture32));
        break;
        case 3:
            temp.push_back(Tile(Vector2f(32*4, 32*7), tiledarkTexture64));
            temp.push_back(Tile(Vector2f(32*3, 32*5), tiledarkTexture32));
            temp.push_back(Tile(Vector2f(32*6, 32*3), tiledarkTexture32));

            temp.push_back(Tile(Vector2f(32*4+ 64*5, 32*2), tilelightTexture64));
            temp.push_back(Tile(Vector2f(32*3+ 32*10, 32*6), tilelightTexture32));
            temp.push_back(Tile(Vector2f(32*6+ 32*10, 32*9), tilelightTexture32));
        break;
        case 4:
            temp.push_back(Tile(Vector2f(32*3, 32*1), tiledarkTexture32));
            temp.push_back(Tile(Vector2f(32*1, 32*3), tiledarkTexture32));
            temp.push_back(Tile(Vector2f(32*5, 32*3), tiledarkTexture32));
            temp.push_back(Tile(Vector2f(32*3, 32*5), tiledarkTexture32));
            temp.push_back(Tile(Vector2f(32*7, 32*5), tiledarkTexture32));
            temp.push_back(Tile(Vector2f(32*7, 32*10), tiledarkTexture32));
            temp.push_back(Tile(Vector2f(32*3, 32*10), tiledarkTexture32));
            temp.push_back(Tile(Vector2f(32*5, 32*12), tiledarkTexture32));
            temp.push_back(Tile(Vector2f(32*7, 32*10), tiledarkTexture32));

            temp.push_back(Tile(Vector2f(32*8, 32*7), tiledarkTexture64));

            temp.push_back(Tile(Vector2f(32*2+32*10, 32*2), tilelightTexture32));
            temp.push_back(Tile(Vector2f(32*5+32*10, 32*11), tilelightTexture32));

            temp.push_back(Tile(Vector2f(32*3+32*10, 32*1), tilelightTexture64));
            temp.push_back(Tile(Vector2f(32*8+32*10, 32*6), tilelightTexture64));
            temp.push_back(Tile(Vector2f(32*3+32*10, 32*11), tilelightTexture64));
        break;
        }
    return temp;
  }
};

#endif // TILE_H_INCLUDED
