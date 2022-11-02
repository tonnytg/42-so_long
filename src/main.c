#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

void *m;
void *w;

int *img;
int xpm1_x = 5;
int xpm1_y = 5;


int peixe_x = 5;
int peixe_y = 5;
int *peixe;
int peixe_px = 100;
int peixe_py = 100;

int x;
int y;

int create_img(int px, int py)
{
	peixe = mlx_xpm_file_to_image(m, "peixe.xpm", &peixe_x, &peixe_y);
	if (img == NULL)
		return (1);
	mlx_put_image_to_window(m, w, peixe, peixe_px, peixe_py);
	return 0;
}

void load_map() {
	mlx_put_image_to_window(m, w, img, 0, y);
	mlx_put_image_to_window(m, w, img, 50, y);
	mlx_put_image_to_window(m, w, img, 100, y);
	mlx_put_image_to_window(m, w, img, 150, y);
	mlx_put_image_to_window(m, w, img, 200, y);
	mlx_put_image_to_window(m, w, img, 250, y);
	mlx_put_image_to_window(m, w, img, 300, y);
	mlx_put_image_to_window(m, w, img, 350, y);
	mlx_put_image_to_window(m, w, img, 400, y);
	mlx_put_image_to_window(m, w, img, 450, y);
	mlx_put_image_to_window(m, w, img, 500, y);
	mlx_put_image_to_window(m, w, img, 550, y);
	mlx_put_image_to_window(m, w, img, 600, y);

	mlx_put_image_to_window(m, w, img, x, 100);
	mlx_put_image_to_window(m, w, img, x, 200);
	mlx_put_image_to_window(m, w, img, x, 300);
	mlx_put_image_to_window(m, w, img, x, 400);
	mlx_put_image_to_window(m, w, img, x, 500);

	mlx_put_image_to_window(m, w, img, 0, 500);
	mlx_put_image_to_window(m, w, img, 50, 500);
	mlx_put_image_to_window(m, w, img, 100, 500);
	mlx_put_image_to_window(m, w, img, 150, 500);
	mlx_put_image_to_window(m, w, img, 200, 500);
	mlx_put_image_to_window(m, w, img, 250, 500);
	mlx_put_image_to_window(m, w, img, 300, 500);
	mlx_put_image_to_window(m, w, img, 350, 500);
	mlx_put_image_to_window(m, w, img, 400, 500);
	mlx_put_image_to_window(m, w, img, 450, 500);
	mlx_put_image_to_window(m, w, img, 500, 500);
	mlx_put_image_to_window(m, w, img, 550, 500);
	mlx_put_image_to_window(m, w, img, 600, 500);

	mlx_put_image_to_window(m, w, img, 600, 100);
	mlx_put_image_to_window(m, w, img, 600, 200);
	mlx_put_image_to_window(m, w, img, 600, 300);
	mlx_put_image_to_window(m, w, img, 600, 400);
	mlx_put_image_to_window(m, w, img, 600, 500);
}

int	keyboard(int key,void *p)
{
	if (key==65307)
		exit(0);
	// up
	if (key==65362)
	{
		mlx_clear_window(m, w);
		load_map();
		peixe_py-=100;
		create_img(peixe_px, peixe_py);
	}
	// down
	if (key==65364)
	{
		mlx_clear_window(m, w);
		load_map();
		peixe_py+=100;
		create_img(peixe_px, peixe_py);
	}
	// left
	if (key==65361)
	{
		mlx_clear_window(m, w);
		load_map();
		peixe_px-=100;
		create_img(peixe_px, peixe_py);
	}
	// right
	if (key==65363)
	{
		mlx_clear_window(m, w);
		load_map();
		peixe_px+=100;
		create_img(peixe_px, peixe_py);
	}
	printf("key = %d\n",key);
	return (0);
}

int main()
{

	m = mlx_init();
	w = mlx_new_window(m, 650, 600, "test");
	if (m == NULL || w == NULL)
		return (1);

	peixe = mlx_xpm_file_to_image(m, "peixe.xpm", &peixe_x, &peixe_y);
	img = mlx_xpm_file_to_image(m, "open.xpm", &xpm1_x, &xpm1_y);

	load_map();

	mlx_put_image_to_window(m, w, img, 0, y);

	mlx_put_image_to_window(m, w, peixe, 100, 100);


	mlx_key_hook(w,keyboard,0);
	mlx_loop(m);

	return (0);
}