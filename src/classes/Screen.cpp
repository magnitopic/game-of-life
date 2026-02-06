#include "../../include/gol.hpp"
#include "../../include/classes/Screen.hpp"

Screen::Screen()
{
	mlx_set_setting(MLX_MAXIMIZED, false);
	this->mlx = mlx_init(SCREEN_SIZE, SCREEN_SIZE, "Gomoku", false);
	if (!this->mlx)
	{
		fprintf(stderr, "%s", mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
}

Screen::Screen(const Screen &copy)
{
	*this = copy;
}

Screen &Screen::operator=(const Screen &assign)
{
	if (this != &assign)
	{
		this->mlx = assign.mlx;
	}
	return *this;
}

Screen::~Screen()
{
	if (this->mlx)
		mlx_terminate(this->mlx);
}

/* Getters */

mlx_t *Screen::getMLX() const
{
	return this->mlx;
}

/* Draw methods */

void Screen::drawBoard()
{
	mlx_image_t *img = mlx_new_image(this->mlx, SCREEN_SIZE, SCREEN_SIZE);
	if (!img)
	{
		fprintf(stderr, "Failed to create image\n");
		return;
	}

	for (uint32_t i = 0; i < img->width * img->height; ++i)
		((uint32_t *)img->pixels)[i] = 0xFF000000;

	mlx_image_to_window(this->mlx, img, 0, 0);
}
