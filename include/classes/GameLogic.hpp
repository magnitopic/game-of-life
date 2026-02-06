#ifndef GAMELOGIC_HPP_
#define GAMELOGIC_HPP_

#include <iostream>
#include "Screen.hpp"

class GameLogic
{
private:
	Screen *screen;

public:
	GameLogic();
	GameLogic(const GameLogic &copy);
	GameLogic &operator=(const GameLogic &assign);
	~GameLogic();

	// Game methods
	void startGame();
};

#endif
