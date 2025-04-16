#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include<SDL.h>
#include<SDL_image.h>
#include"Math.h"

class Entity{
private:
    Vector2f pos;
    double  angle=0;
    Vector2f scale=Vector2f(1, 1);
    SDL_Rect currentFrame;
    SDL_Texture* tex;
public:
    Entity(Vector2f p_pos, SDL_Texture* p_tex);
    Vector2f& getPos(){ return pos;}
    double getAngle(){return angle;}
    Vector2f getScale(){return scale;}

    void setPos(double x, double y);
    void setScale(double w, double h);
    void setAngle(double angle);
    SDL_Texture* getTex();
    void update(double deltaTime);
    SDL_Rect getCurrentFrame();

};

#endif // ENTITY_H_INCLUDED
