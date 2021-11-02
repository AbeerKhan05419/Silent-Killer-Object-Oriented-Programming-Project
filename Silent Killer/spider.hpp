#include <SDL.h>
#include "enemy.hpp"
// we have inherited the spider class which is the child class from the enemy class which is the parent class.
// As spider is an enemy (obstracle).
// if the zombie collide with the spider it lifeline will be decrease by 1.
// if it doesnt collide with the zombie then the health will be increase by 1.
class Spider : public Enemy
{
    SDL_Rect srcRect, moverRect;
    SDL_Rect srcRect_0 = {9, 7, 62, 71};

public:
    // this boolean function is used to detect the collision with bottom of the screen.
    // If it is true that means it has hit the bottom of the screen which result in destroying of the sprite
    bool check = false;
    void drop(SDL_Renderer *, SDL_Texture *assets); //fall the spider from the sky
    void draw(SDL_Renderer *, SDL_Texture *assets); // drawing and displaying spider on screen
    SDL_Rect find_pos();                            // this will help to detect the collision of zombie and spider
    Spider();                                       //empty constuctor
    Spider(int x, int y);                           // constructors with parameters
};
