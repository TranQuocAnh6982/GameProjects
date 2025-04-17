#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<vector>
#include"Hole.h"
#include"Tile.h"
#include"Entity.h"
#include"Math.h"
#include"defs.h"
using namespace std;

class Ball: public Entity{
private:
    Vector2f velocity;
    Vector2f target;
    Vector2f launchedVelocity;
    double velocity1D;
    double launchedVelocity1D;
    Vector2f initialMousePos;
    bool canMove=true;
    bool playedSwingFx=true;
    int index;
    int strokes=0;
    int dirX=1;
    int dirY=1;
    bool win=false;
    double friction=0.001;
    vector<Entity> points;
    vector<Entity>powerBar;
public:
    Ball(Vector2f p_pos, SDL_Texture* p_tex, SDL_Texture* p_pointsTex,
         SDL_Texture* p_powerMTexFG, SDL_Texture* p_powerMTexBG, int p_index):Entity(p_pos, p_tex){
        index=p_index;
        points.push_back(Entity(Vector2f(-64, -64), p_pointsTex));
        powerBar.push_back(Entity(Vector2f(-64, -64), p_powerMTexBG));
        powerBar.push_back(Entity(Vector2f(-64, -64), p_powerMTexFG));

    }
    Vector2f& getVelocity(){return velocity;}
    Vector2f& getInitialMousePos(){return initialMousePos;}
    vector<Entity> getPoints(){return points;}
    vector<Entity> getPowerBar(){return powerBar;}
    int getStrokes(){return strokes;}
    bool isWin(){return win;}
    void setWin(bool p_win){win = p_win;}
    void setInitialMousePos(double x, double y){
        initialMousePos.x=x;
        initialMousePos.y=y;
    }
    void setVelocity(double x, double y){
        velocity.x=x;
        velocity.y=y;
    }
    void setLaunchedVelocity(double x, double y){
        launchedVelocity.x=x;
        launchedVelocity.y=y;
    }
    void update(double deltatime, bool mouseDown, bool mousePressed, vector<Tile>tiles, vector<Hole>holes,
                Mix_Chunk* chargeSfx, Mix_Chunk* swingSfx, Mix_Chunk* holeSfx){
        if(win){
            if(getPos().x<target.x) setPos(getPos().x+=0.1*deltatime, getPos().y);
            else if(getPos().x>target.x ) setPos(getPos().x-=0.1*deltatime, getPos().y);
            else if(getPos().y<target.y) setPos(getPos().x, getPos().y+=0.1*deltatime);
            else if(getPos().y>target.y) {setPos(getPos().x, getPos().y-=0.1*deltatime);}
            setScale(getScale().x-0.001*deltatime, getScale().y-0.001*deltatime);
            return;
        }
        for(Hole h: holes){
            if(getPos().x+ 4 >h.getPos().x && getPos().x+16 <h.getPos().x+20&&
               getPos().y+ 4 >h.getPos().y && getPos().y+16 <h.getPos().y+20){
                Mix_PlayChannel(-1, holeSfx, 0);
                setWin(true);
                target.x=h.getPos().x;
                target.y=h.getPos().y +3;
               }
        }
        if(mousePressed && canMove){
            Mix_PlayChannel(-1, chargeSfx, 0 );
            playedSwingFx=false;
            int mouseX=0;
            int mouseY=0;
            SDL_GetMouseState(&mouseX, &mouseY);
            setInitialMousePos(mouseX, mouseY);
        }
        if(mouseDown && canMove){
            int mouseX=0;
            int mouseY=0;
            SDL_GetMouseState(&mouseX, &mouseY);
            setVelocity((mouseX-getInitialMousePos().x)/-150, (mouseY-getInitialMousePos().y)/-150);
            setLaunchedVelocity((mouseX-getInitialMousePos().x)/-150, (mouseY-getInitialMousePos().y)/-150);
            velocity1D=SDL_sqrt(SDL_pow(abs(getVelocity().x), 2)+SDL_pow(abs(getVelocity().y), 2));
            launchedVelocity1D=velocity1D;

            points.at(0).setPos(getPos().x, getPos().y+8-32);
            points.at(0).setAngle(SDL_atan2(velocity.y,velocity.x )*(180/pi)+90);

            dirX=velocity.x/abs(velocity.x);
            dirY=velocity.y/abs(velocity.y);

            powerBar.at(0).setPos(getPos().x +32+8, getPos().y-32);
            powerBar.at(1).setPos(getPos().x +32+8+4, getPos().y-32+4 + 32 - 32*powerBar.at(1).getScale().y);
            if(velocity1D>1){
                velocity1D=1;
                launchedVelocity1D=1;
            }
            powerBar.at(1).setScale(1, velocity1D/1);

        }
        else{
            if(! playedSwingFx){
                Mix_PlayChannel(-1, swingSfx, 0);
                playedSwingFx=true;
                strokes++;
            }
            points.at(0).setPos(-64, -64);
            powerBar.at(0).setPos(-64, -64);
            powerBar.at(1).setPos(-64, -64);
            canMove=false;
            setPos(getPos().x + getVelocity().x* deltatime, getPos().y + getVelocity().y*deltatime);
            if(getVelocity().x >0.001||getVelocity().x<-0.001 || getVelocity().y>0.001||getVelocity().y<-0.001){
                if(velocity1D>0) {velocity1D-=friction*deltatime;}
                else {velocity1D=0;}
                velocity.x=(velocity1D/launchedVelocity1D)*abs(launchedVelocity.x)*dirX;
                velocity.y=(velocity1D/launchedVelocity1D)*abs(launchedVelocity.y)*dirY;
            }
            else {
                setVelocity(0, 0);
                int mouseX=0;
                int mouseY=0;
                SDL_GetMouseState(&mouseX, &mouseY);
                setInitialMousePos(mouseX, mouseY);
                canMove=true;
            }
            if(getPos().x+getCurrentFrame().w > WINDOW_WIDTH/(2-index)){
                setVelocity(-abs(getVelocity().x), getVelocity().y);
                dirX=-1;
            }
            else if(getPos().x<  index*320){
                setVelocity(abs(getVelocity().x), getVelocity().y);
                dirX=1;
            }
            else if(getPos().y+getCurrentFrame().h>WINDOW_HEIGHT){
                setVelocity(getVelocity().x, -abs(getVelocity().y));
                dirY=-1;
            }
            else if(getPos().y<0){
                setVelocity(getVelocity().x, abs(getVelocity().y));
                dirY=1;
            }
        for(Tile& t: tiles){
            double newX=getPos().x+getVelocity().x*deltatime;
            double newY=getPos().y;
            if(newX+16>t.getPos().x&& newX<t.getPos().x+t.getCurrentFrame().w
               &&newY+16>t.getPos().y&& newY<t.getPos().y+t.getCurrentFrame().h-3)    {
                setVelocity(getVelocity().x*-1, getVelocity().y);
                dirX *=-1;
               }
            newX=getPos().x;
            newY=getPos().y+getVelocity().y*deltatime;
            if(newX+16>t.getPos().x&& newX<t.getPos().x+t.getCurrentFrame().w
               &&newY+16>t.getPos().y&& newY<t.getPos().y+t.getCurrentFrame().h-3){
               setVelocity(getVelocity().x, getVelocity().y *-1);
               dirY *=-1;
               }
        }

        }


    }

};

#endif // BALL_H_INCLUDED
