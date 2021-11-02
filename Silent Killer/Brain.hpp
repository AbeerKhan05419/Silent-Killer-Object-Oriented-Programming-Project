#include <SDL.h>
#include "lifesaver.hpp"
// we have inherited the Brain class which is the child class from the lifesaver class which is the parent class.
// As Brain is a lifesaver.
// if the zombie collide with the Brain it health will be increase.
// if it doesnt collide with the zombie then the lifeline will be decrease by 1.
class Brain : public Lifesaver
{
    SDL_Rect srcRect, moverRect;
    SDL_Rect srcRect_0 = {11, 94, 69, 66};

public:
    // this boolean function is used to detect the collision with bottom of the screen.
    // If it is true that means it has hit the bottom of the screen which result in destroying of the sprite
    bool check = false;
    void drop(SDL_Renderer *, SDL_Texture *assets); //fall the Brain from the sky
    void draw(SDL_Renderer *, SDL_Texture *assets); // drawing and displaying Brain on screen
    SDL_Rect find_pos();                            // this will help to detect the collision of zombie and Brain
    Brain();                                        //empty constuctor
    Brain(int x, int y);                            //Constuctor with paramters
};
