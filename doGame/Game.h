#ifndef INIT_H_INCLUDED
#define INIT_H_INCLUDED

#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<SDL_mixer.h>
#include"RenderWindow.h"
#include"defs.h"
using namespace std;
class Game{
    SDL_Texture* ballTexture, holeTexture, pointTexture, tiledarkTexture32, tiledarkTexture64, tilelightTexture32,
                tilelightTexture64, ballShadowTexture,  bgTexture, uiBgTexture, levelTextBgTexture, powerMeterTexture_FG,
                powerMeterTexture_BG, powerMeterTexture_overlay, logoTexture, click2start, endscreenOverlayTexture, splashBgTexture;
    Mix_Chunk* chargeSfx, swingSfx, holeSfx;
    TTF_Font* font32, font48, font24;
    SDL_Color white=[255, 255, 255, 255];
    SDL_Color black={0, 0, 0, 0};
public:
bool init(){
    if(SDL_Init(SDL_INIT_VIDEO>0)) cout<<"SDL_Init HAS FAIL. SDL_ERROR: "<<SDL_GetError()<<endl;
    if(!(IMG_Init(IMG_INIT_PNG))) cout<<"IMG_Init has fail. Error: "<<SDL_GetError()<<endl;
    if(!(TTF_Init())) cout<<"TTF_Init has fail. Error: "<<SDL_GetError()<<endl;
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    return true;
}
void initGame(){
    RenderWindow window(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT);
     ballTexture=window.loadTexture("");
     holeTexture=window.loadTexture("");
    pointTexture=window.loadTexture("");
     tiledarkTexture32=window.loadTexture("");
     tiledarkTexture64=window.loadTexture("");
     tilelightTexture32=window.loadTexture("");
    tilelightTexture64=window.loadTexture("");
    ballShadowTexture=window.loadTexture("");
     bgTexture=window.loadTexture("");
    uiBgTexture=window.loadTexture("");
     levelTextBgTexture=window.loadTexture("");
     powerMeterTexture_FG=window.loadTexture("");
     powerMeterTexture_BG=window.loadTexture("");
     powerMeterTexture_overlay=window.loadTexture("");
     logoTexture=window.loadTexture("");
     click2start=window.loadTexture("");
     endscreenOverlayTexture=window.loadTexture("");
     splashBgTexture=window.loadTexture("");

     chargeSfx=Mix_LoadWAV("");
     swingSfx=Mix_LoadWAV("");
     holeSfx=Mix_LoadWAV("");


     font32=TTF_OpenFont("", 32);
     font48=TTF_OpenFont("", 48);
     font24=TTF_OpenFont("", 24);
}
};
#endif // INIT_H_INCLUDED
