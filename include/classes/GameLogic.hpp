#ifndef GAMELOGIC_HPP_
#define GAMELOGIC_HPP_

#include <iostream>
#include "Screen.hpp"

class GameLogic
{
private:
	Screen *screen;

	// Mouse event handling
	static void mouseButtonCallback(mouse_key_t button, action_t action, modifier_key_t mods, void *param);
	// Key event handling
	static void keyPressCallback(mlx_key_data_t keydata, void *param);

public:
	GameLogic();
	GameLogic(const GameLogic &copy);
	GameLogic &operator=(const GameLogic &assign);
	~GameLogic();

	Screen *getScreen() const;

	// Game methods
	void startGame();
};

#endif
