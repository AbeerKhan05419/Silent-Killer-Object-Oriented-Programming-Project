#include "Zombie.hpp"
// this will draw the image of zombie on the screen
void Zombie::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}
// this constructor is to recognize the sprites of the zombie (its left and right side)
Zombie::Zombie()
{
    srcRect = srcRect_0;

    moverRect = {0, 450, 100, 150};
}
// this constructor is to recognize the sprites of the zombie (its left and right side) with the x and y value
Zombie::Zombie(int x, int y)
{
    srcRect = srcRect_0;

    moverRect = {x, y, 100, 150};
}
// this function will find the position of zombie and this will help us to find the collision of zombie with enemies
SDL_Rect Zombie ::find_pos()
{
    return moverRect;
}
// this function will move the player in tight and left direction
void Zombie::move(string direction)
{
    if (direction == "right" && moverRect.x < 900)
    {
        srcRect = srcRect_0; //this is the right side zombie sprite
        moverRect.x += 50;
    }
    if (direction == "left" && moverRect.x > 0)
    {
        srcRect = {483, 22, 168, 307}; //this is the left side zombie sprite
        moverRect.x -= 50;
    }
}
