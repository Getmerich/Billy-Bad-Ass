//something like this???

#include <SDL.h>
#include <iostream>

//eventually we should be able to configure full screen etc.
const int gameh = 640;
const int gamew = 400;

class GameScreen {

public:

	//initializes the window
	SDL_Window* window = NULL;

	//initializes the 2d image that will be on the screen
	SDL_Surface* screen = NULL;


	void openBlank();	//creates a blank white screen

};


void GameScreen::openBlank(void)
{
	//initialize
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL could not start! SDL Error: " << SDL_GetError() << endl;
	}
	else {
		//This should create the window for the game
		window = SDL_CreateWindow("Badass Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, gamew, gameh, SDL_WINDOW_SHOWN);

		//Of course error checking
		if (window == NULL) {
			cout << "Window could not be created! Error: " << SDL_GetError() << endl;
		}
		else {
			//now we create the image to be created to the screen, for now just a color
			screen = SDL_GetWindowSurface(window);
			SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));

			//now push the new image to the screen
			SDL_UpdateWindowSurface(window);

			//add a delay so we can see the window
			SDL_Delay(2000);
		}
	}

	//Close the window
	SDL_DestroyWindow(window);

	//Close SDL
	SDL_Quit();
}