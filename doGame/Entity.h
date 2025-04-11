#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include<SDL.h>
#include<SDL_image.h>
#include"Math.h"

class Entity{
private:
    Vector2f pos;
    double  angle=0;
    Vector2 scale=Vector2f(1, 1);
    SDL_Rect currentFrame;
    SDL_Texture* tex;
public:
    Entity(Vector2f _pos, SDL_Texture _tex):pos(p_pos), tex(p_tex){
        currentFrame.x=0;
        currentFrame.y=0;
        currentFrame.w=32;
        currentFrame.h=32;
        SDL_QueryTexture(p_tex, NULL, NULL, &currentFrame.w, &currentFrame.y);

    }
    Vector2f& getPos(){ return pos;}
    double getAngle(){return angle;}
    Vector2f getScale(){return scale;}
    void setPos(double x, double y){ pos.x=x; pos.y=y;}
    void setScale(double w, double h){scale.x=w; scale.y=h;}
    void setAngle(double p_angle){angle=p_angle;}
    SDL_Texture* getTex(){return tex;}
    void update(double deltaTime){}
    SDL_Rect getCurrentFrame(){return currentFrame;}

};

#endif // ENTITY_H_INCLUDED
