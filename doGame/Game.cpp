/*#include<SDL.h>
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

    SDL_Color white={255, 255, 255, 255};
    SDL_Color black={0, 0, 0, 0};

bool init(){
    if(SDL_Init(SDL_INIT_VIDEO>0)) cout<<"SDL_Init HAS FAIL. SDL_ERROR: "<<SDL_GetError()<<endl;
    if(!(IMG_Init(IMG_INIT_PNG))) cout<<"IMG_Init has fail. Error: "<<SDL_GetError()<<endl;
    if(!(TTF_Init())) cout<<"TTF_Init has fail. Error: "<<SDL_GetError()<<endl;
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    return true;
}
    RenderWindow window(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT);
     SDL_Texture*ballTexture=window.loadTexture("./assets/ball.png");
     SDL_Texture*holeTexture=window.loadTexture("./assets/hole.png");
     SDL_Texture*pointTexture=window.loadTexture("./assets/point.png");
     SDL_Texture*tiledarkTexture32=window.loadTexture("./assets/tile32_dark.png");
     SDL_Texture*tiledarkTexture64=window.loadTexture("./assets/tile64_dark.png");
     SDL_Texture*tilelightTexture32=window.loadTexture("./assets/tile32_light.png");
    SDL_Texture*tilelightTexture64=window.loadTexture("./assets/tile64_light.png");
    SDL_Texture*ballShadowTexture=window.loadTexture("./assets/ball_shadow.png");
     SDL_Texture*bgTexture=window.loadTexture("./assets/bg.png");
    SDL_Texture*uiBgTexture=window.loadTexture("./assets/UI_bg.png");
     SDL_Texture*levelTextBgTexture=window.loadTexture("./assets/levelText_bg.png");
     SDL_Texture*powerMeterTexture_FG=window.loadTexture("./assets/powermeter_fg.png");
     SDL_Texture*powerMeterTexture_BG=window.loadTexture("./assets/powermeter_bg.png");
     SDL_Texture*powerMeterTexture_overlay=window.loadTexture("./assets/powermeter_overlay.png");
     SDL_Texture*logoTexture=window.loadTexture("./assets/logo.png");
     SDL_Texture*click2start=window.loadTexture("./assets/click2start.png");
     SDL_Texture*endscreenOverlayTexture=window.loadTexture("./assets/end.png");
     SDL_Texture*splashBgTexture=window.loadTexture("./assets/splashbg.png");

     Mix_Chunk* chargeSfx=Mix_LoadWAV("./assets/charge.mp3");
     Mix_Chunk* swingSfx=Mix_LoadWAV("./assets/swing.mp3");
     Mix_Chunk* holeSfx=Mix_LoadWAV("./assets/hole.mp3");


     TTF_Font*font32=TTF_OpenFont("./assets/font.ttf", 32);
    // font48=TTF_OpenFont(" ", 48);
     TTF_Font*font24=TTF_OpenFont("./assets/font.ttf", 24);

   vector<Hole> holes={Hole(Vector2f(0, 0), holeTexture), Hole(Vector2f(0, 0), holeTexture) };
    Ball balls[2]={Ball(Vector2f(0, 0), ballTexture, pointTexture, powerMeterTexture_FG, powerMeterTexture_BG, 0),
                   Ball(Vector2f(0, 0), ballTexture, pointTexture, powerMeterTexture_FG, powerMeterTexture_BG, 1) };
 vector<Tile> loadTiles(int level){
        vector<Tile> temp={};
        switch(level){
        case 0:
            temp.push_back(Tile(Vector2f(64*3, 64*3), tiledarkTexture64));
temp.push_back(Tile(Vector2f(64*4, 64*3), tiledarkTexture64));

            temp.push_back(Tile(Vector2f(64*0, 64*3), tiledarkTexture64));
            temp.push_back(Tile(Vector2f(64*1, 64*3), tiledarkTexture64));

            temp.push_back(Tile(Vector2f(64*3+64*5, 64*3), tilelightTexture64));
            temp.push_back(Tile(Vector2f(64*4+64*5, 64*3), tilelightTexture64));

            temp.push_back(Tile(Vector2f(64*0+64*5, 64*3), tilelightTexture64));
            temp.push_back(Tile(Vector2f(64*1+64*5, 64*3), tilelightTexture64));
        break;
        case 1:
            temp.push_back(Tile(Vector2f(64*2, 64*3), tiledarkTexture64));
            temp.push_back(Tile(Vector2f(64*4+64*5, 64*3), tilelightTexture64));
        break;
        case 2:
             temp.push_back(Tile(Vector2f(32*1+32*10+16, 32*5), tilelightTexture32));
        break;
        case 3:
            temp.push_back(Tile(Vector2f(32*4, 32*7), tiledarkTexture64));
            temp.push_back(Tile(Vector2f(32*3, 32*5), tiledarkTexture32));
            temp.push_back(Tile(Vector2f(32*6, 32*3), tiledarkTexture32));

            temp.push_back(Tile(Vector2f(32*4+ 64*5, 32*2), tilelightTexture64));
            temp.push_back(Tile(Vector2f(32*3+ 32*10, 32*6), tilelightTexture32));
            temp.push_back(Tile(Vector2f(32*6+ 32*10, 32*9), tilelightTexture32));
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

            temp.push_back(Tile(Vector2f(32*2+32*10, 32*2), tilelightTexture32));
            temp.push_back(Tile(Vector2f(32*5+32*10, 32*11), tilelightTexture32));

            temp.push_back(Tile(Vector2f(32*3+32*10, 32*1), tilelightTexture64));
            temp.push_back(Tile(Vector2f(32*8+32*10, 32*6), tilelightTexture64));
            temp.push_back(Tile(Vector2f(32*3+32*10, 32*11), tilelightTexture64));
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
    bool secondSingPlayed=false;
    SDL_Event event;
    int state=0;
    Uint64 currentTick=SDL_GetPerformanceCounter();
    Uint64 lastTick=0;
    double deltatime=0;
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
                loadLevel(level);
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
    void game(){
     if(state==0) titleScreen();
     else {
        update();
        graphics();
     }
    }
