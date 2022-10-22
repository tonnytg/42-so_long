#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

void *m;
void *w;

int *img;
int xpm1_x;
int xpm1_y;

int *x;
int *y;


int create_img(int px, int py)
{
	img = mlx_xpm_file_to_image(m, "open.xpm", &xpm1_x, &xpm1_y);
	if (img == NULL)
		return (1);
	mlx_put_image_to_window(m, w, img, px, py);
	return 0;
}

int	keyboard(int key,void *p)
{
	if (key==65307)
		exit(0);
	if (key==65362)
	{
		printf("Key UP\n");
		mlx_destroy_image(m, img);
		y -= 1;
		create_img(x,y);
	}
	if (key==65364)
	{
		mlx_destroy_image(m, img);
		printf("Key DOWN\n");
		y += 1;
		create_img(x,y);
	}
	if (key==65361)
	{
		mlx_destroy_image(m, img);
		printf("Key LEFT\n");
		x -= 1;
		create_img(x,y);
	}
	if (key==65363)
	{
		mlx_destroy_image(m, img);
		printf("Key RIGHT\n");
		x += 1;
		create_img(x,y);
	}
	return (0);
}

int main()
{


	m = mlx_init();
	w = mlx_new_window(m, 250, 250, "test");
	if (m == NULL || w == NULL)
		return (1);

	create_img(0,0);

	mlx_key_hook(w,keyboard,0);
	mlx_loop(m);

	return (0);
}