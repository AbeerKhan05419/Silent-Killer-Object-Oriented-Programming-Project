#include <SDL.h>
#include "enemy.hpp"
// we have inherited the wolf class which is the child class from the enemy class which is the parent class.
// As wolf is an enemy (obstracle).
// if the zombie collide with the wolf it lifeline will be decrease by 1.
// if it doesnt collide with the zombie then the health will be increase by 1.
class Wolf : public Enemy
{
    SDL_Rect srcRect, moverRect;
    SDL_Rect srcRect_0 = {162, 7, 64, 85};

public:
    // this boolean function is used to detect the collision with bottom of the screen.
    // If it is true that means it has hit the bottom of the screen which result in destroying of the sprite
    bool check = false;
    void drop(SDL_Renderer *, SDL_Texture *assets); //fall the wolf from the sky
    void draw(SDL_Renderer *, SDL_Texture *assets); // drawing and displaying wolf on screen
    SDL_Rect find_pos();                            // this will help to detect the collision of zombie and wolf
    Wolf();                                         //empty constuctor
    Wolf(int x, int y);                             // constructors with parameters
};
