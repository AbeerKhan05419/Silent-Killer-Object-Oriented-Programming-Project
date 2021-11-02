#include "lifesaver.hpp"
// conrtuctor with parameters
Lifesaver::Lifesaver(SDL_Rect src, SDL_Rect mr) : srcRect(src), moverRect(mr) {}
// constructor without paramaters
Lifesaver::Lifesaver() {}
// this will draw and display the sprites on the screen
void Lifesaver::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}
