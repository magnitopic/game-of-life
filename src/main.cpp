#include "../include/gol.hpp"
#include "../include/classes/GameLogic.hpp"

int main()
{
	std::cout << "Game of life!" << std::endl;

	GameLogic game;
	game.startGame();

	return (EXIT_SUCCESS);
}
