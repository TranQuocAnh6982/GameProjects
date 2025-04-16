/*#ifndef INIT_H_INCLUDED
#define INIT_H_INCLUDED

#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<SDL_mixer.h>
#include"RenderWindow.h"
#include"defs.h"
#include"Ball.h"
#include"Entity.h"
#include"Tile.h"
#include"Hole.h"
#include"Math.h"
#include<vector>
#include<string>
using namespace std;
class Game{
    Tile tile;
    RenderWindow window;
    SDL_Texture* ballTexture, *holeTexture, *pointTexture, *tiledarkTexture32, *tiledarkTexture64, *tilelightTexture32,
                *tilelightTexture64, *ballShadowTexture,  *bgTexture, *uiBgTexture, *levelTextBgTexture, *powerMeterTexture_FG,
                *powerMeterTexture_BG, *powerMeterTexture_overlay, *logoTexture, *click2start, *endscreenOverlayTexture, *splashBgTexture;
    Mix_Chunk* chargeSfx, *swingSfx, *holeSfx;
    TTF_Font* font32, *font48, *font24;
    SDL_Color white={255, 255, 255, 255};
    SDL_Color black={0, 0, 0, 0};

    int level=0;
    vector<Tile> tiles = tile.loadTiles();
    bool gameRunning=true;
    bool mouseDown=false;
    bool mousePressed=false;
    bool swingPlayed=false;
    bool secondSingPlayed=false;
    SDL_Event event;
    int state=0;
    Uint64 currentTick=SDL_GetPerformanceCounter();
    Uint64 lastTick=0;
    double deltatime=0;
    vector<Hole> holes={Hole(Vector2f(0, 0), holeTexture), Hole(Vector2f(0, 0), holeTexture) };
    Ball balls[2]={Ball(Vector2f(0, 0), ballTexture, pointTexture, powerMeterTexture_FG, powerMeterTexture_BG, 0),
                   Ball(Vector2f(0, 0), ballTexture, pointTexture, powerMeterTexture_FG, powerMeterTexture_BG, 1) };
//public:
bool init(){
    if(SDL_Init(SDL_INIT_VIDEO>0)) cout<<"SDL_Init HAS FAIL. SDL_ERROR: "<<SDL_GetError()<<endl;
    if(!(IMG_Init(IMG_INIT_PNG))) cout<<"IMG_Init has fail. Error: "<<SDL_GetError()<<endl;
    if(!(TTF_Init())) cout<<"TTF_Init has fail. Error: "<<SDL_GetError()<<endl;
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    return true;
}
void initGame(){
     ballTexture=window.loadTexture("assets/ball.png");
     holeTexture=window.loadTexture("assets/hole.png");
     pointTexture=window.loadTexture("assets/point.png");
     tiledarkTexture32=window.loadTexture("assets/tile32_dark.png");
     tiledarkTexture64=window.loadTexture("assets/tile64_dark.png");
     tilelightTexture32=window.loadTexture("assets/tile32_light.png");
    tilelightTexture64=window.loadTexture("assets/tile64_light.png");
    ballShadowTexture=window.loadTexture("assets/ball_shadow.png");
     bgTexture=window.loadTexture("assets/bg.png");
    uiBgTexture=window.loadTexture("assets/UI_bg.png");
     levelTextBgTexture=window.loadTexture("assets/levelText_bg.png");
     powerMeterTexture_FG=window.loadTexture("asset/powermeter_fg.png");
     powerMeterTexture_BG=window.loadTexture("asset/powermeter_bg.png");
     powerMeterTexture_overlay=window.loadTexture("assets?powermeter_overlay.png");
     logoTexture=window.loadTexture("assets/logo.png");
     click2start=window.loadTexture("assets/click2start.png");
     endscreenOverlayTexture=window.loadTexture("assets/end.png");
     splashBgTexture=window.loadTexture("assets/splashbg.png");

     chargeSfx=Mix_LoadWAV("assets/charge.mp3");
     swingSfx=Mix_LoadWAV("assets/swing.mp3");
     holeSfx=Mix_LoadWAV("asset/hole.mp3");


     font32=TTF_OpenFont("assets/font.ttf", 32);
    // font48=TTF_OpenFont(" ", 48);
     font24=TTF_OpenFont("asset/font.ttf", 24);

  }

  void loadLevel(){
    if(level>4){
        state=2;
        return;
    }
    balls[0].setVelocity(0, 0);
    balls[1].setVelocity(0, 0);
    balls[0].setScale(1, 1);
    balls[1].setScale(1, 1);
    balls[0].setWin(false);
    balls[1].setWin(false);
    tiles=tile.loadTiles();
    switch(level){
    case 0:
        balls[0].setPos(24+32*4, 24+32*11);
        balls[1].setPos(24+32*4+32*10, 24+32*11);
        holes.at(0).setPos(24+32*4, 22+32*2);
        holes.at(1).setPos(24+32*4+32*10, 22+32*2);
    break;
    case 1:
        balls[0].setPos(24+32*4, 24+32*11);
        balls[1].setPos(24+32*4+32*10, 24+32*11);
        holes.at(0).setPos(24+32*4, 22+32*2);
        holes.at(1).setPos(24+32*4+32*10, 22+32*2);
    break;
    case 2:
        balls[0].setPos(8+32*7, 8+32*10);
        balls[0].setPos(8+32*7+32*10, 24+32*11);
        holes.at(0).setPos(8+32*2, 6+32*5);
        holes.at(1).setPos(8+32*4+32*10, 6+32*3);
    break;
    case 3:
        balls[0].setPos(24+32*4, 24+32*5);
        balls[0].setPos(24+32*4+32*10, 24+32*4);
        holes.at(0).setPos(24+32*4, 22+32*1);
        holes.at(1).setPos(24+32*4+32*10, 22+32*11);
    break;
    case 4:
        balls[0].setPos(24+32*2, 24+32*12);
        balls[0].setPos(24+32*0+32*10, 24+32*5);
        holes.at(0).setPos(24+32*1, 22+32*1);
        holes.at(1).setPos(24+32*0+32*10, 22+32*7);
    break;
    }
  }
  const char* getStrokeText(){
    int biggestStroke=0;
    if(balls[1].getStrokes()>balls[0].getStrokes()) biggestStroke=balls[1].getStrokes();
    else biggestStroke=balls[0].getStrokes();
    string s= to_string(biggestStroke);
    s="STROKES: "+s;
    return s.c_str();
  }
  const char* getLevelText(int side){
    int tempLevel=(level+1)*2-1;
    if(side==1) tempLevel++;
    string s=to_string(tempLevel);
    s="HOLE:"+s;
    return s.c_str();
  }
  void update(){
    lastTick=currentTick;
    currentTick=SDL_GetPerformanceCounter();
    deltatime=(double)((currentTick-lastTick)*1000/(double)SDL_GetPerformanceCounter());
    mousePressed=false;
    while(SDL_PollEvent(&event)){
        switch(event.type){
        case SDL_QUIT:
            gameRunning=false;
            break;
        case SDL_MOUSEBUTTONDOWN:
            if(event.button.button==SDL_BUTTON_LEFT){
                mouseDown=true;
                mousePressed=true;
            }
            break;
        case SDL_MOUSEBUTTONUP:
            if(event.button.button==SDL_BUTTON_LEFT) {
                    mouseDown=false;
            }
            break;
        }
        if(state==1){
            for(Ball& b:balls){
                b.update(deltatime, mouseDown, mousePressed, tiles, holes, chargeSfx, swingSfx, holeSfx);
            }
            if(balls[0].getScale().x<-1&& balls[1].getScale().x<-1){
                level++;
                loadLevel();
            }
        }
  }
  }
    void graphics(){
        window.clear();
        window.render(0, 0, bgTexture);
        for(Hole& h:holes) window.render(h);
        for(Ball& b:balls){
            if(!b.isWin()) window.render(b.getPos().x, b.getPos().y+4, ballShadowTexture);
            for(Entity& e:b.getPoints()) {
                    window.render(e);
            }
            window.render(b);
        }
        for(Tile& t:tiles) window.render(t);
        for(Ball& b:balls){
            for(Entity& e:b.getPowerBar()) {
                    window.render(e);
            }
        window.render(b.getPowerBar().at(0).getPos().x, b.getPowerBar().at(0).getPos().y, powerMeterTexture_overlay);
        }
        if(state!=2){
            window.render(WINDOW_WIDTH/4-132/2, WINDOW_HEIGHT-32, levelTextBgTexture);
            window.renderCenter(-160, 240-16+3, getLevelText(0), font24, black);
            window.renderCenter(-160, 240-16, getLevelText(0), font24, white);

            window.render(WINDOW_WIDTH/2+640/4, WINDOW_HEIGHT-32, levelTextBgTexture);
            window.renderCenter(-160, 240-16+3, getLevelText(1), font24, black);
            window.renderCenter(-160, 240-16, getLevelText(1), font24, white);

            window.render(WINDOW_WIDTH/2-196/2, 0, uiBgTexture);
            window.renderCenter(0, -240+16+3, getStrokeText(), font24, black);
            window.renderCenter(0, -240+16, getStrokeText(), font24, white);
        }
        else {
            window.render(0, 0, endscreenOverlayTexture);
            window.renderCenter(0, 3+32, getStrokeText(), font32, black );
            window.renderCenter(0, 32, getStrokeText(), font32, white );
        }
      window.display();
    }
    void titleScreen(){
        if(SDL_GetTicks()<2000){
            Mix_PlayChannel(-1, swingSfx, 0);
            swingPlayed=true;
        }
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    gameRunning=false;
                    break;
            }
        }
        window.clear();
        window.render(0, 0, bgTexture);
        window.render(0, 0, splashBgTexture);
        window.renderCenter(0, 0+3, "POLYMAS", font32, black);
        window.renderCenter(0, 0+3, "POLYMAS", font32, white);
        window.display();
    }
    void games(){
     if(state==0) titleScreen();
     else {
        update();
        graphics();
     }
    }

};
#endif // INIT_H_INCLUDED
