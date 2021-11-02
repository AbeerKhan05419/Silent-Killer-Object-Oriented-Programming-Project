#include "music.hpp"
// the before 2 function will loaf the audio file and will play them
void Music::LoadingMusic(const std::string &musicfile)
{
    bgMusic = Mix_LoadMUS(musicfile.c_str());
    if (bgMusic == NULL)
    {
        printf("Unable to load music: %s \n", Mix_GetError());
    }
}
void Music::LoadingSoundEffect(const std::string &soundfile)
{
    chunk = Mix_LoadWAV(soundfile.c_str());
}
// this function will display the background music for unlimited time/ nonstop
void Music::PlayMusic()
{
    if (Mix_PlayingMusic() == 0)
    {
        Mix_PlayMusic(bgMusic, -1);
    }
}
//this will pause the bg music for the particular time
void Music::PauseMusic()
{
    if (Mix_PlayingMusic())
    {
        Mix_PauseMusic();
    }
}
//this will play the sound effects like for collison of enemy with player or for losing life etc
void Music::PlaySoundEffect()
{
    Mix_PlayChannel(-1, chunk, 0);
}