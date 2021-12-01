#include <iostream>
#include "silentkiller.hpp"
#include <stdlib.h>
#include <SDL.h>
#include "music.hpp"
using namespace std;
// this function will display the objects on screen and it will also check if the object has hit the bottom of the screen or it has collided with the zombie
void Silentkiller::drawObjects()
{
    zombie.draw(gRenderer, assets);
    for (list<Spider *>::iterator it = Slist.begin(); it != Slist.end(); it++)
    {
        SDL_Rect SkPos = (*it)->find_pos();     //find the current position of the spider
        SDL_Rect ZombiePos = zombie.find_pos(); // find the current position of the zombie
        ZombiePos.y += 30;
        if ((*it)->check == true) //if the spider has collide the bottom of the screen then delete the sprite and also increase the health
        {
            delete (*it);
            Slist.remove(*it);
            Health += 1;
        }
        else if (SDL_HasIntersection(&SkPos, &ZombiePos) == true) //if it has collided with zombie then decrease the lifeline and then delete the sprite after colliding
        {
            delete (*it);
            Slist.remove(*it);
            Lifeline -= 1;
        }
        else //else just draw the sprite on the screen
            (*it)->draw(gRenderer, assets);
    }
    for (list<Skull *>::iterator it = skulllist.begin(); it != skulllist.end(); it++)
    {
        SDL_Rect skullPos = (*it)->find_pos();  //find the current position of the skull
        SDL_Rect ZombiePos = zombie.find_pos(); // find the current position of the zombie
        ZombiePos.y += 30;
        if ((*it)->check == true) //if the skull has collide the bottom of the screen then delete the sprite and also increase the health
        {
            delete (*it);
            skulllist.remove(*it);
            Health += 1;
        }
        else if (SDL_HasIntersection(&skullPos, &ZombiePos) == true) //if it has collided with zombie then decrease the lifeline and then delete the sprite after colliding
        {
            delete (*it);
            skulllist.remove(*it);
            Lifeline -= 1;
        }
        else //else just draw the sprite on the screen
            (*it)->draw(gRenderer, assets);
    }
    for (list<Fart *>::iterator it = fartlist.begin(); it != fartlist.end(); it++)
    {
        SDL_Rect fartPos = (*it)->find_pos();   //find the current position of the fart
        SDL_Rect ZombiePos = zombie.find_pos(); // find the current position of the zombie
        ZombiePos.y += 30;
        if ((*it)->check == true) //if the fart has collide the bottom of the screen then delete the sprite and also increase the health
        {
            delete (*it);
            fartlist.remove(*it);
            Health += 1;
        }
        else if (SDL_HasIntersection(&fartPos, &ZombiePos) == true) //if it has collided with zombie then set the lifeline equal to zero and then delete the sprite after colliding and display the gameover screen
        {
            delete (*it);
            fartlist.remove(*it);
            Lifeline = 0;
        }
        else //else just draw the sprite on the screen
            (*it)->draw(gRenderer, assets);
    }
    for (list<Bat *>::iterator it = batlist.begin(); it != batlist.end(); it++)
    {
        SDL_Rect BatPos = (*it)->find_pos();    //find the current position of the bat
        SDL_Rect ZombiePos = zombie.find_pos(); // find the current position of the zombie
        ZombiePos.y += 30;
        if ((*it)->check == true) //if the bat has collide the bottom of the screen then delete the sprite and also increase the health
        {
            delete (*it);
            batlist.remove(*it);
            Health += 1;
        }
        else if (SDL_HasIntersection(&BatPos, &ZombiePos) == true) //if it has collided with zombie then decrease the lifeline and then delete the sprite after colliding
        {
            delete (*it);
            batlist.remove(*it);
            Lifeline -= 1;
        }
        else //else just draw the sprite on the screen
            (*it)->draw(gRenderer, assets);
    }
    for (list<Wolf *>::iterator it = wolflist.begin(); it != wolflist.end(); it++)
    {
        SDL_Rect WolfPos = (*it)->find_pos();   //find the current position of the wolf
        SDL_Rect ZombiePos = zombie.find_pos(); // find the current position of the zombie
        ZombiePos.y += 30;
        if ((*it)->check == true) //if the wolf has collide the bottom of the screen then delete the sprite and also increase the health
        {
            delete (*it);
            wolflist.remove(*it);
            Health += 1;
        }
        else if (SDL_HasIntersection(&WolfPos, &ZombiePos) == true) //if it has collided with zombie then decrease the lifeline and then delete the sprite after colliding
        {
            delete (*it);
            wolflist.remove(*it);
            Lifeline -= 1;
        }
        else //else just draw the sprite on the screen
            (*it)->draw(gRenderer, assets);
    }
    for (list<Brain *>::iterator it = brainlist.begin(); it != brainlist.end(); it++)
    {
        SDL_Rect BrainPos = (*it)->find_pos();  //find the current position of the brain
        SDL_Rect ZombiePos = zombie.find_pos(); // find the current position of the zombie
        ZombiePos.y += 30;
        if ((*it)->check == true) //if the brain has collide the bottom of the screen then delete the sprite and also decrease the lifeline
        {
            delete (*it);
            brainlist.remove(*it);
            Lifeline -= 1;
        }
        else if (SDL_HasIntersection(&BrainPos, &ZombiePos) == true) //if it has collided with zombie then increase the health and then delete the sprite after colliding
        {
            delete (*it);
            brainlist.remove(*it);
            Health += 12;
        }
        else //else just draw the sprite on the screen
            (*it)->draw(gRenderer, assets);
    }
    for (list<Severed_hand *>::iterator it = Severedhandlist.begin(); it != Severedhandlist.end(); it++)
    {
        SDL_Rect SeveredhandPos = (*it)->find_pos(); //find the current position of the severed hand
        SDL_Rect ZombiePos = zombie.find_pos();      // find the current position of the zombie
        ZombiePos.y += 30;
        if ((*it)->check == true) //if the severed hand has collide the bottom of the screen then delete the sprite and also decrease the lifeline
        {
            delete (*it);
            Severedhandlist.remove(*it);
            Lifeline -= 1;
        }
        else if (SDL_HasIntersection(&SeveredhandPos, &ZombiePos) == true) //if it has collided with zombie then increase the health and then delete the sprite after colliding
        {
            delete (*it);
            Severedhandlist.remove(*it);
            Health += 15;
        }
        else //else just draw the sprite on the screen
            (*it)->draw(gRenderer, assets);
    }
    for (list<Axe *>::iterator it = axelist.begin(); it != axelist.end(); it++)
    {
        SDL_Rect AxePos = (*it)->find_pos();    //find the current position of the axe
        SDL_Rect ZombiePos = zombie.find_pos(); // find the current position of the zombie
        ZombiePos.y += 30;
        if ((*it)->check == true) //if the axe has collide the bottom of the screen then delete the sprite and also increase the health
        {
            delete (*it);
            axelist.remove(*it);
            Health += 1;
        }
        else if (SDL_HasIntersection(&AxePos, &ZombiePos) == true) //if it has collided with zombie then decrease the lifeline and then delete the sprite after colliding
        {
            delete (*it);
            axelist.remove(*it);
            Lifeline -= 1;
        }
        else //else just draw the sprite on the screen
            (*it)->draw(gRenderer, assets);
    }
    for (list<Heart *>::iterator it = heartlist.begin(); it != heartlist.end(); it++)
    {
        SDL_Rect HeartPos = (*it)->find_pos();  //find the current position of the heart
        SDL_Rect ZombiePos = zombie.find_pos(); // find the current position of the zombie
        ZombiePos.y += 30;
        if ((*it)->check == true) //if the heart has collide the bottom of the screen then delete the sprite and also decrease the lifeline
        {
            delete (*it);
            heartlist.remove(*it);
            Lifeline -= 1;
        }
        else if (SDL_HasIntersection(&HeartPos, &ZombiePos) == true) //if it has collided with zombie then increase the health and then delete the sprite after colliding
        {
            delete (*it);
            heartlist.remove(*it);
            Health += 10;
        }
        else //else just draw the sprite on the screen
            (*it)->draw(gRenderer, assets);
    }
    for (list<Blood *>::iterator it = bloodlist.begin(); it != bloodlist.end(); it++)
    {
        SDL_Rect BloodPos = (*it)->find_pos();  //find the current position of the blood
        SDL_Rect ZombiePos = zombie.find_pos(); // find the current position of the zombie
        ZombiePos.y += 30;
        if ((*it)->check == true) //if the blood has collide the bottom of the screen then delete the sprite and also decrease the lifeline
        {
            delete (*it);
            bloodlist.remove(*it);
            Lifeline -= 1;
        }
        else if (SDL_HasIntersection(&BloodPos, &ZombiePos) == true) //if it has collided with zombie then increase the health and then delete the sprite after colliding
        {
            delete (*it);
            bloodlist.remove(*it);
            Health += 5;
        }
        else //else just draw the sprite on the screen
            (*it)->draw(gRenderer, assets);
    }
}

