#ifndef SCREEN_HPP_
#define SCREEN_HPP_

#include <iostream>
#include "../../MLX42/include/MLX42/MLX42.h"

class Screen
{
private:
	mlx_t *mlx;
	static void keyCallback(mlx_key_data_t keydata, void *param);

public:
	Screen();
	Screen(const Screen &copy);
	Screen &operator=(const Screen &assign);
	~Screen();

	// Getters
	mlx_t *getMLX() const;

	// Draw methods
	void drawBoard();
};

#endif