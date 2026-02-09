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

void Screen::drawLine(mlx_image_t *img, int height, int width, int x, int y)
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			mlx_put_pixel(img, x + j, y + i, WHITE);
		}
	}
}

void Screen::drawSquare(mlx_image_t *img, int x, int y, int size, bool filled)
{
	std::cout <<"val:" <<x << ", " << y << std::endl;
	this->drawLine(img, 2, size, x, y);
	this->drawLine(img, size, 2, y, x);
	this->drawLine(img, 2, size, x, y + size - 2);
	this->drawLine(img, size, 2, y + size - 2, x);
	if (filled)
		this->drawLine(img, size - 8, size - 8, x + 4, y + 4);
}

void Screen::drawGrid()
{
	mlx_image_t *img = mlx_new_image(this->mlx, SCREEN_SIZE, SCREEN_SIZE);
	if (!img)
	{
		fprintf(stderr, "Failed to create image\n");
		return;
	}

	int cell_size = (SCREEN_SIZE - 2) / (BOARD_SIZE - 1);
	for (int i = 0; i < BOARD_SIZE - 1; i++)
	{
		for (int j = 0; j < BOARD_SIZE - 1; j++)
		{
			std::cout << "Drawing square at (" << i << ", " << j << ")\n";
			int x = i * cell_size;
			int y = j * cell_size;
			this->drawSquare(img, x, y, cell_size, false);
		}
	}
	/* this->drawSquare(img, 55, 55, 50, true); */

	mlx_image_to_window(this->mlx, img, 0, 0);
}