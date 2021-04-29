#include "game.h"

int main() {
	Game *game = Game::getInstance();
	game = Game::getInstance(); // nothing appen, singleton
	game->attackMonster();
	game->heal();
	game->heal();
	game->heal();
	game->attackMonster();
	game->attackMonster();
	game->attackMonster();
	game->attackMonster();
	game->attackMonster();
	game->attackMonster();
	game->attackMonster();
	game->attackMonster();
	game->attackMonster();
	game->attackMonster();
	game->restart();
	game->attackMonster();
}
