#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

int	key_esc(int key,void *p)
{
	printf("Key in Win1 : %d\n",key);
	if (key==0xFF1B)
		exit(0);
	return (0);
}

int	key_up(int key,void *p)
{
	printf("Key in Win1 : %d\n",key);
	if (key==0xFF1B)
		exit(0);
	return (0);
}

int	key_down(int key,void *p)
{
	printf("Key in Win1 : %d\n",key);
	if (key==0xFF1B)
		exit(0);
	return (0);
}

int main()
{
	void *m;
	void *w;

	m = mlx_init();
	w = mlx_new_window(m, 250, 250, "test");
	if (m == NULL || w == NULL)
		return (1);

	int *img;
	int xpm1_x;
	int xpm1_y;

	img = mlx_xpm_file_to_image(m, "open.xpm", &xpm1_x, &xpm1_y);
	if (img == NULL)
		return (1);
	mlx_put_image_to_window(m, w, img, 0, 0);
	//destray image
	mlx_destroy_image(m, img);
//	for (int i = 0; i < 100; i++)
//	{
//		for (int j = 0; j < 100; j++)
//		{
//			img = mlx_xpm_file_to_image(m, "open.xpm", &xpm1_x, &xpm1_y);
//			// draw image to windows and move
//			mlx_put_image_to_window(m, w, img, i, j);
//			//clear windows
//			mlx_destroy_image(m, img);
//		}
//		for (int j = 100; j > 0; j--)
//		{
//			img = mlx_xpm_file_to_image(m, "open.xpm", &xpm1_x, &xpm1_y);
//			// draw image to windows and move
//			mlx_put_image_to_window(m, w, img, i, j);
//			//clear windows
//			mlx_destroy_image(m, img);
//		}
//	}
	mlx_key_hook(w,key_esc,0);
	mlx_key_hook(w,key_up,0);
	mlx_key_hook(w,key_down,0);
	mlx_loop(m);


	return (0);
}