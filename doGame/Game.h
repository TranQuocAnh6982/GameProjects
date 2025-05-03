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
#include<vector>
#include<string>
#include"music.h"
using namespace std;


bool init(){
    if(SDL_Init(SDL_INIT_VIDEO>0)) cout<<"SDL_Init HAS FAIL. SDL_ERROR: "<<SDL_GetError()<<endl;
    if(!(IMG_Init(IMG_INIT_PNG))) cout<<"IMG_Init has fail. Error: "<<SDL_GetError()<<endl;
    if(TTF_Init()!=0) cout<<"TTF_Init has fail. Error: "<<TTF_GetError()<<endl;
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    return true;
}
    bool SDLinit=init();
     RenderWindow window(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT);
     SDL_Texture*ballTexture=window.loadTexture(BALL);
     SDL_Texture*holeTexture=window.loadTexture(HOLE);
     SDL_Texture*pointTexture=window.loadTexture(POINT);
     SDL_Texture*tiledarkTexture32=window.loadTexture(TILE32_DARK);
     SDL_Texture*tiledarkTexture64=window.loadTexture(TILE64_DARK);
     SDL_Texture*tilelightTexture32=window.loadTexture(TILE32_LIGHT);
     SDL_Texture*tilelightTexture64=window.loadTexture(TILE64_LIGHT);
     SDL_Texture*ballShadowTexture=window.loadTexture(BALL_SHADOW);
     SDL_Texture*bgTexture=window.loadTexture(BACKGROUNG);
     SDL_Texture*uiBgTexture=window.loadTexture(UI_BACKGROUND);
     SDL_Texture*levelTextBgTexture=window.loadTexture(LEVEL_BACKGROUND);
     SDL_Texture*powerMeterTexture_FG=window.loadTexture(POWERMETER_FG);
     SDL_Texture*powerMeterTexture_BG=window.loadTexture(POWERMETER_BG);
     SDL_Texture*powerMeterTexture_overlay=window.loadTexture(POWERMETER_OVERLAY);
     SDL_Texture*logoTexture=window.loadTexture(LOGO);
     SDL_Texture*click2start=window.loadTexture(CLICK2START);
     SDL_Texture*endscreenOverlayTexture=window.loadTexture(ENDSCREEN);
     SDL_Texture*splashBgTexture=window.loadTexture(SPLASH_BACKGROUND);

     Mix_Chunk* chargeSfx=Mix_LoadWAV(CHARGE_WAV);
     Mix_Chunk* swingSfx=Mix_LoadWAV(SWING_WAV);
     Mix_Chunk* holeSfx=Mix_LoadWAV(HOLE_WAV);
     SDL_Color white={255, 255, 255, 255};
     SDL_Color black={0, 0, 0, 0};

     TTF_Font* font32= TTF_OpenFont(FONT, 32);
     TTF_Font* font24= TTF_OpenFont(FONT, 24);
     vector<Hole> holes={Hole(Vector2f(0, 0), holeTexture), Hole(Vector2f(0, 0), holeTexture) };
     Ball balls[2]={Ball(Vector2f(0, 0), ballTexture, pointTexture, powerMeterTexture_FG, powerMeterTexture_BG, 0),
                   Ball(Vector2f(0, 0), ballTexture, pointTexture, powerMeterTexture_FG, powerMeterTexture_BG, 1) };
    vector<Tile> loadTiles(int level){
        vector<Tile> temp={};
        switch(level){
        case 0:
            temp.push_back(Tile(Vector2f(64*3, 64*3), tiledarkTexture64));
            temp.push_back(Tile(Vector2f(64*2, 64*5), tiledarkTexture32));

            temp.push_back(Tile(Vector2f(64*0, 64*3), tiledarkTexture64));
            temp.push_back(Tile(Vector2f(64*1, 64*3), tiledarkTexture64));

            temp.push_back(Tile(Vector2f(64*3+320, 64*3), tilelightTexture64));
            temp.push_back(Tile(Vector2f(64*1+320, 64*1), tilelightTexture32));

            temp.push_back(Tile(Vector2f(64*0+320, 64*3), tilelightTexture64));
            temp.push_back(Tile(Vector2f(64*1+320, 64*3), tilelightTexture64));
        break;
        case 1:
            temp.push_back(Tile(Vector2f(64*2, 64*3), tiledarkTexture64));
            temp.push_back(Tile(Vector2f(64*4+320, 64*3), tilelightTexture64));
            temp.push_back(Tile(Vector2f(64*3, 64*2), tiledarkTexture32));
            temp.push_back(Tile(Vector2f(64*2+320, 64*5), tilelightTexture32));
        break;
        case 2:
             temp.push_back(Tile(Vector2f(32*2+320, 32*5), tilelightTexture32));
             temp.push_back(Tile(Vector2f(32*5, 64*3), tiledarkTexture32));
             temp.push_back(Tile(Vector2f(32*7, 64*2), tiledarkTexture64));
             temp.push_back(Tile(Vector2f(32*4+320, 32*7), tilelightTexture64));
        break;
        case 3:
            temp.push_back(Tile(Vector2f(32*4, 32*7), tiledarkTexture64));
            temp.push_back(Tile(Vector2f(32*3, 32*5), tiledarkTexture32));
            temp.push_back(Tile(Vector2f(32*6, 32*3), tiledarkTexture32));

            temp.push_back(Tile(Vector2f(32*4+ 320, 32*2), tilelightTexture64));
            temp.push_back(Tile(Vector2f(32*3+ 320, 32*6), tilelightTexture32));
            temp.push_back(Tile(Vector2f(32*6+ 320, 32*9), tilelightTexture32));
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

            temp.push_back(Tile(Vector2f(32*2+320, 32*2), tilelightTexture32));
            temp.push_back(Tile(Vector2f(32*5+320, 32*11), tilelightTexture32));

            temp.push_back(Tile(Vector2f(32*3+320, 32*1), tilelightTexture64));
            temp.push_back(Tile(Vector2f(32*8+320, 32*6), tilelightTexture64));
            temp.push_back(Tile(Vector2f(32*3+320, 32*11), tilelightTexture64));
        break;
        }
    return temp;
  }
    int level=0;
    vector<Tile> tiles =loadTiles(level);
    bool gameRunning=true;
    bool mouseDown=false;
    bool mousePressed=false;
    bool swingPlayed=false;
    bool secondSwingPlayed=false;
    SDL_Event event;
    int state=0;
    Uint64 currentTick=SDL_GetPerformanceCounter();
    Uint64 lastTick=0;
    double deltaTime=0;
  void loadLevel(int level){
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
    tiles=loadTiles(level);
    switch(level){
    case 0:
        balls[0].setPos(24+32*4, 24+32*11);
        balls[1].setPos(24+32*4+320, 24+32*11);

        holes.at(0).setPos(24+32*4, 22+32*2);
        holes.at(1).setPos(24+32*4+320, 22+32*2);
        break;
    case 1:
        balls[0].setPos(24+32*4, 24+32*11);
        balls[1].setPos(24+32*4+320, 24+32*11);

        holes.at(0).setPos(24+32*4, 22+32*2);
        holes.at(1).setPos(24+32*4+320, 22+32*2);
        break;
    case 2:
        balls[0].setPos(8+32*7, 8+32*10);
        balls[1].setPos(8+32*7+320, 24+32*11);

        holes.at(0).setPos(8+32*2, 6+32*5);
        holes.at(1).setPos(8+32*4+320, 6+32*3);
        break;
    case 3:
        balls[0].setPos(24+32*4, 24+32*5);
        balls[1].setPos(24+32*4+320, 24+32*4);

        holes.at(0).setPos(24+32*4, 22+32*1);
        holes.at(1).setPos(24+32*4+320, 22+32*11);
        break;
    case 4:
        balls[0].setPos(24+32*2, 24+32*12);
        balls[1].setPos(24+32*0+320, 24+32*5);

        holes.at(0).setPos(24+32*1, 22+32*1);
        holes.at(1).setPos(24+32*0+320, 22+32*7);
        break;
    }
  }

  int biggestStroke=0;
  const char* getStrokeText(){
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
    deltaTime=(double)((currentTick-lastTick)*1000/(double)SDL_GetPerformanceFrequency());
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
        case SDL_KEYDOWN:
            if(event.key.keysym.scancode==SDL_SCANCODE_F5) {
                    state=1;
                    level=0;
                    loadLevel(0);
                    balls[1].setStrokes(0);
                    balls[0].setStrokes(0);

            }
            if(event.key.keysym.scancode==SDL_SCANCODE_ESCAPE) {
                    exit(0);
            }
            break;
        }
  }
        if(state==1){
            for(Ball& b:balls){
                b.update(deltaTime, mouseDown, mousePressed, tiles, holes, chargeSfx, swingSfx, holeSfx);
            }
            if(balls[0].getScale().x<-1&& balls[1].getScale().x<-1){
                level++;
                loadLevel(level);
            }
        }
  }
  void graphics(){
        window.clear();
        window.render(0, 0, bgTexture);
        for(Hole& h:holes) window.render(h);
        for(Ball& b:balls){
            if(!b.isWin()) window.render(b.getPos().x, b.getPos().y + 4, ballShadowTexture);
            for(Entity& e: b.getPoints()) {
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
            window.render(640/4-132/2, 480-32, levelTextBgTexture);
            window.renderCenter(-160, 240-16+3, getLevelText(0), font24, black);
            window.renderCenter(-160, 240-16, getLevelText(0), font24, white);

            window.render(640/2+640/4-132/2, 480-32, levelTextBgTexture);
            window.renderCenter(160, 240-16+3, getLevelText(1), font24, black);
            window.renderCenter(160, 240-16, getLevelText(1), font24, white);

            window.render(640/2-196/2, 0, uiBgTexture);
            window.renderCenter(0, -240+16+3, getStrokeText(), font24, black);
            window.renderCenter(0, -240+16, getStrokeText(), font24, white);
        }
        else {
            window.render(0, 0, endscreenOverlayTexture);
            window.renderCenter(0, 3+20, getStrokeText(), font32, black );
            window.renderCenter(0, 20, getStrokeText(), font32, white );
            window.renderCenter(0, 64, "F5 to Restart", font24, white);
            window.renderCenter(0, 88, "ESC to Exit", font24, white);
        }
      window.display();
    }
  void titleScreen(){
        if(SDL_GetTicks()<2000){
            if(!swingPlayed){
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
        else {
            if(!secondSwingPlayed){
                Mix_PlayChannel(-1, swingSfx, 0);
                secondSwingPlayed=true;
            }
            lastTick=currentTick;
            currentTick=SDL_GetPerformanceCounter();
            deltaTime=(double)((currentTick-lastTick)*1000/(double)SDL_GetPerformanceFrequency());
            while(SDL_PollEvent(&event)){
                switch(event.type){
                    case SDL_QUIT:
                        gameRunning=false;
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        if(event.button.button==SDL_BUTTON_LEFT){
                           Mix_PlayChannel(-1, holeSfx, 0);
                           state=1;
                        }
                        break;
                }
        window.clear();
        window.render(0, 0, bgTexture);
        window.render(320-160, 240-100-50 +4*SDL_sin(SDL_GetTicks()*(pi/1500)),  logoTexture);
        window.render(0, 0, click2start);
        window.renderCenter(0, 240-48+3-16*5,"LEFT CLICK TO START", font32, black);
        window.renderCenter(0, 240-48-16*5, "LEFT CLICK TO START", font32, white);
        window.display();
        }
    }
}


