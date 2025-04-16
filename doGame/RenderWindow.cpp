#include"RenderWindow.h"

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
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
  SDL_Texture* RenderWindow::loadTexture(const char* p_filePath){
        SDL_Texture* texture=NULL;
        texture=IMG_LoadTexture(renderer, p_filePath);
        if(texture==NULL){
            cout<<"Failed to load texture. Error: "<<SDL_GetError()<<endl;
        }
          return texture;
    }
void RenderWindow::cleanUp(){SDL_DestroyWindow(window);}
void RenderWindow::clear(){SDL_RenderClear();}

void RenderWindow::render(Entity& p_entity){
        SDL_Rect src;
        src.x=p_entity.getCurrentFrame().x;
        src.y=p_entity.getCurrentFrame().y;
        src.w=p_entity.getCurrentFrame().w;
        src.h=p_entity.getCurrentFrame().h;
        SDL_Rect dst;
        dst.x=p_entity.getPos().x+(p_entity.getCurrentFrame().w- p_entity.getCurrentFrame().w * p_entity.getScale().x)/2;
        dst.y=p_entity.getPos().y+(p_entity.getCurrentFrame().h- p_entity.getCurrentFrame().h * p_entity.getScale().y)/2;
        dst.w=p_entity.getCurrentFrame().w * p_entity.getScale().x;
        dst.y=p_entity.getCurrentFrame().h * p_entity.getScale().y;

        SDL_RenderCopyEx(renderer, p_entity.getTex(), &src, &dst, p_entity.getAngle(), 0, SDL_FLIP_NONE);
    }
