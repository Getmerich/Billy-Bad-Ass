#include <iostream>
#include <time.h>

using namespace std;

int turn(int, int, int);

int main()
{
	int elfh = 10, skelh = 10;
	int edmg = 2, sdmg = 1;
	int eroll = 0, sroll = 0, hroll = 0;
	int eacc = 50, sacc = 75;
	int die = 0;
	int i = 0;

	srand(time(0));

	while (elfh > 0 && skelh > 0) {
		cout << "Elf Health: " << elfh << endl << "Skeleton Health: " << skelh << endl;
		eroll = (rand() % 6) + 1;
		sroll = (rand() % 6) + 1;
		cout << "The elf rolled: " << eroll << endl << "The skeleton rolled: " << sroll << endl;

		if (eroll >= sroll) {
			skelh = turn(edmg, eacc, skelh);
			cout << "The Skeleton's health is now: " << skelh << endl << endl;
			if (skelh > 0) {
				elfh = turn(sdmg, sacc, elfh);
				cout << "The Elf's health is now: " << elfh << endl << endl;
			}
		}
		else {
			elfh = turn(sdmg, sacc, elfh);
			cout << "The Elf's health is now: " << elfh << endl << endl;
			if (elfh > 0) {
				skelh = turn(edmg, eacc, skelh);
				cout << "The Skeleton's health is now: " << skelh << endl << endl;
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