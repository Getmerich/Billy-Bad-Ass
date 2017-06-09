/* Things to do:
	-create a window to display the characters
	-add 3 races and 5 classes, allow for user to choose race/class
	-have about 10 enemies to fight
	-allow for basic movement */


/*	
	All of the create window shit should be placed in its own file, leaving main as the
	overlay to begin the window as its own class and to use functions on the window that
	involve drawing and pushing to the screen each time X thing happens.
*/	


#include <iostream>
#include <time.h>
#include "Warrior.h"
#include "Skeleton.h"
#include "Ranger.h"
#include <SDL.h>

using namespace std;

const int gameh = 640;
const int gamew = 400;

int turn(int, int, int);

int main()
{
	//initializes the window
	SDL_Window* window = NULL;

	//initializes the 2d image that will be on the screen
	SDL_Surface* screen = NULL;

	//SDL needs to be started, this is the statement to initialize and catch errors
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

	//commenting out the combat portion of the code until needed (maybe should make a class for combat functions
	/*
	Warrior Billy;
	Skeleton Baddie;
	
	int eroll = 0, sroll = 0, hroll = 0;
	int die = 0;
	int i = 0;
	char flag;
	srand(time(0));

	do{
		cout << "Billy's Health: " << Billy.hp << endl << "Skeleton's Health: " << Baddie.hp << endl;
		eroll = (rand() % 6) + 1;
		sroll = (rand() % 6) + 1;
		cout << "Billy rolled: " << eroll << endl << "Baddie rolled: " << sroll << endl;

		if (eroll >= sroll) {
			Baddie.hp = turn(Billy.dmg, Billy.hit, Baddie.hp);
			cout << "The Skeleton's health is now: " << Baddie.hp << endl << endl;
			if (Baddie.hp > 0) {
				Billy.hp = turn(Baddie.dmg, Baddie.hit, Billy.hp);
				cout << "The Elf's health is now: " << Billy.hp << endl << endl;
			}
		}
		else {
			Billy.hp = turn(Baddie.dmg, Baddie.hit, Billy.hp);
			cout << "The Elf's health is now: " << Billy.hp << endl << endl;
			if (Billy.hp > 0) {
				Baddie.hp = turn(Billy.dmg, Billy.hit, Baddie.hp);
				cout << "The Skeleton's health is now: " << Baddie.hp << endl << endl;
			}
		}	

		cout << "Keep fighting?(y/n)    ";
	
		cin >> flag;
	} while (Billy.hp > 0 && Baddie.hp > 0 && (flag == 'y' || flag == 'Y')); */

	cout << "Hope everything went well!!" << endl;

	system("pause");

	return 0;
}

int turn(int dmg, int hit, int health)
{
	int roll = 0;

	roll = rand() % 100;
	if (roll <= hit) {
		health = health - dmg;
		cout << "Hit!" << endl;
	}
	else {
		cout << "Attack missed!" << endl;
	}
	return health;
}