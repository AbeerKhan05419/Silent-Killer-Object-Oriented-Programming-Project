#include "SeveredHand.hpp"
// this will draw the image of severed hand on the screen
void Severed_hand::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    drop(gRenderer, assets);
}
// this constructor is to recognize the sprites of the severed hand
Severed_hand::Severed_hand()
{
    Lifesaver({srcRect_0, {0, 0, 50, 60}});
}
// this constructor is to recognize the sprites of the severed hand with the x and y value
Severed_hand::Severed_hand(int x, int y)
{
    srcRect = srcRect_0;
    moverRect = {x, y, 30, 40};
}
// this function will find the position of severed hand and this will help us to find the collision of severed hand with zombie
SDL_Rect Severed_hand ::find_pos()
{
    return moverRect;
}
// this function will drop the severed hand from sky.
void Severed_hand::drop(SDL_Renderer *gRenderer, SDL_Texture *assets)
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
