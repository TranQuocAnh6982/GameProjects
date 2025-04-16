#ifndef RENDERWINDOW_H_INCLUDED
#define RENDERWINDOW_H_INCLUDED

#include<SDL.h>
#include<SDL_image.h>
#include<SDl_ttf.h>
#include"Entity.h"
#include"defs.h"
#include<string>
class RenderWindow{
private:
    SDL_Window* window;
    SDL_Renderer* renderer;

public:
    RenderWindow(const char* p_title, int p_w, int p_h);
    SDL_Texture* loadTexture(const char* p_filePath);
    void cleanUp();
    void clear();
    void render(Entity& p_entity);
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
        dst.x=WINDOW_WIDTH/2- src.w /2 + p_x;
        dst.y=WINDOW_HEIGHT/2- src.h /2 + p_y;
        dst.w=src.w;
        dst.h=src.h;
        SDL_RenderCopy(renderer, message, &src, &dst);
        SDL_FreeSurface(surfaceMessage);
        SDL_DestroyTexture(message);
    }
    void display(){SDL_RenderPresent(renderer);}

};


#endif // RENDERWINDOW_H_INCLUDEDinc