void Silentkiller::moveZombie(string direction) //zombie left right movement
{
    zombie.move(direction);
}
// this function will randomly generates the object on screen
void Silentkiller::createObject()
{
    int a = rand() % 9;
    int b = rand() % 1000;
    if (b <= 5)
    {
        
        if (a == 0)
        {
            // Slist.push_back(new Spider(510, 580));
            Slist.push_back(new Spider(rand() % 960, 0));
        }
        else if (a == 1)
        {
            skulllist.push_back(new Skull(rand() % 960, 0));
        }
        else if (a == 2)
        {
            fartlist.push_back(new Fart(rand() % 960, 0));
        }
        else if (a == 3)
        {
            batlist.push_back(new Bat(rand() % 960, 0));
        }
        else if (a == 4)
        {
            wolflist.push_back(new Wolf(rand() % 960, 0));
        }
        else if (a == 5)
        {
            brainlist.push_back(new Brain(rand() % 960, 0));
        }
        else if (a == 6)
        {
            Severedhandlist.push_back(new Severed_hand(rand() % 960, 0));
        }
        else if (a == 7)
        {
            axelist.push_back(new Axe(rand() % 960, 0));
        }
        else if (a == 8)
        {
            heartlist.push_back(new Heart(rand() % 960, 0));
        }
        else if (a == 9)
        {
            bloodlist.push_back(new Blood(rand() % 960, 0));
        }
    }
}
Silentkiller::Silentkiller(SDL_Renderer *renderer, SDL_Texture *asst) : gRenderer(renderer), assets(asst) {}