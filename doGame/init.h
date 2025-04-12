#ifndef INIT_H_INCLUDED
#define INIT_H_INCLUDED

#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<SDL_mixer.h>
#include"RenderWindow.h"
#include"defs.h"
using namespace std;

bool init(){
    if(SDL_Init(SDL_INIT_VIDEO>0)) cout<<"SDL_Init HAS FAIL. SDL_ERROR: "<<SDL_GetError()<<endl;
    if(!(IMG_Init(IMG_INIT_PNG))) cout<<"IMG_Init has fail. Error: "<<SDL_GetError()<<endl;
    if(!(TTF_Init())) cout<<"TTF_Init has fail. Error: "<<SDL_GetError()<<endl;
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    return true;
}
void initGame(){
    RenderWindow window(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT);
    SDL_Texture* ballTexture=window.loadTexture("");
    SDL_Texture* holeTexture=window.loadTexture("");
    SDL_Texture* pointTexture=window.loadTexture("");
    SDL_Texture* tiledarkTexture32=window.loadTexture("");
    SDL_Texture* tiledarkTexture64=window.loadTexture("");
    SDL_Texture* tilelightTexture32=window.loadTexture("");
    SDL_Texture* tilelightTexture64=window.loadTexture("");
    SDL_Texture* ballShadowTexture=window.loadTexture("");
    SDL_Texture* bgTexture=window.loadTexture("");
    SDL_Texture* uiBgTexture=window.loadTexture("");
    SDL_Texture* levelTextBgTexture=window.loadTexture("");
    SDL_Texture* powerMeterTexture_FG=window.loadTexture("");
    SDL_Texture* powerMeterTexture_BG=window.loadTexture("");
    SDL_Texture* powerMeterTexture_overlay=window.loadTexture("");
    SDL_Texture* logoTexture=window.loadTexture("");
    SDL_Texture* click2start=window.loadTexture("");
    SDL_Texture* endscreenOverlayTexture=window.loadTexture("");
    SDL_Texture* splashBgTexture=window.loadTexture("");

    Mix_Chunk* chargeSfx=Mix_LoadWAV("");
    Mix_Chunk* swingSfx=Mix_LoadWAV("");
    Mix_Chunk* holeSfx=Mix_LoadWAV("");

    SDL_Color white=[255, 255, 255, 255];
    SDL_Color black={0, 0, 0, 0};
    TTF_Font* font32=TTF_OpenFont("", 32);
    TTF_Font* font48=TTF_OpenFont("", 48);
    TTF_Font* font24=TTF_OpenFont("", 24);
}

#endif // INIT_H_INCLUDED
