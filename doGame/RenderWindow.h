#ifndef RENDERWINDOW_H_INCLUDED
#define RENDERWINDOW_H_INCLUDED

#include<SDL.h>
#include<SDL_image.h>
#include<SDl_ttf.h>
#include"Entity.h"
#include"defs.h"

class RenderWindow{
private:
    SDL_Window* window;
    SDL_Renderer* renderer;

public:
    RenderWindow(const char* p_title, int p_w, int p_h)
    :window(NULL), renderer(NULL)
    {
        window=SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);
        if(window==NULL){
            cout<<"Window failed to init. Error: "<<SDL_GetError()<<endl;
        }
        renderer=SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    }
    SDL_Texture* loadTexture(const char* p_filePath){
        SDL_Texture* texture=NULL;
        texture=IMG_LoadTexture(renderer, p_filePath);
        if(texture==NULL){
            cout<<"Failed to load texture. Error: "<<SDL_GetError()<<endl;
        }
          return texture;
    }
    void cleanUp(){ SDL_DestroyWindow(window);}
    void clear(){ SDL_RenderClear(renderer);}
    void render(Entity& p_entity){
        SDL_Rect src;
        src.x=p_entity.getCurrentFrame().x;
        src.y=p_entity.getCurrentFrame().y;
        src.w=p_entity.getCurrentFrame().w;
        src.h=p_entity.getCurrentFrame().h;
        SDL_Rect dst;
        dst.x=p_entity.getPos().x+(p_entity.getCurrentFrame().w- p_entity.getCurrentFrame().w* p_entity.getScale().x)/2;
        dst.y=p_entity.getPos().y+(p_entity.getCurrentFrame().h- p_entity.getCurrentFrame().h* p_entity.getScale().y)/2;
        dst.w=p_entity.getCurrentFrame().w* p_entity.getScale().x;
        dst.y=p_entity.getCurrentFrame().h* p_entity.getScale().y;
        SDL_RenderCopyEx(renderer, p_entity.getTex(), &src, &dst, p_entity.getAngle(), 0, SDL_FLIP_NONE);
    }
    void render(int x, int y, SDL_Texture* p_tex){
        SDL_Rect src;
        src.x=0;
        src.y=0;
        src.w;
        src.h;
        SDL_QueryTexture(p_tex, NULL, NULL, &src.w, &src.h);
        SDL_Rect dst;
        dst.x=x;
        dst.y=y;
        dst.w=src.w;
        dst.h=src.h;
        SDL_RenderCopy(renderer, p_tex, &src, &dst);
    }
    void render(double p_x, double p_y, const char* p_text, TTF_Font* font, SDL_Color textColor ){
        SDL_Surface* surfaceMessage=TTF_RenderText_Blended(font, p_text, textColor);
        SDL_Texture* message=SDL_CreateTextureFromSurface(renderer, surfaceMessage);
        SDL_Rect src;
        src.x=0;
        src.y=0;
        src.w=surfaceMessage->w;
        src.h=surfaceMessage->h;
        SDL_Rect dst;
        dst.x=p_x;
        dst.y=p_y;
        dst.w=src.w;
        dst.h=src.h;
        SDL_RenderCopy(renderer, message, &src, &dst);
        SDL_FreeSurface(surfaceMessage);
        SDL_DestroyTexture(message);

    }
    void renderCenter(double p_x, double p_y, const char* p_text, TTF_Font* font, SDL_Color textColor ){
        SDL_Surface* surfaceMessage=TTF_RenderText_Blended(font, p_text, textColor);
        SDL_Texture* message=SDL_CreateTextureFromSurface(renderer, surfaceMessage);
        SDL_Rect src;
        src.x=0;
        src.y=0;
        src.w=surfaceMessage->w;
        src.h=surfaceMessage->h;
        SDL_Rect dst;
        dst.x=WINDOW_WIDTH/2-src.w/2+p_x;
        dst.y=WINDOW_HEIGHT/2-src.h/2+p_y;
        dst.w=src.w;
        dst.h=src.h;
        SDL_RenderCopy(renderer, message, &src, &dst);
        SDL_FreeSurface(surfaceMessage);
        SDL_DestroyTexture(message);
    }
    void display(){SDL_RenderPresent(renderer);}

};


#endif // RENDERWINDOW_H_INCLUDEDinc
