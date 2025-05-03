#ifndef MUSIC_H_INCLUDED
#define MUSIC_H_INCLUDED
#include<SDl_mixer.h>
#include<string>
class Music{
Mix_Music* gMusic;
public:
    Music():gMusic(nullptr){}
    Music(const std::string path):Music(){
        gMusic=Mix_LoadMUS(path.c_str());
        if(gMusic==nullptr){
            cout<<"SDL_mixer has fail.Error: "<<SDL_GetError()<<endl;
        }
    }
    ~Music(){
        if(gMusic!=nullptr){
            Mix_FreeMusic(gMusic);
        }
    }
    Music(const Music&)=delete;
    Music& operator=(const Music&)=delete;
    void play(){
        if(gMusic!=nullptr){
            if(Mix_PlayingMusic()==0){
                Mix_PlayMusic(gMusic, -1);
            }
            else if(Mix_PausedMusic()==1){
                Mix_ResumeMusic();
            }
        }
    }
    void pause(){
        if(Mix_PlayingMusic()==1){
            Mix_PauseMusic();
        }
    }
    void stop(){
        pause();
        Mix_RewindMusic();
    }
};

#endif // MUSIC_H_INCLUDED
