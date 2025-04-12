#ifndef INIT_H_INCLUDED
#define INIT_H_INCLUDED

#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<SDL_mixer.h>
#include"RenderWindow.h"
using namespace std;

bool init(){
    if(SDL_Init(SDL_INIT_VIDEO>0)) cout<<"SDL_Init HAS FAIL. SDL_ERROR: "<<SDL_GetError()<<endl;
    if(!(IMG_Init(IMG_INIT_PNG))) cout<<"IMG_Init has fail. Error: "<<SDL_GetError()<<endl;
    if(!(TTF_Init())) cout<<"TTF_Init has fail. Error: "<<SDL_GetError()<<endl;
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    return true;
}

#endif // INIT_H_INCLUDED
