#include "game.h"
#include <string>

using namespace std;

bool Game::started = false;
Game *Game::instance = nullptr;

Game::Game(){
	// inizializzo singleton con inizio partita
	restart();
}

Game* Game::getInstance(){
  // se la partita è già iniziata ritorno l'istanza della partita
	// altrimenti viene create
	if (!started) {
		instance = new Game();
		started = true;
  }

	return instance;
}

Game::~Game(){
	delete(instance);
}

void Game::restart(){
	cout << endl; printLine(); cout << endl;
	cout << "NEW GAME\t| YOU\t| MON\t|" << endl;
	printLine(); cout << endl;
	this->player_health = 100;
	this->monster_health = 100;
	this->current_round = 0;
	this->game_finished = false;
	this->winner = "";
}

int Game::getRandomNumber(int min, int max){
	return (rand() % max) + min;
}

void Game::attackMonster(){
	if (!gameOver()){
		cout << "YOU attack\t| ";
		this->current_round++;
		this->monster_health -= getRandomNumber(5,12); // random (5,12)
		printStats();

		if (this->monster_health<=0){
			this->winner = "player";
			this->game_finished = true;
			cout << "WINNER IS: " << getWinner() << endl;
		} else{
			this->attackPlayer();
		}
	} else{
		cout << "\t    GAME OVER\t\t|" << endl;
		printLine(); cout << endl;
	}
}

void Game::attackPlayer(){
	cout << "MON attack\t| ";
	this->player_health -= getRandomNumber(8,15); // random (8,15)

	printStats();

	if (this->player_health<=0){
		this->winner = "monster";
		this->game_finished = true;
		cout << "\tWINNER IS:  " << getWinner() << "\t|" << endl;
		printLine(); cout << endl;
	}
}

void Game::heal(){
	if (!gameOver()){
		if (healEnabled()){
			cout << "YOU heal\t| ";
			this->current_round++;
            int healt_value = getRandomNumber(10, 20); // random (8,20) more difficult
			if (this->player_health + healt_value > 100){
				this->player_health = 100;
			} else{
				this->player_health += healt_value;
			}

			printStats();
			Game::attackPlayer(); // quando guarisce il giocatore viene subito attaccato
		} else {
			cout << "CAN'T heal\t| ";
			printStats();
		}
	} else{
		cout << "\t    GAME OVER\t\t|" << endl;
		printLine(); cout << endl;
	}
}

int Game::getPlayerHealth(){
	return this->player_health;
}
int Game::getMonsterHealth(){
	return this->monster_health;
}

bool Game::gameOver(){
  return this->game_finished;
}

void Game::printStats(){
	cout << getPlayerHealth() << "\t| " ;
	cout << getMonsterHealth() << "\t|" << endl;
	printLine(); cout << endl;
}

bool Game::healEnabled(){
	return this->current_round % 3 != 0;
}

string Game::getWinner(){
  return this->winner;
}

void Game::printLine(){
	cout << "---------------------------------";
}
