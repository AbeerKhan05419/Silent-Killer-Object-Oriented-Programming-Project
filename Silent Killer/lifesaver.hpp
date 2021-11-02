#include <SDL.h>
#pragma once
// All the lifesaver obstracle (i.e brain,blood,severed hand and heart) will be inherited from the super class of lifesaver
class Lifesaver
{
protected:
    // protected attributes
    SDL_Rect srcRect, moverRect;

public:
    // public attributes
    Lifesaver();                                    //constructor without variable
    Lifesaver(SDL_Rect src, SDL_Rect mr);           //constructor with paramters
    void draw(SDL_Renderer *, SDL_Texture *assets); // draw and display the sprites on the screen
};
