#include "Bat.hpp"
// this will draw the image of Bat on the screen
void Bat::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    drop(gRenderer, assets);
}
// this constructor is to recognize the sprites of the Bat
Bat::Bat()
{
    Enemy({srcRect_0, {0, 0, 50, 60}});
}
// this constructor is to recognize the sprites of the Bat with the x and y value
Bat::Bat(int x, int y)
{
    srcRect = srcRect_0;
    moverRect = {x, y, 30, 40};
}
// this function will find the position of Bat and this will help us to find the collision of Bat with zombie
SDL_Rect Bat ::find_pos()
{
    return moverRect;
}
// this function will drop the Bat from sky.
void Bat::drop(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    if (moverRect.y <= 550)
    {
        srcRect = srcRect_0;
        moverRect.y = moverRect.y + 1;
    }

    if (moverRect.y >= 550)
    {
        check = true; // this boolean function is used to detect the collision with bottom of the screen.
        // If it is true that means it has hit the bottom of the screen which result in destroying of the sprite
    }
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}
