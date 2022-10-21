#include "minilibx/mlx.h"

int main()
{
	void *p;

	p = mlx_init();
	mlx_new_window(p, 500, 500, "test");
	mlx_loop(p);
	return (0);
}