#include <SDL.h>
#include "lifesaver.hpp"
// we have inherited the Blood class which is the child class from the lifesaver class which is the parent class.
// As Blood is a lifesaver.
// if the zombie collide with the Blood it health will be increase.
// if it doesnt collide with the zombie then the lifeline will be decrease by 1.
class Blood : public Lifesaver
{
    SDL_Rect srcRect, moverRect;
    SDL_Rect srcRect_0 = {211, 105, 44, 60};

public:
    // this boolean function is used to detect the collision with bottom of the screen.
    // If it is true that means it has hit the bottom of the screen which result in destroying of the sprite
    bool check = false;
    void drop(SDL_Renderer *, SDL_Texture *assets); //fall the Blood from the sky
    void draw(SDL_Renderer *, SDL_Texture *assets); // drawing and displaying Blood on screen
    SDL_Rect find_pos();                            // this will help to detect the collision of zombie and Blood
    Blood();                                        //empty constuctor
    Blood(int x, int y);                            //Constuctor with paramters
};
