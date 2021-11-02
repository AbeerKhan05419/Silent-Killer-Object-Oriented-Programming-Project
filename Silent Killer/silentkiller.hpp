#include <SDL.h>
#include "Zombie.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include "spider.hpp"
#include "Skull.hpp"
#include "fart.hpp"
#include "Bat.hpp"
#include "Wolf.hpp"
#include "Brain.hpp"
#include "SeveredHand.hpp"
#include "Axe.hpp"
#include "Heart.hpp"
#include "Blood.hpp"
#pragma once
using namespace std;

class Silentkiller
{

    SDL_Renderer *gRenderer;
    SDL_Texture *assets;
    Zombie zombie;

public:
    list<Spider *> Slist;
    list<Skull *> skulllist;
    list<Fart *> fartlist;
    list<Bat *> batlist;
    list<Wolf *> wolflist;
    list<Brain *> brainlist;
    list<Severed_hand *> Severedhandlist;
    list<Axe *> axelist;
    list<Heart *> heartlist;
    list<Blood *> bloodlist;
    Silentkiller(SDL_Renderer *, SDL_Texture *); //constructor
    void drawObjects();                          //will draw all the enemy and player objects on screen
    void moveZombie(string direction);           //movie zombie by calling zombie class and its function move
    void createObject();                         //will create an objects of enemy using vector list (just like hw3)
    enum States                                  //will help to detect the current states of game
    {
        RUNNING,
        LOST,
        WON
    };
    // this will increase or decrease the life of player and will effect the states of the game
    int Lifeline = 20;
    int Health = 0;
};
