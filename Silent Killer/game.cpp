#include "game.hpp"
#include "silentkiller.hpp"
#include "music.hpp"

bool Game::init()
{
	bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}
		gWindow = SDL_CreateWindow("Silent Killer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}
void Game::writeText(std::string content, int fontSize, int xCo, int yCo, SDL_Color color)
{
	Text text(gRenderer, "font_text.ttf", fontSize, content, color);
	text.display(xCo, yCo, gRenderer);
}
bool Game::loadMedia()
{
	bool success = true;
	assets = loadTexture("assets.png");
	gTexture = loadTexture("menu.png");
	if (gTexture == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}
	return success;
}

void Game::close()
{
	SDL_DestroyTexture(gTexture);
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture *Game::loadTexture(std::string path)
{
	SDL_Texture *newTexture = NULL;
	SDL_Surface *loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
	}
	return newTexture;
}

void Game::run()
{
	bool quit = false;
std:
	string current_screen_state = "Home";
	SDL_Event e;
	Silentkiller s1 = Silentkiller(gRenderer, assets);

	while (!quit)
	{
		bgSound.PlayMusic();
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			if (e.type == SDL_KEYDOWN)
			{
				SDL_Keycode key = e.key.keysym.sym;
				std::string direction = "";
				if (key == SDLK_UP)
					direction = "up";
				else if (key == SDLK_DOWN)
					direction = "down";
				else if (key == SDLK_RIGHT)
					direction = "right";
				else if (key == SDLK_LEFT)
					direction = "left";
				s1.moveZombie(direction);
			}
			if (e.type == SDL_MOUSEBUTTONDOWN && current_screen_state == "Home")
			{
				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse, &yMouse);
				// cout << xMouse << " " << yMouse << endl;
				// if mouse is on PLAY button then display the main game screen
				if (xMouse > 51 && xMouse < 230 && yMouse > 148 && yMouse < 185)
				{
					gTexture = loadTexture("playscreen.jpg");
					current_screen_state = "Play";
				}
				// if mouse is on INSTRUCTION button then display the instruction screen
				if (xMouse > 56 && xMouse < 264 && yMouse > 242 && yMouse < 280)
				{
					gTexture = loadTexture("instructionscreen.png");
					current_screen_state = "Instructions";
				}
				// if mouse is on HIGHSCORE button then display the highscore screen
				if (xMouse > 64 && xMouse < 260 && yMouse > 335 && yMouse < 372)
				{
					gTexture = loadTexture("highscore.png");
					current_screen_state = "Highscore";
				}
				// if mouse is on QUIT button then quit/close the game
				if (xMouse > 65 && xMouse < 262 && yMouse > 424 && yMouse < 472)
				{
					SDL_Quit();
				}
			}
			// this is display the HOME screen if we click on BACK BUTTON
			// if on instuction screen, user click on back button then it will display home screen
			if (e.type == SDL_MOUSEBUTTONDOWN && current_screen_state == "Instructions")
			{
				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse, &yMouse);
				// cout << xMouse << " " << yMouse << endl;
				if (xMouse > 15 && xMouse < 165 && yMouse > 3 && yMouse < 47)
				{
					gTexture = loadTexture("menu.png");
					current_screen_state = "Home";
				}
			}
			// if on highscore screen, user click on back button then it will display home screen
			if (e.type == SDL_MOUSEBUTTONDOWN && current_screen_state == "Highscore")
			{

				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse, &yMouse);
				// cout << xMouse << " " << yMouse << endl;
				if (xMouse > 40 && xMouse < 190 && yMouse > 14 && yMouse < 56)
				{
					gTexture = loadTexture("menu.png");
					current_screen_state = "Home";
				}
			}
			// if on play screen, user click on exit button the game will be end and home screen will be displayed
			if (e.type == SDL_MOUSEBUTTONDOWN && current_screen_state == "Play")
			{

				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse, &yMouse);
				cout << xMouse << " " << yMouse << endl;
				if (xMouse > 19 && xMouse < 85 && yMouse > 35 && yMouse < 128)
				{
					gTexture = loadTexture("menu.png");
					current_screen_state = "Home";
				}
			}
			// play music for unfinite time
			bgSound.LoadingMusic("music.mp3");
		}
		// this will clear all the things from gRenderer
		SDL_RenderClear(gRenderer);
		// this will draw the background images/sprites to the renderer
		SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
		// if the current_screen_state is play then the image will be displayed is playscreen.jpg
		// and it will draw all the objects of the silentkiller class (which is exactly same as HUMania)
		if (current_screen_state == "Play")
		{
			SDL_Delay(6);
			s1.createObject();
			s1.drawObjects();
			writeText("Health", 40, 850, 80, {243, 225, 169});
			writeText(to_string(s1.Health), 30, 870, 115, {0, 0, 0});
			writeText("LifeLine", 40, 850, 10, {243, 225, 169});
			writeText(to_string(s1.Lifeline), 30, 870, 50, {0, 0, 0});
			// if player have life remaining then it will display winningscreen.jpg image and player will win the game
			if (s1.Health >= 100 && s1.Lifeline >= 1)
			{
				gTexture = loadTexture("winningscreen.jpg");
				current_screen_state = "Win";
			}
			// if player have no life remaining then it will display losingscreen.jpg image and player will loss the game
			if (s1.Lifeline <= 0)
			{
				gTexture = loadTexture("losingscreen.jpg");
				current_screen_state = "Lost";
			}
		}
		// updated grenderer is displayed over here
		SDL_RenderPresent(gRenderer);
	}
}