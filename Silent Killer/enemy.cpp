#include "enemy.hpp"
// conrtuctor with parameters
Enemy::Enemy(SDL_Rect src, SDL_Rect mr) : srcRect(src), moverRect(mr) {}
// conrtuctor without parameters
Enemy::Enemy() {}
// this will draw and display the sprites on the screen
void Enemy::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}
