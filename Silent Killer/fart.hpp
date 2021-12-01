#include <SDL.h>
#include "enemy.hpp"
//                                  Fart is the silent killer of our game
// -------------------------------------------------------------------------------------------------------
// we have inherited the fart class which is the child class from the enemy class which is the parent class.
// As fart is an enemy (obstracle).
// if the zombie collide with the fart it lifeline will be become zero.
// if it doesnt collide with the zombie then the health will be increase by 1.

class Fart : public Enemy
{
    SDL_Rect srcRect, moverRect;
    SDL_Rect srcRect_0 = {92, 5, 53, 35};

public:
    // this boolean function is used to detect the collision with bottom of the screen.
    // If it is true that means it has hit the bottom of the screen which result in destroying of the sprite
    bool check = false;
    void drop(SDL_Renderer *, SDL_Texture *assets); //fall the fart from the sky
    void draw(SDL_Renderer *, SDL_Texture *assets); // drawing and displaying fart on screen
    SDL_Rect find_pos();                            // this will help to detect the collision of zombie and fart
    Fart();                                         //empty constuctor
    Fart(int x, int y);                             // constructors with parameters
};
