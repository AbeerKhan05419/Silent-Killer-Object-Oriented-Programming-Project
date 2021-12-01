#include <SDL.h>
#include "lifesaver.hpp"
// we have inherited the severed hand class which is the child class from the lifesaver class which is the parent class.
// As severed hand is a lifesaver.
// if the zombie collide with the severed hand it health will be increase.
// if it doesnt collide with the zombie then the lifeline will be decrease by 1.
class Severed_hand : public Lifesaver
{
    SDL_Rect srcRect, moverRect;
    SDL_Rect srcRect_0 = {8, 120, 32, 37};

public:
    // this boolean function is used to detect the collision with bottom of the screen.
    // If it is true that means it has hit the bottom of the screen which result in destroying of the sprite
    bool check = false;
    void drop(SDL_Renderer *, SDL_Texture *assets); //fall the severed hand from the sky
    void draw(SDL_Renderer *, SDL_Texture *assets); // drawing and displaying severed hand on screen
    SDL_Rect find_pos();                            // this will help to detect the collision of zombie and severed hand
    Severed_hand();                                 //empty constuctor
    Severed_hand(int x, int y);                     // constructors with parameters
};