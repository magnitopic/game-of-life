#include "../../include/gol.hpp"
#include "../../include/classes/GameLogic.hpp"
#include "../../MLX42/include/MLX42/MLX42.h"

GameLogic::GameLogic()
{
	this->screen = new Screen();
}

GameLogic::~GameLogic()
{
	delete this->screen;
}

void GameLogic::startGame()
{
	// Draw the initial board
	this->screen->drawBoard();

	// Start the main loop
	mlx_loop(this->screen->getMLX());
}
