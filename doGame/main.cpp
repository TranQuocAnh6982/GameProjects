#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<SDL_mixer.h>
#include "Math.h"
#include "Entity.h"
#include "RenderWindow.h"
#include "Ball.h"
#include "Hole.h"
#include "Tile.h"
#include"Game.h"
#include"music.h"


int main(int argc, char* args[]){
    Music mus{BG_MUSIC};
    mus.play();
    loadLevel(level);
    while(gameRunning){
      if(state==0) titleScreen();
      else {
        update();
        graphics();
     }
   }
    window.cleanUp();
    TTF_CloseFont(font32);
    TTF_CloseFont(font24);
    SDL_Quit();
    TTF_Quit();
   return 0;
}
