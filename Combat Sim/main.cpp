#include <iostream>
#include <time.h>
#include "Warrior.h"
#include "Skeleton.h"
#include "Ranger.h"


using namespace std;

int turn(int, int, int);

int main()
{
	Warrior Billy;
	Skeleton Baddie;


	int eroll = 0, sroll = 0, hroll = 0;
	int die = 0;
	int i = 0;

	srand(time(0));

	while (Billy.hp > 0 && Baddie.hp > 0) {
		cout << "Billy's Health: " << Billy.hp << endl << "Skeleton's Health: " << Baddie.hp << endl;
		eroll = (rand() % 6) + 1;
		sroll = (rand() % 6) + 1;
		cout << "Billy rolled: " << eroll << endl << "Baddie rolled: " << sroll << endl;

		if (eroll >= sroll) {
			Baddie.hp = turn(Billy.hp, Billy.hit, Baddie.hp);
			cout << "The Skeleton's health is now: " << Baddie.hp << endl << endl;
			if (Baddie.hp > 0) {
				Billy.hp = turn(Baddie.hp, Baddie.hit, Billy.hp);
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
	}
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