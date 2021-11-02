#pragma once
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <SDL.h>
#include <string>
//this class is took from the lazyfoo website and from this website
// https://stackoverflow.com/questions/30361423/sdl-mixer-plays-static-instead-of-wav-file
// https://lazyfoo.net/tutorials/SDL/21_sound_effects_and_music/index.php
class Music
{
private:
    Mix_Music *bgMusic = NULL;
    Mix_Chunk *chunk = NULL;

public:
    Music()
    {
        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0)
        {
            printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        }
    }

    // thsi will load the audio file in mp3
    void LoadingMusic(const std::string &musicfile);
    void LoadingSoundEffect(const std::string &soundfile);
    // this is for the game background music
    void PlayMusic();
    void PauseMusic();      //stop/pause the music
    void PlaySoundEffect(); // background effects
    ~Music()
    {
        Mix_FreeChunk(chunk);
        Mix_FreeMusic(bgMusic);
        bgMusic = nullptr;
        chunk = nullptr;
        Mix_Quit();
    }
};