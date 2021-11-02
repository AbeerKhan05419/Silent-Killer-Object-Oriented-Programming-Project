#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "music.hpp"
// we took this file from hw3 and lazyfoo
// added few things like home,instruction,highscore,quit screen and play screem
class Game
{
    Music bgSound;
    Music mouseclick;
    Music scoreup;
    const int SCREEN_WIDTH = 1000; //width of sdl screen
    const int SCREEN_HEIGHT = 600; //height of sdl screen
    SDL_Window *gWindow = NULL;
    SDL_Renderer *gRenderer = NULL;
    SDL_Texture *gTexture = NULL;
    SDL_Texture *assets = NULL;

public:
    bool init();
    bool loadMedia();
    void close();
    SDL_Texture *loadTexture(std::string path);
    void run();
};