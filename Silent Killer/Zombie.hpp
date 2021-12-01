#include <SDL.h>
#include <iostream>
#include <string>
using namespace std;

class Zombie
{
    SDL_Rect srcRect, moverRect;
    SDL_Rect srcRect_0 = {278, 17, 167, 307}; //right side zombie sprite

public:
    void move(string direction);                    //player movement in left right direction
    void draw(SDL_Renderer *, SDL_Texture *assets); // display player sprite on screen
    SDL_Rect find_pos();                            //help to find the collision detection
    Zombie();                                       //constructor without parameters
    Zombie(int x, int y);                           //constructor with parameters
};
