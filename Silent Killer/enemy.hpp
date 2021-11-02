#include <SDL.h>
#pragma once
// All the enemy obstracle (i.e Axe,bat,fart,spider,skull and wolf) will be inherited from the super class of enemy
class Enemy
{
protected:
    // protected attributes
    SDL_Rect srcRect, moverRect;

public:
    // public attributes
    Enemy();                                        //constructor without variable
    Enemy(SDL_Rect src, SDL_Rect mr);               //constructor with parameters
    void draw(SDL_Renderer *, SDL_Texture *assets); // draw and display the sprites on the screen
};
