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

GameLogic::GameLogic(const GameLogic &copy)
{
	*this = copy;
}

GameLogic &GameLogic::operator=(const GameLogic &assign)
{
	if (this != &assign)
	{
		this->screen = assign.screen;
	}
	return *this;
}

Screen *GameLogic::getScreen() const
{
	return this->screen;
}

/* Callbacks */
void GameLogic::mouseButtonCallback(mouse_key_t button, action_t action, modifier_key_t mods, void *param)
{
	(void)mods;

	GameLogic *game = static_cast<GameLogic *>(param);
	if (action == MLX_PRESS && button == MLX_MOUSE_BUTTON_LEFT)
	{
		int xpos, ypos;
		mlx_get_mouse_pos(game->screen->getMLX(), &xpos, &ypos);
	}
}

void GameLogic::keyPressCallback(mlx_key_data_t keydata, void *param)
{
	GameLogic *game = static_cast<GameLogic *>(param);

	// Pressing 'ESC' key exits the game
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		std::cout << "Exiting..." << std::endl;
		mlx_close_window(game->screen->getMLX());
	}
}

void render_next_frame(void *param)
{
	GameLogic *game = static_cast<GameLogic *>(param);
	game->getScreen()->drawGrid();
}

void GameLogic::startGame()
{
	// Set up the mouse callback
	mlx_mouse_hook(this->screen->getMLX(), &GameLogic::mouseButtonCallback, this);

	// Set up the key callback for switching players
	mlx_key_hook(this->screen->getMLX(), &GameLogic::keyPressCallback, this);

	// Draw the initial board
	this->screen->drawBoard();

	mlx_loop_hook(this->screen->getMLX(), render_next_frame, this);

	// Start the main loop
	mlx_loop(this->screen->getMLX());
}
