#ifndef GAME_H
#define GAME_H

#include <string>
#include <iostream>
#include <cstdlib> // for random numbers

using namespace std;

class Game{

private:
	// singleton
	static bool started;
	static Game* instance;
	Game(); // private constructor

	// fields
	int player_health;
	int monster_health;
	string winner;
	int current_round;
	bool game_finished;

	// methods
	void attackPlayer(); // privato perchè il pc attacca il player

	// utils
	int getRandomNumber(int, int);
	void printLine();
	
public:
	static Game* getInstance();
	virtual ~Game(); // destructor

	// methods
	void restart();
	void attackMonster();
	void heal();

	// getters
	int getPlayerHealth();
	int getMonsterHealth();
	bool healEnabled(); // ci si può curare ogni 3 turni
	bool gameOver();
	string getWinner();

	// utils
	void printStats();
};

#endif // GAME_H
