#include "Wolf.hpp"
// this will draw the image of wolf on the screen
void Wolf::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    drop(gRenderer, assets);
}
// this constructor is to recognize the sprites of the wolf
Wolf::Wolf()
{
    Enemy({srcRect_0, {0, 0, 50, 80}});
}
// this constructor is to recognize the sprites of the wolf with the x and y value
Wolf::Wolf(int x, int y)
{
    srcRect = srcRect_0;
    moverRect = {x, y, 50, 80};
}
// this function will find the position of wolf and this will help us to find the collision of wolf with zombie
SDL_Rect Wolf ::find_pos()
{
    return moverRect;
}
// this function will drop the wolf from sky.
void Wolf::drop(SDL_Renderer *gRenderer, SDL_Texture *assets)
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
